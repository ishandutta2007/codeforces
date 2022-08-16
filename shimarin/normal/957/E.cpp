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
int n,m,x[N],v[N],cnt;
double c[N<<1];
pair<double,double>b[N];

int t[N];
inline void Add(int x,int y){
	for (;x<=cnt;x+=x&-x) t[x]+=y;
}
inline int Query(int x){
	int ret=0;
	for (;x;x-=x&-x) ret+=t[x];
	return ret;
}

int main(){
	n=read(),m=read();
	For(i,1,n){
		x[i]=read(),v[i]=read();
		c[++cnt]=1.0*x[i]/(m-v[i]);
		c[++cnt]=1.0*x[i]/(m+v[i]);
		b[i]=mp(c[cnt-1],c[cnt]);
	}
	sort(c+1,c+1+cnt),cnt=unique(c+1,c+1+cnt)-c-1;
	For(i,1,n){
		b[i].fi=lower_bound(c+1,c+1+cnt,b[i].fi)-c;	
		b[i].se=lower_bound(c+1,c+1+cnt,b[i].se)-c;
	}
	sort(b+1,b+1+n);
	ll ans=0;
	For(i,1,n) ans+=Query(b[i].se),Add(b[i].se,1);
	printf("%lld\n",ans);
}