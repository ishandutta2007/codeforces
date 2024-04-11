#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001
#define MAX_N 505

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

ll nums[MAX_N];
bool isPow[MAX_N];

map<ll, int> facs;
map<ll, int> sameNums;
ll rest;
int N;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    rest = 1;

    cin >> N;
    F0R(i, N){
        ll x;
        cin >> x;
        nums[i] = x;
        ll rt = (ll)(sqrt(x)+EPSILON);

        if(rt*rt == x){
            isPow[i] = true;

            ll newRt = (ll)(sqrt(rt)+EPSILON);

            if(newRt*newRt == rt){
                facs[newRt] += 4;
                //cout << x << " has 5 factors\n";
            } else{
                facs[rt] += 2;
                //cout << x << " has 3 factors\n";
            }
        } else{
            ll cb = (ll)(cbrt(x)+EPSILON);
            if(cb*cb*cb == x){
                facs[cb] += 3;
                //cout << x << " has 4 factors and is a cbrt\n";
                isPow[i] = true;
            } else{
                //cout << x << " has 4 factors and is a normie\n";
            }
        }
    }

    F0R(i, N){
        if(isPow[i]) continue;

        bool found = false;
        bool foundEq = false;
        bool foundNotEq = false;
        F0R(j, N){
            if(i == j) continue;

            ll gcd = __gcd(nums[i], nums[j]);
            if(gcd != 1){
                found = true;

                if(nums[i] == nums[j]){
                    foundEq = true;
                } else{
                    foundNotEq = true;
                    facs[gcd]++;
                    facs[nums[i]/gcd]++;
                    break;
                }
            }
        }

        if(foundEq && !foundNotEq){
            sameNums[nums[i]]++;
        } else if(!found){
            rest = (rest*4) % MOD;
        }
    }

    for(auto p : sameNums){
        rest = (rest*(p.second+1)) % MOD;
        rest = (rest*(p.second+1)) % MOD;
    }

    for(auto p : facs){
        rest = (rest*(p.second+1)) % MOD;
    }

    cout << rest << "\n";
    cout.flush();

    return 0;
}