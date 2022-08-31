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

const int N = 2e7+10;
int n,tot,p[N],f[N];
bool vis[N];
inline void init(int n){
	f[1]=1;
	For(i,2,n){
		if (!vis[i]) p[++tot]=i,f[i]=2;
		for (int j=1;j<=tot&&i*p[j]<=n;++j){
			vis[i*p[j]]=1;
			if (i%p[j]==0){
				f[i*p[j]]=f[i];
				break;
			}
			f[i*p[j]]=2*f[i];
		}
	}
}

inline int calc(int c,int d,int x,int i){
	ll s=x+1ll*d*i;
	if (s%c==0){ 
		ll k=s/c;
		if (k%i==0) return f[k/i];
	}
	return 0;
}

inline void solve(){
	int c=read(),d=read(),x=read();
	int l=sqrt(x);
	ll ans=0;
	For(i,1,l) if (x%i==0){
		ans+=calc(c,d,x,i);
		if (i*i!=x){
			int j=x/i;
			ans+=calc(c,d,x,j);
		}
	}
	printf("%lld\n",ans);
}

int main(){
	init(2e7);
	int T=read();
	while (T--) solve();
}