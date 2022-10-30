#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef long double ld;
#define INF 1000000000LL
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 2005
int n;
int a[MN];
int dp[MN][4];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        if(a[i] == 1){
            dp[i][0] = dp[i-1][0]+1;
            dp[i][1] = dp[i-1][1];
            dp[i][2] = max(dp[i-1][2]+1, dp[i-1][1]+1);
            dp[i][3] = dp[i-1][3];
        } else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][0]+1, dp[i-1][1]+1);
            dp[i][2] = dp[i-1][2];
            dp[i][3] = max(dp[i-1][2]+1, dp[i-1][3]+1);
        }
    }
    cout << max(max(dp[n][0], dp[n][1]), max(dp[n][2], dp[n][3])) << "\n";

    return 0;
}