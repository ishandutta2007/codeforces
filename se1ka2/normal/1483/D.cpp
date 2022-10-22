#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000000;

ll w[606][606];
ll l[606][606];
ll d[606][606];
bool b[606][606];

void warshallfloyd(int n){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j) d[i][j] = w[i][j] = INF;
        }
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        cin >> w[u][v];
        w[v][u] = d[u][v] = d[v][u] = w[u][v];
    }
    warshallfloyd(n);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        cin >> l[u][v];
        l[v][u] = l[u][v];
    }
    for(int r = 0; r < n; r++){
        ll e[606];
        for(int i = 0; i < n; i++) e[i] = -INF;
        for(int u = 0; u < n; u++){
            for(int s = 0; s < n; s++){
                e[u] = max(e[u], l[r][s] - d[u][s]);
            }
        }
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                if(u == v) continue;
                if(d[r][u] + w[u][v] <= e[v]) b[u][v] = true;
            }
        }
    }
    int ans = 0;
    for(int u = 0; u < n; u++){
        for(int v = 0; v < n; v++) ans += b[u][v];
    }
    cout << ans / 2 << endl;
}