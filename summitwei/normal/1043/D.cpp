#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 100005
#define MAX_M 10
#define fi first
#define se second

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int ppl[MAX_M][MAX_N];
int inv[MAX_M][MAX_N];
int N, M;

int currOn[MAX_M];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    F0R(i, M){
        F0R(j, N){
            int x;
            cin >> x;
            ppl[i][j] = x;
            inv[i][x] = j;
        }
    }

    ll sum = 0;

    int l = 0;
    int r = 0;

    while(l < N){
        //set up r=l case
        int num = ppl[0][l];
        F0R(i, M){
            currOn[i] = inv[i][num];
        }

        while(r < N){
            int works = true;

            int next = ppl[0][r];

            F0R(i, M){
                if(currOn[i] == N || ppl[i][currOn[i]] != next){
                    works = false;
                    break;
                } else{
                    currOn[i]++;
                }
            }

            if(works == false){
                break;
            }

            r++;
        }

        ll len = r-l;
        sum += len*(len+1)/2;
        //cout << "adding " << len*(len+1)/2 << " for l of " << l << "\n";
        l = r;
    }

    cout << sum << "\n";
    
    return 0;
}