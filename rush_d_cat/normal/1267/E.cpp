#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 7;

int a[N][N];
pair<int, int > b[N];
vector<int > vec[N];
bool vis[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int mx = 0, y = -1;
    for (int i = 1; i < n; i++){
        for (int j = 1; j <= m; j++){
            b[j] = {a[j][i] - a[j][n], j};

        }
        sort(b + 1, b + m + 1);
        reverse(b + 1, b + m + 1);
        int k = 0, res = 0;
        for (int j = 1; j <= m; j++){
            res += b[j].first;
            if (res >= 0){
                k = j;
                vec[i].push_back(b[j].second);
            }
            else break;
        }
        if (vec[i].size() > mx){
            mx = vec[i].size();
            y = i;
        }
    }
    printf("%d\n", m - mx);
    if (y != -1){
        for (int v : vec[y]) vis[v] = true;
        for (int i = 1; i <= m; i++) if (!vis[i]) printf("%d ", i);
    } else {
        for (int i = 1; i <= m; i++) printf("%d ", i);
    }
    return 0;
}