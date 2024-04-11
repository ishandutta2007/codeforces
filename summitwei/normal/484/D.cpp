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
#define MAX_N 1000005

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)

int N;
int c[MAX_N];
ll dp[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    F0R(i, N){
        cin >> c[i+1];
    }

    ll maxPlus = c[1];
    ll maxMin = -1*c[1];
    FOR(i, 1, N+1){
        maxPlus = max(maxPlus, dp[i-1]+c[i]);
        maxMin = max(maxMin, dp[i-1]-c[i]);
        dp[i] = max(maxPlus-c[i], maxMin+c[i]);
        //cout << dp[i] << " ";
    }

    //cout << "\n";
    cout << dp[N] << "\n";

    return 0;
}