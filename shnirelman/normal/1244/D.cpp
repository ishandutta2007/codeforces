#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int m = 3;

vector<vector<long long>> c;
vector<vector<int>> a;
vector<vector<vector<long long>>> dp;

//         

int other(int x, int y) {
    return 3 - x - y;
}

/*void dfs(int v, int p) {
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            dp[v][j][i] = c[v][i];
                
    if(a[v].size() == 1 && p != -1) {
        return;
    }
    
    for(auto u : a[v]) 
        if(u != p){
            dfs(u, v);
            for(int i = 0; i < m; i++)  
                for(int j = 0; j < m; j++)
                    if(i != j)
                        dp[v][i][j] += dp[u][other(i, j)][j];
        }
        
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            cout << v << ' ' << i << ' ' << j << ' ' << dp[v][i][j] << endl;
    
}*/

vector<int> col;

long long dfs1(int v, int p, int cl1, int cl2) {
    col[v] = cl1;
    
    long long cur = c[v][cl1];
    for(auto u : a[v])
        if(u != p) 
            cur += dfs1(u, v, cl2, other(cl1, cl2));
            
    return cur;
}

int main() {
    int n;
    cin >> n;
    
    a.resize(n);
    c.resize(n, vector<long long>(m));
    dp.resize(n, vector<vector<long long>>(m, vector<long long>(m, INF)));
    
    for(int j = 0; j < m; j++)
        for(int i = 0; i < n; i++)
            cin >> c[i][j];
            
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        
        v--;
        u--;
        
        a[v].push_back(u);
        a[u].push_back(v);
    }
    
    int root = -1;
    
    for(int i = 0; i < n; i++)
        if(a[i].size() >= 3) {
            cout << -1;
            return 0;
        } else if(a[i].size() == 1)
            root = i;
    
    //dfs(0, -1);
    
    /*long long ans = INF;
    int bi = 0, bj = 1;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            if(i != j) {
                if(ans > dp[0][i][j]) {
                    ans = dp[0][i][j];
                    bi = i;
                    bj = j;
                }
            }*/
    
    col.resize(n, -1);
    
    int cl1, cl2;
    long long ans = INF;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++) 
            if(i != j) {
                long long res = dfs1(root, -1, i, j);
                if(res < ans) {
                    ans = res;
                    cl1 = i;
                    cl2 = j;
                }
            }
    
    dfs1(root, -1, cl1, cl2);  
    
    cout << ans << endl;
    for(auto cl : col)  
        cout << cl + 1 << ' ';
}