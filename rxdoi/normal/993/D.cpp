#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=50+19;
const ll oo=1ll<<60;

pii P[N];
ll val[N],l,r;
ll dp[2][N];
int n,c;

void upd(ll &x,ll y){
	if (y<x) x=y;
}
bool check(ll k){
	For(i,1,n+1) val[i]=1000ll*P[i].fi-k*P[i].se;
	For(i,0,2) For(j,0,N) dp[i][j]=oo;
	dp[c][0]=0;
	for (int l=1,r;l<=n;l=r+1){
		For(i,0,N) dp[c^1][i]=oo;
		for (r=l;r+1<=n&&P[r+1].fi==P[l].fi;r++);
		vector<ll> V;
		For(i,l,r+1) V.pb(val[i]);
		sort(V.begin(),V.end());
		For(i,0,N) if (dp[c][i]!=oo){
			ll sum=0;
			For(j,0,r-l+2){
				if (r-l+1-j<=i){
					upd(dp[c^1][i-(r-l+1-j)+j],dp[c][i]+sum);
				}
				if (j<V.size()) sum+=V[j];
			}
		}
		c^=1;
	}
	For(i,0,N) if (dp[c][i]<=0) return 1;
	return 0;
}

int main(){
	n=IN();
	For(i,1,n+1) P[i].fi=IN();
	For(i,1,n+1) P[i].se=IN();
	sort(P+1,P+n+1,greater<pii>());
	l=0,r=ll(1e11);
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid)) r=mid-1;else l=mid+1;
	}
	cout<<r+1<<endl;
}