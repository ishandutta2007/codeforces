// Faster!

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

const int maxn=1010,mod=998244353;
const ll inf=1e18;

bool mark[maxn];
vector<int>v[maxn];
int a[maxn],ans,n;

pii solve(int u){
    mark[u]=1;
    pii p={1,0};
    for(int y:v[u]){
	if(mark[y]==0){
	    p=solve(y);
	    if(a[y]==-1) p.F=(p.F+p.S)%mod,p.S=p.F;
	    if(a[y]==1) swap(p.F,p.S);
	}
    }
    return p;
}

void change(int pos){
    if(a[pos]==-1) return;
    a[pos]=1-a[pos];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    reverse(s.begin(),s.end());
    n=sz(s);
    for(int i=0;i<n-1;i++){
	memset(mark,0,sizeof mark);
	int cof=1;
	for(int j=0;j<n;j++){
	    v[j].clear();
	}
	for(int j=0;j<n;j++){
	    if(s[j]=='0') a[j]=0;
	    if(s[j]=='1') a[j]=1;
	    if(s[j]=='?') a[j]=-1;
	    if(2*j!=i && 0<j && j<i) v[j].PB(i-j);
	    if(2*j!=n-1 && 0<j && j<n-1) v[j].PB(n-1-j);
	    if(j>0 && (2*j==i || 2*j==n-1)){
		if(a[j]==-1) cof*=2;
		else a[j]=-1;
	    }
	}
	change(n-1);
	if(i>0) change(i);
	int num=1;
	for(int j=0;j<n;j++){
	    if(sz(v[j])<2 && mark[j]==0){
		pii p=solve(j);
		int val=0;
		if(a[j]==-1) val=p.F+p.S;
		if(a[j]==0) val=p.F;
		if(a[j]==1) val=p.S;
		num=1ll*num*val %mod;
	    }
	}
	ans=(1ll*ans+1ll*cof*num)%mod;
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.