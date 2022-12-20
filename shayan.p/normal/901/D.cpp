// Wanna Hack? GL...

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

vector<pii>v[maxn];
int A[maxn],B[maxn],h[maxn],ID=-1;
ll Ans[maxn],c[maxn];
bool mark[maxn];

ll dfs(int u,int parid=-1){
    mark[u]=1;
    ll num=c[u];
    for(pii p:v[u]){
	if(!mark[p.F]){
	    h[p.F]=h[u]+1;
	    num-=dfs(p.F,p.S);
	}
	else if(mark[p.F] && h[p.F]<h[u] && (h[u]&1)==(h[p.F]&1)){
	    ID=p.S;
	}
    }
    if(parid!=-1) Ans[parid]=-num;
    return num;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
	cin>>c[i];
	c[i]*=-1;
    }
    for(int i=0;i<m;i++){
	cin>>A[i]>>B[i];
	v[A[i]].PB({B[i],i});
	v[B[i]].PB({A[i],i});
    }
    ll num=dfs(1);
    if(num!=0 && ID==-1) return cout<<"NO\n",0;
    if(num!=0){
	if(h[A[ID]]&1) num*=-1;
	Ans[ID]=-(num/2);
	c[A[ID]]-=num/2;
	c[B[ID]]-=num/2;
    }
    memset(mark,0,sizeof mark);
    dfs(1);
    cout<<"YES\n";
    for(int i=0;i<m;i++){
	cout<<Ans[i]<<"\n";
    }
    return 0;
}