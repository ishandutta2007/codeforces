#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000009
#define EPSILON 0.00001
#define MAX_N 505
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int N;
int c[MAX_N];

int dp[MAX_N][MAX_N];

int calcDP(int l, int r){
    if(l > r) return 1;
    if(dp[l][r] != 0) return dp[l][r];

    int curMin = 1+calcDP(l+1, r);
    if(c[l] == c[r]) curMin = min(curMin, calcDP(l+1, r-1));
    
    FOR(i, l+1, r-1){
        if(c[l] == c[i]){
            curMin = min(curMin, calcDP(l+1, i-1) + calcDP(i+1, r));
        }
    }

    dp[l][r] = curMin;
    return curMin;
}

int main(){
    cin >> N;
    F0R(i, N){
        cin >> c[i];
        dp[i][i] = 1;
        if(i > 0 && c[i] == c[i-1]){
            dp[i-1][i] = 1;
        }
    }

    cout << calcDP(0, N-1) << "\n";
    return 0;
}