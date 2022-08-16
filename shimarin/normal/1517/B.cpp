#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
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


const int N = 110, M = 1e5+10;
int n,m,v[M],p[M],a[N][N],vis[N][N],id[N][N];
inline void work2(){
	For(i,1,n){
		int now=1;
		For(j,1,m) if (!vis[i][j]){
			while (id[i][now]) ++now;
			id[i][now]=a[i][j];
		}
	}
}
inline void solve(){
	n=read(),m=read();
	int cnt=0;
	For(i,1,n) For(j,1,m) a[i][j]=read(),v[++cnt]=a[i][j];
	For(i,1,cnt) p[i]=i;
	sort(p+1,p+1+cnt,[&](int a,int b){return v[a]<v[b];});
	fil(id,0),fil(vis,0);
	For(i,1,m){
		int a=(p[i]-1)/m+1,b=(p[i]-1)%m+1;
		id[a][i]=::a[a][b],vis[a][b]=1;
	}
	work2();
	For(i,1,n){
		For(j,1,m) printf("%d ",id[i][j]);
		puts("");
	}
}
int main(){
	int T=read();
	while (T--) solve();
}