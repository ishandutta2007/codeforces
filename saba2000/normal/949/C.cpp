#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
vector<int> S;
int f[1000009],g[1000009];
vector<int> C[1000009];
vector<int > v[100009];
int H[100009];
vector<int> k[100009];
int cc[100009];
void dfs(int x){
    f[x] =1;
    for (int i = 0; i <v[x].size(); i++)
        if(f[v[x][i]]==0) dfs(v[x][i]);
    S.push_back(x);
}
void dfs1(int x, int N){
    g[x]=1;
    cc[x] = N;
    C[N].push_back(x);
    for (int i=0; i<k[x].size(); i++)
    if(g[k[x][i]]==0) dfs1(k[x][i],N);
}
int u[100009];
main(){
    int n,m,h;
    cin >> n >> m >> h;
    for (int i =1 ; i <= n; i++){
        cin >> u[i] ;
    }
    for (int i= 0; i < m ; i++){
        int a,b;
        cin >>a >> b;
        if((u[a]+1)%h == u[b]) {v[a].push_back(b);k[b].push_back(a);}
        if((u[b]+1)%h == u[a]) {v[b].push_back(a); k[a].push_back(b);}
    }
    for (int i= 1; i <= n; i++){
        if(f[i] == 0) dfs(i);
    }
    int cnt=  0;
    while(S.size()){
        int x = S.back();
        S.pop_back();
      //  cout <<x << endl;
        if(g[x]) continue;
        dfs1(x,cnt);
        cnt++;
    }
    for (int i = 1; i <= n; i++){
         //   cout << i <<" "<<cc[i] << endl;
        for (int j =0; j <v[i].size(); j++)
            if(cc[v[i][j]]!=cc[i])H[cc[i]] = 1;
    }
    int ans=1e9,I;
    for (int i =0; i < cnt; i++)
        if(H[i]==0){
            if(C[i].size()< ans)
                ans=C[i].size(), I = i;
        }
    cout << ans << endl;
    for (int i=0 ; i <ans; i++)
        cout <<C[I][i]<<" ";
    cout << endl;
}
/*
1.2.3.4.5  .6.7.8.9
5768

9
*/