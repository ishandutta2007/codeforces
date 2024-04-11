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
#define int li
int s[55];
int n,p;

double cc(int x, int k){
    int n = x + k;
    //cerr << n << ' ' << k << endl;
    double res = 1;
    for(int i = 1; i<= k; ++i){
        res *= n - k + i;
        res /= i;
    }
    return res;
}
double solve(int c){
    int dp[51][51];
    memset(dp, 0, sizeof dp);
    
    dp[0][0] = 1;
    

    for(int j = 0; j < n; ++j){
        if(c != j){
            for(int k = n - 1; k >= 0; --k){
                for(int i = p; i>=0; --i){
                    if(i + s[j] <= p)
                        dp[k + 1][i + s[j]] += dp[k][i];
                }
            }
        }
    }

    double sum = 0;
    for(int t = 0; t < n; ++t){
        double z = 1 / cc(t, n - 1 - t);
        for(int i = 0; i <= p - s[c]; ++i){
            if(!dp[t][i])
                continue;
            sum += z * dp[t][i];
            
        //  cerr << t <<' '<< i << ' '<< z << ' '<<dp[t][i] <<  endl;
        }
    }
    return sum / n;
}

void solve() {
    cin >> n;
    
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    
    cin >> p;
    double ans = 0;
    for(int i = 0; i < n; ++i){
        
        //cout << solve(i) << endl;
        ans += solve(i);
    }
    
    printf("%.15lf", ans);
}