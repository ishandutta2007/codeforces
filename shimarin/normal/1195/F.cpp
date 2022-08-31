#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
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
int n,q,B,tot,cnt[N],c[N],pre[N],id[N],x[N],y[N];
pa b[N];

struct query{
	int l,r,id;
}a[N];
bool cmp(query x,query y){return id[x.l]==id[y.l]?x.r<y.r:id[x.l]<id[y.l];}

int F;
map<pa,int>f;
inline void init(){
	For(i,1,pre[n]){
		int g=__gcd(abs(b[i].fi),abs(b[i].se));
		pa x=mp(b[i].fi/g,b[i].se/g);
		if (!f[x]) f[x]=++F;
		c[i]=f[x];
	//	printf(" %d %d\n",i,c[i]);
	}
}

int g[N],l,r,sum,ans[N];
inline void Add(int x){
	g[x]++;
	sum+=(g[x]==1);
}
inline void Del(int x){
	g[x]--;
	sum-=(g[x]==0);
}

int main(){
	n=read();
	For(i,1,n){
		cnt[i]=read();
		For(j,1,cnt[i]) x[j]=read(),y[j]=read();
		For(j,2,cnt[i]) b[++tot]=mp(x[j]-x[j-1],y[j]-y[j-1]);
		b[++tot]=mp(x[1]-x[cnt[i]],y[1]-y[cnt[i]]);
		pre[i]=tot;
	}
//	For(i,1,tot) printf("azhe %d %d\n",b[i].fi,b[i].se);
	init();
	B=sqrt(pre[n]);
	For(i,1,pre[n]) id[i]=(i-1)/B+1;
	q=read();
	For(i,1,q){
		int l=read(),r=read();
		a[i]=(query){pre[l-1]+1,pre[r],i};
		//printf("Query %d %d\n",a[i].l,a[i].r);
	}
	sort(a+1,a+1+q,cmp);
	For(i,a[1].l,a[1].r) Add(c[i]);
	l=a[1].l,r=a[1].r,ans[a[1].id]=sum;
	For(i,2,q){
		while (l<a[i].l) Del(c[l++]);
		while (l>a[i].l) Add(c[--l]);
		while (r<a[i].r) Add(c[++r]);
		while (r>a[i].r) Del(c[r--]);
		ans[a[i].id]=sum;
	}
	For(i,1,q) printf("%d\n",ans[i]);
}