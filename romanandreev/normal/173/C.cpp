#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())
#define y0 y0_fedswjfwe
#define pb push_back
#define mp make_pair
#define debug(...) fprintf(stderr, __VA_ARGS__)
int n, m;
int s[510][510];
int a[510][510];
int dp[2][510][510];
int main () {
    #ifdef home
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i + 1][j + 1]);
            s[i + 1][j + 1] = s[i + 1][j] + a[i + 1][j + 1] + s[i][j + 1] - s[i][j];
        }
    }
    int f0 = 0;
    int ans = -10000000;
//    cerr<<sum1(1, 0, 4)<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[0][i][j] = a[i + 1][j + 1];
        }
    }
    for (int k = 3; k <= min(n, m); k += 2) {
        int f1 = 1 - f0;
        for (int i = 0; i < n - k + 1; i++) {
            for (int j = 0; j < m - k + 1; j++) {
                dp[f1][i][j] = s[i + k][j + k] - s[i + k][j] - s[i][j + k] + s[i][j] - dp[f0][i + 1][j + 1] - a[i + 2][j + 1]; 
//                cerr<<k<<" "<<i<<" "<<j<<" "<<dp[f1][i][j]<<endl;
                ans = max(ans, dp[f1][i][j]);
            }   
        }
        f0 = f1;
    }
    cout<<ans<<endl;
    return 0;
}