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

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int N;
int nums[MAX_N];
int inv[MAX_N];

bool hereWins[MAX_N]; //if the person going to this NUMBER wins

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    F0R(i, N){
        cin >> nums[i];
        inv[nums[i]] = i;
    }

    RFOR(i, N, 1){
        int loc = inv[i];
        for(int j=(loc%i); j<N; j+=i){
            if(j == loc) continue;
            if(!hereWins[nums[j]] && nums[j] > i){
                hereWins[i] = true;
            }
        }
    }

    F0R(i, N){
        if(hereWins[nums[i]]) cout << "A";
        else cout << "B";
    }



    return 0;
}