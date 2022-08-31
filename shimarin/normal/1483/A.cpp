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

const int N = 1e5+10;
int n,m,vis[N],ans[N];
poly v[N];
inline void solve(){
	n=read(),m=read();
	For(i,1,n) vis[i]=0;
	For(i,1,m){
		int cnt=read();
		v[i].clear();
		For(j,1,cnt) v[i].pb(read());
		ans[i]=v[i][0],++vis[ans[i]];
	}
	For(i,1,n) if (vis[i]>(m+1)/2){
		For(j,1,m){
			if (v[j][0]==i&&siz(v[j])>1){
				--vis[i],ans[j]=v[j][1];
			}
			if (vis[i]<=(m+1)/2) break;
		}
		if (vis[i]>(m+1)/2) return puts("NO"),void(0);
	}
	puts("YES");
	For(i,1,m) printf("%d ",ans[i]);
	puts("");
}

int main(){
	int T=read();
	while (T--) solve();
}