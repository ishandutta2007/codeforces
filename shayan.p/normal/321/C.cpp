// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn];
bool mark[maxn];
int ans[maxn],SZ[maxn];

void dfsS(int u,int par=-1){
    SZ[u]=1;
    for(int y:v[u]){
	if(y!=par && !mark[y])
	    dfsS(y,u),SZ[u]+=SZ[y];
    }
}

int dfsC(int u,int ss,int par=-1){
    for(int y:v[u]){
	if(y!=par && !mark[y] && ss<SZ[y])
	    return dfsC(y,ss,u);
    }
    return u;
}

void solve(int u,int x){
    dfsS(u);
    u=dfsC(u,SZ[u]/2);
    ans[u]=x;
    mark[u]=1;
    for(int y:v[u])
	if(!mark[y])
	    solve(y,x+1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n;cin>>n;
    for(int i=0;i<n-1;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    solve(1,0);
    for(int i=1;i<=n;i++)
	cout<<char(ans[i]+'A')<<" ";
    cout<<endl;
    return 0;
}