#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N2 = 100 + 3;
const int N = 100;
const int INF = 1e9;
const int ADD = 2 * N * N;

int n;
int a[N2], b[N2];
int dp[2][N2][4 * N2 * N2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
    }

    for(int i = n; i >= n; --i){
        bool curr = (i & 1);
        bool nxt = ((i + 1) & 1);
        for(int j = 0; j <= n - i; ++j){
            for(int diff = -ADD; diff <= ADD; ++diff){
                auto &ans = dp[curr][j][diff + ADD];
                ans = 0;
            }
        }

        int j = n - i + 1;
        for(int diff = -ADD; diff <= ADD; ++diff){
            int &ans = dp[curr][j][diff + ADD];
            ans = -INF;
        }
    }

    for(int i = n - 1; i >= 0; --i){
        bool curr = (i & 1);
        bool nxt = ((i + 1) & 1);
        for(int j = 0; j <= n - i; ++j){
            for(int diff = -ADD; diff <= ADD; ++diff){
                int &ans = dp[curr][j][diff + ADD];
                ans = dp[nxt][j][diff + ADD];
                
                if(j){
                    int s1 = min(diff, 0);
                    int s2 = min(diff + b[i], 2 * a[i]);
                    ans = max(ans, dp[nxt][j - 1][diff + ADD + b[i] - 2 * a[i]] + s2 - s1);
                }
            }
        }

        int j = n - i + 1;
        for(int diff = -ADD; diff <= ADD; ++diff){
            auto &ans = dp[curr][j][diff + ADD];
            ans = -INF;
        }
    }

    int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += b[i];

    for(int j = 1; j <= n; ++j){
        cout << fixed << setprecision(12) <<  (long double)dp[0][j][sum + ADD] / (long double)2.0 << " ";
    }
    cout << "\n";
}