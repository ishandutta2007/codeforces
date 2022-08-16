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

const int N = 1e5+10;
int n,q,k,a[N];
ll pre[N];
inline void solve(){
	n=read(),q=read(),k=read();
	For(i,1,n) a[i]=read();
	FOR(i,2,n) pre[i]=pre[i-1]+max(0,a[i+1]-a[i-1]-2);
	while (q--){
		int l=read(),r=read();
		if (l==r){
			printf("%d\n",k-1);
			continue;
		}
		ll ans=pre[r-1]-pre[l]+max(0,a[l+1]-2)+max(0,k-a[r-1]-1);
		printf("%lld\n",ans);
	}
}

int main(){
	int T=1;
	while (T--) solve();
}