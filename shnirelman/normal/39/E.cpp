#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e5 + 13;
const int INF = 1e9;
const int MAXA = 10011;
const int MAXB = 32;


/*
0 - ?
1 - win
2 - draw
3 - lost
*/
int dp[MAXA][MAXB];
vector<pii> g[MAXA][MAXB];

void dfs(int a, int b) {
    if(dp[a][b] != 0)
        return;
        
    int mx = 1;
    for(auto p : g[a][b]) {
        dfs(p.f, p.s);
        
        mx = max(mx, dp[p.f][p.s]);
    }
    
    dp[a][b] = 4 - mx;
    //cout << a << ' ' << b << ' ' << dp[a][b] << endl;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    
    int a, b, n;
    cin >> a >> b >> n;
    
    dp[1][MAXB - 1] = 2;
    dp[MAXA - 1][1] = ((n - MAXA) % 2 != 0 ? 1 : 3);
    
    for(int i = 0; i < MAXA; i++) {
        for(int j = 0; j < MAXB; j++) {
            //dp[i][j] = 0;
            li pw = 1;
            for(int l = 0; l < j; l++) {
                pw *= i;
                if(pw >= n) {
                    dp[i][j] = 1;
                    break;
                }
            }
            
            if(i < MAXA - 1) {
                g[i][j].emplace_back(i + 1, j);
            }
            
            if(j < MAXB - 1) {
                g[i][j].emplace_back(i, j + 1);
            }
        }
    }
    
   //cout << dp[1][31] << endl;
    
    dfs(a, b);
    
    if(dp[a][b] == 3)
        cout << "Stas";
    else if(dp[a][b] == 1)
        cout << "Masha";
    else
        cout << "Missing";
}