#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
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

const int N = 150010, inf = 1<<30;
int n[4],a[4][N],f[4][N],id[N];
bool vis[N];
poly v[4][N];

int main(){
	For(i,0,3) n[i]=read();
	For(i,0,3) For(j,1,n[i]) a[i][j]=read();
	For(i,1,3){
		int cnt=read();
		For(j,1,cnt){
			int x=read(),y=read();
			v[i][y].pb(x);
		}
	}
	For(i,1,n[0]) f[0][i]=a[0][i];
	For(i,1,3){
		For(j,1,n[i-1]) id[j]=j;
		sort(id+1,id+1+n[i-1],[=](int a,int b){
			return f[i-1][a]<f[i-1][b];
		});
		For(j,1,n[i]){
			f[i][j]=inf;
			for (auto k:v[i][j]) vis[k]=1;
			int p=1;
			while (vis[id[p]]) ++p;
			if (p<=n[i-1]) f[i][j]=f[i-1][id[p]]+a[i][j]; 
			for (auto k:v[i][j]) vis[k]=0;
		}
	}
	int ans=inf;
	For(j,1,n[3]) ans=min(ans,f[3][j]);
	printf("%d\n",ans==inf?-1:ans);
}