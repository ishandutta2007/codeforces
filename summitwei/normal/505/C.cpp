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
#define MAX_N 30005
#define DIST 600

#define FOR(i, a, b) for(int i=a; i<b; i++)
#define F0R(i, a) for(int i=0; i<a; i++)

int has[MAX_N];
int dp[MAX_N][DIST]; //start at 300

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;
    F0R(i, n){
        int x;
        cin >> x;
        has[x]++;
    }

    dp[d][300] = MAX_N;
    if(has[d]) dp[d][300]+=has[d];

    //cout << "hi\n";

    int ans = dp[d][300];
    FOR(i, d+1, MAX_N){
        FOR(j, 1, DIST-1){
            //cout << "doing " << i << " " << j << "\n";
            int jump = d+j-300;
            if(i-jump >= 0 && jump > 0){
                dp[i][j] = max(dp[i-jump][j-1], max(dp[i-jump][j], dp[i-jump][j+1]));
            }
            if(has[i]) dp[i][j]+=has[i];

            ans = max(ans, dp[i][j]);
            /*if(dp[i][j] >= MAX_N){
                cout << "max in " << i << " " << j << " is " << dp[i][j] << "\n";
            }*/
        }
    }

    cout << ans-MAX_N << "\n";
    return 0;
}