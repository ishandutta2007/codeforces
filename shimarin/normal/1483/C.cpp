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

const int N = 3e5+10;
const ll inf = 1e18;
int n,a[N],b[N],l[N],r[N],top,stk[N];
ll f[N];

ll c[N];
inline void Add(int x,ll y){
	for (++x;x;x-=x&-x) c[x]=max(c[x],y);
}
inline ll Query(int x){
	ll ans=-inf;
	for (++x;x<=n+2;x+=x&-x) ans=max(ans,c[x]);
	return ans;
}

int main() {
	n=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) b[i]=read();
	For(i,1,n){
		while (top&&a[i]<a[stk[top]]) --top;
		l[i]=stk[top],stk[++top]=i;
		if (top==1) l[i]=-1;
	}
	stk[0]=n+1;
	top=0;
	Dow(i,n,1){
		while (top&&a[i]<a[stk[top]]) --top;
		r[i]=stk[top],stk[++top]=i;
	}
	//For(i,1,n) printf("%d %d %d\n",i,l[i],r[i]);
	For(i,0,n+2) c[i]=-inf;
	Add(0,0);
	For(i,1,n){
		f[i]=Query(l[i]+1)+b[i];
		Add(r[i],f[i]);
	}
	ll ans=-inf;
	For(i,1,n) if (r[i]==n+1) ans=max(ans,f[i]);
	printf("%lld\n",ans);
}