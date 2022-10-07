#include<bits/stdc++.h>
using namespace std;
int p[200009];
int o[200009];
vector<int> v[200009];
vector<int> V[200009];
int f[200009];
int F[200009];
void dfs(int x){
   // o[x] = 1;
   if(x != 1) o[x] = 1;

    f[x]=1;
    for (int i = 0; i < v[x].size(); i++){
        if(f[v[x][i]]) continue;
        dfs(v[x][i]);
        if(o[v[x][i]]) {

            o[x]^=1;
         //   cout<<x<<" "<<v[x][i]<<endl;
 V[x].push_back(v[x][i]);
        }
        else{
            V[v[x][i]].push_back(x);

        }
    }
  //  cout<<x<<" "<<o[x]<<endl;

}
vector<int> S;
void DFS(int x){
F[x]=1;
for(int i= 0; i < V[x].size(); i++)
if(!F[V[x][i]]) DFS(V[x][i]);
S.push_back(x);

}


main(){
    int n;
    cin >> n;
    for (int i= 1; i <= n; i++){
        cin >> p[i];
        if(!p[i]) continue;
        v[i].push_back(p[i]);
        v[p[i]].push_back(i);
    }
    dfs(1);
    if(o[1]){
        cout<<"NO"<<endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        if(F[i]==0) DFS(i);
    reverse(S.begin(),S.end());
    cout<<"YES"<<endl;
    for (int i= 0; i < S.size(); i++)
        cout<<S[i]<<endl;
    cout<<endl;

}