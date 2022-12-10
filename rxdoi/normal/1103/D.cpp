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

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1e6+19;
const int top=1e6;
const ll oo=1ll<<60;

map<ll,Vi> M;
Vi S[1<<11],H[N];
int pri[N],vis[N],B[N];
int n,c;
ll dp[1<<11][12];
ll A[N],p[20],val[20];
ll k,g,ans;
Vi V,G;

void upd(ll &x,ll y){
	if (y<x) x=y;
}
bool cmp(int x,int y){
	return B[x]<B[y];
}
void Init(){
	For(i,2,top+1){
		if (!vis[i]) pri[++*pri]=i;
		for (int j=1;j<=*pri&&pri[j]*i<=top;j++){
			vis[pri[j]*i]=1;
			if (i%pri[j]==0) break;
		}
	}
}
void gao(ll x){
	For(i,1,*pri+1){
		if (x%pri[i]==0){
			p[c++]=pri[i];
			while (x%pri[i]==0) x/=pri[i];
		}
	}
	if (x>1) p[c++]=x;
}
void dfs(int x,int mask,ll v){
	if (v>k) return;
	if (x==c){
		if (mask) G.pb(mask);
		return;
	}
	dfs(x+1,mask,v);
	dfs(x+1,mask|1<<x,v*val[x]);
}

int main(){
	Init();
	n=IN(),k=IN();
	For(i,1,n+1) A[i]=IN(),g=__gcd(g,A[i]);
	For(i,1,n+1) B[i]=IN();
	gao(g);
	For(i,1,n+1){
		ll x=A[i],y=1;
		For(j,0,c){
			while (x%p[j]==0) x/=p[j],y*=p[j];
		}
		M[y].pb(B[i]);
	}
	n=0;
	for (auto T:M){
		ll x=T.fi;
		For(i,0,c){
			val[i]=1;
			while (x%p[i]==0) x/=p[i],val[i]*=p[i];
		}
		sort(T.se.begin(),T.se.end());
		if (T.se.size()>c) T.se.resize(c);
		G.clear();
		dfs(0,0,1);
		if (G.empty()) continue;
		for (int i:T.se){
			B[++n]=i;
			for (int w:G) S[w].pb(n);
		}
	}
	For(w,0,1<<c){
		sort(S[w].begin(),S[w].end(),cmp);
		if (S[w].size()>c) S[w].resize(c);
		for (int i:S[w]){
			H[i].pb(w);
		}
	}
	For(w,0,1<<c) For(i,0,c+1) dp[w][i]=oo;
	dp[0][0]=0;
	For(i,1,n+1){
		for (int j=c;j;j--){
			for (int w:H[i]){
				for (int u=~w&(1<<c)-1,t=u;;t=(t-1)&u){
					upd(dp[t|w][j],dp[t][j-1]+B[i]);
					if (!t) break;
				}
			}
		}
	}
	ans=oo;
	For(i,0,c+1)
		if (dp[(1<<c)-1][i]!=oo){
			upd(ans,dp[(1<<c)-1][i]*i);
		}
	if (ans==oo){
		puts("-1");
	} else{
		cout<<ans<<endl;
	}
}