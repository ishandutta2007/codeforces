#include<bits/stdc++.h>
using namespace std;
int f[200009];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
 //   cin >>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            f[i] = 0;
        int cnt = 0;
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            if(u > v) swap(u, v);
            f[u]++; if(f[u] == 1) cnt++;
        }
        int q;
        cin >> q;
        while(q--){
            int t, u, v;
            cin >> t;
            if(t == 3){
                cout << n - cnt << endl;
                continue;
            }
            int d = 1;
            if(t == 2) d = -1;
            cin >> u >> v;
            if(u > v) swap(u, v);
            if(f[u] == 0) cnt++;
            f[u] += d;
            if(f[u] == 0) cnt--;

        }

    }

}