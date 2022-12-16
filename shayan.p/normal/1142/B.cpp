// Jump, and you will find out how to unfold your wings as you fall.

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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

int to[maxn],a[maxn],lst[maxn],nxt[20][maxn],sp[20][maxn];

int NXT(int u,int t){
    for(int i=19;i>=0;i--){
	if(u==-1) return -1;
	if(t>=(1<<i))
	    u=nxt[i][u],t-=1<<i;
    }
    return u;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,q;cin>>n>>m>>q;
    for(int i=0;i<n;i++){
	int x;cin>>x;
	to[--x]=i;
    }
    for(int i=0;i<m;i++){
	cin>>a[i];
	a[i]=to[a[i]-1];
    }
    memset(lst,-1,sizeof lst);
    memset(nxt,-1,sizeof nxt);
    for(int i=m-1;i>=0;i--){
	int x=(a[i]+1)%n;
	if(lst[x]!=-1) nxt[0][i]=lst[x];
	lst[a[i]]=i;
    }
    for(int i=1;i<20;i++){
	for(int j=0;j<m;j++){
	    if(nxt[i-1][j]!=-1)
		nxt[i][j]=nxt[i-1][nxt[i-1][j]];
	}
    }
    for(int i=0;i<m;i++){
	sp[0][i]=NXT(i,n-1);
	if(sp[0][i]==-1) sp[0][i]=m;
    }
    for(int i=1;i<20;i++){
	for(int j=0;j<m;j++){
	    sp[i][j]=sp[i-1][j];
	    if(j+(1<<i)<m)
		sp[i][j]=min(sp[i][j],sp[i-1][j+(1<<(i-1))]);
	}
    }
    while(q--){
	int l,r;cin>>l>>r;
	--l;
	int id=31-__builtin_clz(r-l);
	int mn=min(sp[id][l],sp[id][r-(1<<id)]);
	if(mn<r) cout<<1;
	else cout<<0;
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.