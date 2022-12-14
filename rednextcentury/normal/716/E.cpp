#include <bits/stdc++.h>
using namespace std;
int M;
long long mul_inv(long long a)
{
    long long b = M;
	long long b0 = b, t, q;
	long long x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
long long P[1000000];
long long iP[1000000];
int sz[1000000];
bool done[1000000];
vector<pair<int,int> > adj[1000000];
void pre(int v,int p)
{
    sz[v]=1;
    for (auto u:adj[v]){
        if (done[u.first] || u.first==p)continue;
        pre(u.first,v);
        sz[v]+=sz[u.first];
    }
}
int tot;
int best,node;
void get_centroid(int v,int p)
{
    int mx = tot-sz[v];
    for (auto u:adj[v]){
        if (done[u.first] || u.first==p)continue;
        get_centroid(u.first,v);
        mx=max(mx,sz[u.first]);
    }
    if (mx<best)best=mx,node=v;
}
int a[1000000];
map<int,int> mp;
vector<int> val;
long long ret=0;
int cur;
void process(int v,int p,int dep) {
    cur=(cur + (a[v]*P[dep])%M    )%M;
    //if (cur==0)ret++;
    val.push_back(cur);
    for (auto u:adj[v]) {
        if (done[u.first] || u.first==p)continue;
        a[u.first]=u.second;
        process(u.first,v,dep+1);
    }
    cur=(cur - (a[v]*P[dep])%M + M)%M;
}
int len;
void dfs(int v,int p,int cur) {
    len++;
    int y = (M - (cur*iP[len])%M)%M;
    ret+=mp[y];
    for (auto u:adj[v]) {
        if (u.first==p || done[u.first])continue;
        long long newCur = (cur*10LL + u.second)%M;
        dfs(u.first,v,newCur);
    }
    len--;
}
void centroid(int v=1)
{
    mp.clear();
    mp[0]=1;
    best=1e9,node=-1;
    pre(v,0);
    tot=sz[v];
    get_centroid(v,0);
    v=node;
    done[v]=1;
    for (auto u:adj[v]) {
        if (!done[u.first]){
            a[u.first]=u.second;
            process(u.first,0,0);
            for (auto x:val)mp[x]++;
            val.clear();
        }
    }
    for (auto u:adj[v]) {
        if (!done[u.first]){
            process(u.first,0,0);
            for (auto x:val)mp[x]--;
            dfs(u.first,0,u.second);
            for (auto x:val)mp[x]++;
            val.clear();
        }
    }
    ret+=mp[0]-1;
    for (auto u:adj[v]) {
        if (!done[u.first])centroid(u.first);
    }
}
int main()
{
    int n;
    scanf("%d%d",&n,&M);
    P[0]=1,iP[0]=1;
    long long inv = mul_inv(10);
    for (int i=1;i<=n;i++) {
        P[i]=(P[i-1]*10)%M;
        iP[i]=(iP[i-1]*inv)%M;
    }
    for (int i=1;i<n;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        u++,v++;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    centroid();
    cout<<ret<<endl;
}