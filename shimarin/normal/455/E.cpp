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
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
namespace IO {
	static const int OUT_BUF = 1 << 23;
	inline void myPutchar(char x) {
		static char pbuf[OUT_BUF], *pp = pbuf;
		struct _flusher {
			~_flusher() {
				fwrite(pbuf, 1, pp - pbuf, stdout);
			}
		};
		static _flusher outputFlusher;
		if (pp == pbuf + OUT_BUF) {
			fwrite(pbuf, 1, OUT_BUF, stdout);
			pp = pbuf;
		}
		*pp++ = x;
	}
	#define putchar myPutchar
	template<typename T>
	inline void print_(T x) {
		if (x == 0) {
			putchar('0');
			return;
		}
		static int num[40];
		if (x < 0) {
			putchar('-');
			x = -x;
		}
		for (*num = 0; x; x /= 10) {
			num[++*num] = x % 10;
		}
		while (*num){
			putchar(num[*num] ^ '0');
			--*num;
		}
	}

	template<typename T>
	inline void print(T x, char ch = '\n') {
		print_(x);
		putchar(ch);
	}
}

const int N = 1e5+10;
int n,q,a[N];
ll pre[N],ans[N];
vector<pa>Q[N];

int top,stk[N],lascnt[N];
struct line{
	int k;
	ll b;
	inline ll f(int x){
		return 1ll*k*x+b;
	}
};

const int M = N*30;
int tot,pos[M],pos2[N],_ls[M],_rs[M];
line _v[M];

int rt,cnt,lson[N],rson[N];
line v[N];
inline void insert(int &u,int l,int r,line x,int now){
	if (!u) return u=++cnt,lson[cnt]=rson[cnt]=0,v[u]=x,void(0);
	int mid=l+r>>1;
	++tot,pos[tot]=u,_ls[tot]=lson[u],_rs[tot]=rson[u];
	_v[tot]=v[u];
	if (x.f(mid)<v[u].f(mid)) swap(x,v[u]);
	if (x.f(l)<v[u].f(l)) insert(lson[u],l,mid,x,now);
	else if (x.f(r)<v[u].f(r)) insert(rson[u],mid+1,r,x,now);
}
inline ll Query(int u,int l,int r,int x){
	if (!u) return 1e18;
	int mid=l+r>>1;
	if (l==r) return v[u].f(x);
	if (x<=mid) return min(v[u].f(x),Query(lson[u],l,mid,x));
		else return min(v[u].f(x),Query(rson[u],mid+1,r,x));
}

inline ll query(int now,int x){
	ll ans=pre[now]+Query(rt,-1e9,1e9,x-now);
//	For(i,1,top) ans=min(ans,pre[now]-pre[stk[i]]+1ll*a[stk[i]]*(x-(now-stk[i]))); 
	return ans;
}

int main(){
	n=read();
	For(i,1,n) a[i]=read(),pre[i]=pre[i-1]+a[i];
	q=read();
	For(i,1,q){
		int x=read(),y=read();
		Q[y].pb(mp(x,i));
	}
	For(i,1,n){
		while (top&&a[i]<=a[stk[top]]){
			cnt=lascnt[top];
			while (tot>pos2[top]){
				v[pos[tot]]=_v[tot];
				lson[pos[tot]]=_ls[tot];
				rson[pos[tot]]=_rs[tot];
				--tot;
			}
			if (cnt==0) rt=0;
			--top;
		}
		stk[++top]=i,lascnt[top]=cnt,pos2[top]=tot,insert(rt,-1e9,1e9,(line){a[i],1ll*a[i]*i-pre[i]},top);
		for (auto j:Q[i]) ans[j.se]=query(i,j.fi);
	}
	For(i,1,q) IO::print(ans[i]);//printf("%lld\n",ans[i]);
}