#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)/2)
using namespace std;
int n, m;
int d[609][609];
int L[609][609], Y[609];
int f[609][609];
int ok[609][609];
int inf = 1e9+1;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            d[i][j] = inf;
            if(i == j) d[i][j] = 0;
        }
    }
    for(int i = 1; i <= m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
    }
    for(int i = 1; i <= n; i++){
        for(int  j = 1; j <= n; j++){
            f[i][j] = d[i][j];
        }
    }
    for(int i= 1; i <= n; i++){
        for(int j  =1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                f[j][k] = min(f[j][k], f[j][i] + f[i][k]);
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int u, v, l;
        cin>>u>>v>>l;
        L[u][v] =l;
        L[v][u] = l;
    }
    for(int i =1; i <= n; i++){
        for(int b = 1; b <= n; b++){
            Y[b] = -1;
            for(int a = 1; a <= n; a++){
                Y[b] = max(Y[b], L[a][b] - f[i][a]);
            }
        }
        for(int j = 1; j <= n; j++){
            for(int b = 1; b <= n; b++){
                if(d[i][j] + f[j][b] <= Y[b]){
                    ok[i][j] = 1;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(d[i][j] == inf) continue;
            if(ok[i][j] || ok[j][i]) ans++;
        }
    }

    cout<<ans<<endl;
}
/*
a,b

*/