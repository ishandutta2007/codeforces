#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+9;
vector<int> v[N],w[N],scc[N];
int f[N], g[N], Sc[N];
stack<int> S;
void dfs(int x){
    f[x] = 1;
    for(int y : v[x]){
        if(!f[y]) dfs(y);
    }
    S.push(x);
}
int c= 0;
void ufs(int x){
    g[x] = 1;
    scc[c].push_back(x);
    Sc[x] = c;
    for(int y : w[x])
        if(!g[y]) ufs(y);
}
void solve(){
    c= 0;
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i =1 ; i <= m; i++){
        int a, b;
        scanf("%d %d",&a, &b);
        v[a].push_back(b+n);
        w[b+n].push_back(a);
    }
    for(int i = 1; i <= n; i++)
        v[i+n].push_back(i),
        w[i].push_back(i+n);
    for(int i = 1; i <= 2*n; i++){
         if(f[i] == 0) dfs(i);
    }
    while(S.size()){
        int x = S.top();
        S.pop();
        if(g[x]) continue;
        c++;
        ufs(x);
    }
    for(int i = 1; i <= c; i++){
        int fl = 1,a=0,b=0;
        for(int j : scc[i]){
            if(j <= n) a++;
            else b++;
            for(int x : v[j])
                if(Sc[x] != i) fl = 0;
        }
        if(!fl || a != b || scc[i].size() == 2*n || scc[i].size()==0) continue;
        cout<<"Yes\n";
        printf("%d %d\n",scc[i].size()/2,n - scc[i].size()/2);
        for(int j = 1; j <= n; j++)
            if(Sc[j] == i) printf("%d ", j);
        cout<<endl;
        for(int j = 1; j <= n; j++)
            if(Sc[j+n] != i) printf("%d ", j);
        cout<<endl;

    for(int i = 1; i <= 2*n; i++)
        v[i].clear(), w[i].clear(), scc[i].clear(),f[i] =0,g[i] = 0,Sc[i] =0;
        return;
    }
    cout<<"No"<<endl;
    for(int i = 1; i <= 2*n; i++)
        v[i].clear(), w[i].clear(), scc[i].clear(),f[i] =0,g[i] = 0,Sc[i] =0;
}
main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }

}
/*

[       ]x
*/