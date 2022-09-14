#include<bits/stdc++.h>

using namespace std;

vector<vector<int>>ps(101, vector<int>(101, 0));

int get(int x1, int y1, int x2, int y2){
    return ps[x2][y2] - ps[x2][y1 - 1] - ps[x1 - 1][y2] + ps[x1 - 1][y1 - 1];
}

int main() {
   int n, m;
   cin >> n >> m;
   vector<string> a(n);
   for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < m; j++){
            ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + (a[i][j] == 'B');
        }
   }
   int ans = 1e9;
   for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 1; i + k <= n && j + k <= m; k++){
                int c = get(i + 1, j + 1, i + k, j + k);
                if(c == ps[n][m]){
                    ans = min(ans, k * k - c);
                }
            }
        }
   }
   if(ans > 1e8) cout << -1;
   else cout << ans;
}