#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <stack>
#include <list>
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
void solve();

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    clock_t start = clock();
#else
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

#ifdef DEBUG
    cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
    return 0;
}

int t[101010];

string s;
int dp[5050][5050];
int mn[5050][5050];
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> t[i] >> s;
    }
    
    for(int i = 1; i <= m; ++i)
        dp[0][i] = 0;
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            dp[i][j] = dp[i - 1][j] + 1;
            if(t[i] <= j){
                dp[i][j] = min(dp[i][j], dp[i - 1][t[i]]);
            }
            //cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    
    cout << dp[n][m];
}