// Can U hack it?

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

const int maxn=3e5+10,inf=2e9;

int x[maxn],y[maxn];
pair<int,pii> w[maxn];
ll smx[maxn],smy[maxn];
vector<int>v[maxn];

inline int solve(int a,int b){
    return min(x[a]+y[b],x[b]+y[a]);
}

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
	scanf("%d%d",&x[i],&y[i]);
	w[i]={x[i]-y[i],{x[i],y[i]}};
    }
    sort(w+1,w+n+1);
    for(int i=1;i<=n;i++)
	smx[i]=smx[i-1]+w[i].S.F;
    for(int i=n;i>=1;i--)
	smy[i]=smy[i+1]+w[i].S.S;
    for(int i=1;i<=m;i++){
	int a,b;scanf("%d%d",&a,&b);
	v[a].PB(b);
	v[b].PB(a);
    }
    for(int i=1;i<=n;i++){
	pair<int,pii> P={x[i]-y[i],{inf,inf}};
	int id=upper_bound(w+1,w+n+1,P)-w;
	ll ans=1ll*x[i]*(n-id+1)+1ll*y[i]*(id-1)+smy[id]+smx[id-1];
	ans-=solve(i,i);
	for(int j:v[i])
	    ans-=solve(i,j);
	printf("%lld ",ans);
    }
    printf("\n");
    return 0;
}