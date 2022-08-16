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
int n,a[N],mn[2],cnt[2];
ll s[N];
inline void solve(){
	n=read();
	For(i,1,n) a[i]=read();
	ll ans=1e18;
	mn[0]=mn[1]=1e9,s[0]=s[1]=cnt[0]=cnt[1]=0;
	For(i,1,n){
		mn[i&1]=min(mn[i&1],a[i]),s[i&1]+=a[i];
		cnt[i&1]++;
		if (i>=2) ans=min(ans,s[0]-mn[0]+1ll*mn[0]*(n-cnt[0]+1)+s[1]-mn[1]+1ll*mn[1]*(n-cnt[1]+1));
	}
	printf("%lld\n",ans);
}

int main(){
	int T=read();
	while (T--) solve();
}