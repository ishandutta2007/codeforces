#include<bits/stdc++.h>
using namespace std;
int d[2][1000000];
#define ll long long
vector<int> adj[1000000];
int n,m,k;
int mx[1000000][2];
int id[1000000][2];
void bfs(int v, int o){
    for (int i=1;i<=n;i++)
        d[o][i]=1e9;
    d[o][v]=0;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        v = q.front();
        q.pop();
        for (auto u:adj[v])
        {
            if (d[o][u]<1e7)continue;
            d[o][u]=d[o][v]+1;
            q.push(u);
        }
    }
}
int a[1000000];

vector<pair<int,int> > vec;
bool check(int x){
    for (int i=0;i<vec.size();i++){
        int A = x - vec[i].second - 1;
        int B = x - vec[i].first - 1;
        A=max(A,0);
        B=max(B,0);
        if (i==id[A][0] && mx[A][1]>=B)return 1;
        else if (i!=id[A][0] && mx[A][0]>=B)return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    int s=1,t=n;
    for (int i=1;i<=k;i++){
        cin>>a[i];
    }
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(s,0);
    bfs(t,1);
    for (int i=0;i<=n+1;i++)mx[i][0]=-1e9,mx[i][1]=-1e9;
    for (int j=1;j<=k;j++){
        int i = a[j];
        vec.emplace_back(d[0][i],d[1][i]);
        int Id, val;
        Id = d[0][i];
        val = d[1][i];
        if (val>mx[Id][0]){
            swap(mx[Id][0],mx[Id][1]);
            swap(id[Id][0],id[Id][1]);
            mx[Id][0] = val;
            id[Id][0] = j-1;
        }
    }
    for (int i=n;i>=0;i--){
        pair<int,int> b[] = {{mx[i][0], id[i][0]}, {mx[i][1], id[i][1]}, {mx[i+1][0], id[i+1][0]}, {mx[i+1][1], id[i+1][1]}};
        sort(b,b+4);
        reverse(b,b+4);
        mx[i][0] = b[0].first, id[i][0]=b[0].second;
        mx[i][1] = b[1].first, id[i][1]=b[1].second;
    }
    int dist = d[0][n];
    int ret = 0;
    int l=0,r=dist;
    while(l<=r){
        int mid=  (l+r)/2;
        if (check(mid))ret=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ret<<endl;
}