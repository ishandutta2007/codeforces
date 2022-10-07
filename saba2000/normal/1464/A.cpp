#include<bits/stdc++.h>
using namespace std;
int ok = 0;
vector<int> v[100009];
int f[100009];
void dfs(int x){
    f[x] = 1;
    if(v[x].size() <= 1) ok = 1;
    for(int y : v[x]){
        if(!f[y]) dfs(y);
    }
}
main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int ans = 0;
        for(int i = 1; i <= m; i++){
            int x,y;
            cin>>x>>y;
            if(x==y) continue;
            v[x].push_back(y);
            v[y].push_back(x);
            ans++;
        }
        for(int i =1 ; i <= n; i++){
            if(f[i] == 0){
                ok = 0;
                dfs(i);
                if(!ok) ans++;

            }
        }
        cout<<ans<<endl;
        for(int i = 1; i <= n; i++)
            f[i] = 0, v[i].clear();
    }
}
//1 2
//2 3
//3 1