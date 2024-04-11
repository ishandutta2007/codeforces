#include<bits/stdc++.h>
#define ll long long
using namespace std;
int h[100009], p[100009],f[100009];
vector<int> v[100009];
void dfs(int x, int y){
    p[x] = y;
    h[x] = h[y] + 1;
    for(int z : v[x]){
        if(z == y) continue;
        dfs(z, x);
    }
}
main(){
    int n;
    cin >> n;
    if(n == 2){
        cout << 1 <<" "<<1<<endl;
        return 0;
    }
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int r = 0;
    for(int i = 1; i <= n; i++){
        if(v[i].size() > 1) r = i;
    }
    dfs(r, 0);
    int o = 0, e = 0, ans = n - 1;
    for(int i = 1; i <= n; i++){
        if(v[i].size() > 1) continue;
        if(h[i] % 2 == 0) e = 1; else o = 1;
        if(f[p[i]]) ans --;
        f[p[i]] = 1;
    }
    if(o && e){
        cout << 3 <<" ";
    }
    else cout << 1 <<" ";
    cout<<ans<<endl;

}