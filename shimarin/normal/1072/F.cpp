#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cerr<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int M = 1010, lim = 2e8;
const int p[] = {19,17,13,11,7,5,3,2};
int cnt,q[10],tot[M];
poly v[M];
map<poly,int>f;
inline void dfs(int k,int x,int las){
	if (k==8){
		++cnt,tot[cnt]=1;
		FOR(i,0,k) v[cnt].pb(q[i]),tot[cnt]*=q[i]+1;
		f[v[cnt]]=cnt;
		return;
	}
	For(i,1,las){
		x*=p[k];
		if (x>lim) return;
	}
	For(i,las,30){
		q[k]=i;
		if (x<=lim) dfs(k+1,x,i); 
			else break;
		x=x*p[k];
	}
}
int dis[M][M];
poly e[M];
inline void bfs(poly v,int s){
	For(i,1,cnt) dis[s][i]=1e9;
	queue<int>q;
	dis[s][s]=0,q.push(s);
	while (!q.empty()){
		int v=q.front(),tmp;q.pop();
		for (auto to:e[v]) if (dis[s][to]==1e9){
			dis[s][to]=dis[s][v]+1,q.push(to);
		}
	}
}
const int N = 1e6+10;
int mx,mn[N],Dis[M][M],dis2[M][M];
inline void init(){
	dfs(0,1,0);
	For(i,1,cnt){
		FOR(j,0,siz(v[i])){
			poly tmp=v[i];
			if (tmp[j]) tmp[j]--;
			sort(all(tmp));
			int p=f[tmp];
			if (p) e[i].pb(p);
			tmp=v[i],tmp[j]++;
			sort(all(tmp));
			p=f[tmp];
			if (p) e[i].pb(p);
		}
	}
	For(i,1,cnt) bfs(v[i],i);
	For(i,2,1000000) if (!mn[i])
		For(j,1,1000000/i) mn[i*j]=i;
	For(i,1,cnt) mx=max(mx,tot[i]);
	For(i,1,cnt){
		For(j,1,mx) dis2[i][j]=1e9;
		For(j,1,cnt) dis2[i][tot[j]]=min(dis2[i][tot[j]],dis[i][j]);
	}
//	For(i,1,cnt){
//		For(j,i,cnt){
//			Dis[i][j]=1e9;
//			For(k,1,mx) Dis[i][j]=min(Dis[i][j],dis2[i][k]+dis2[j][k]);
//		}
//	}
}

int T,A[10],B[10];
inline void solve(int cas){
	int a=read(),b=read();
	fil(A,0),fil(B,0);
	int x=0;
	for (;a>1;a/=mn[a])
		if (mn[a]!=x) x=mn[a],A[++*A]=1;
			else ++A[*A];
	x=0;
	for (;b>1;b/=mn[b])
		if (mn[b]!=x) x=mn[b],B[++*B]=1;
			else ++B[*B];
	sort(A+1,A+9),sort(B+1,B+9);
	poly v,v2;
	For(i,1,8) v.pb(A[i]),v2.pb(B[i]);
	int l=f[v],r=f[v2];
	if (l>r) swap(l,r);
	int ans=1e9;
	For(k,1,mx) ans=min(ans,dis2[l][k]+dis2[r][k]);
	printf("%d\n",ans);
}

int main(){
	init();
	T=read();
	For(i,1,T) solve(i);
}