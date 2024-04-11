#include<bits/stdc++.h>
#include<bits/extc++.h>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
 
vector<map<int,int>> pat;
vector<int> offset;
vector<vector<int>> gr;
int k;
ll ans = 0;
 
void mer(int u, int v){
    offset[v]++;
    if(pat[u].size() < pat[v].size()){
        swap(pat[u],pat[v]);
        swap(offset[u],offset[v]);
    }
    for(auto x : pat[v]){
		ans+=x.second*pat[u][k-(x.first+offset[u]+offset[v])];
    }
    for(auto x : pat[v])
        pat[u][x.first+offset[v]-offset[u]]+=x.second;
}
 
void dfs(int x = 0, int p = 0){
    for(int i : gr[x]){
        if(i == p)continue;
        dfs(i,x);
        mer(x,i);
    }
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n >> k;
    gr.resize(n);
    offset.resize(n,0);
    pat.resize(n);
    for(int i = 0; i < n; ++i)
        pat[i][0]++;
    for(int i = 0, a, b; i < n-1; ++i){
        cin >> a >> b, a--, b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs();
    cout << ans << '\n';
}