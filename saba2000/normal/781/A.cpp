#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c[200009];
vector<int> v[200009];
int g[200009];
int f[200009];
void dfs(int x, int y, int z){
    int t = 0;
    for(int u : v[x]){
        if(c[u]) continue;
        t++;
        while(t==y || t==z) t++;
        c[u] =t;
        dfs(u,t,y);
    }
}
main(){
    int n;
    cin >> n;
    int ans=  1;
    for(int i = 1; i <= n -1; i++){
        int a,b;
        cin>>a>>b;
        if(a >b) swap(a,b);
        v[b].push_back(a);
        v[a].push_back(b);
        f[a]++; f[b]++;
        ans = max(ans, 1+max(f[a],f[b]));
    }
    c[1] = 1;
    dfs(1,1,-1);
    cout<<ans<<endl;
    for(int i =1; i<= n; i++)
        cout<<c[i]<<" ";
}