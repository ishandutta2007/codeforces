#include<bits/stdc++.h>
using namespace std;
const int maxn = 200009;
int p[maxn];
int sz[maxn];
int f[maxn];
vector<int> v[maxn];
void dfs(int x){
    if(!v[x].size()) sz[x]= 1;
    for(int y : v[x])
        dfs(y), sz[x] += sz[y];
    f[sz[x]] ++;

}
main(){
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        cin >> p[i];
        v[p[i]].push_back(i);
    }
    dfs(1);
    for(int i =1; i <=n; i++)
        f[i] += f[i-1];
    int x = 1;
    for(int i =1;i <= n; i++){
        while(f[x] < i) x++;
        cout<<x<<" ";

    }
    cout<<endl;
}