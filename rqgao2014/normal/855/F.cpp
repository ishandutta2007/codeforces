#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define HEAP(...) priority_queue<__VA_ARGS__ >
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__ >,greater<__VA_ARGS__ > > 
#define pii pair<int,int> 
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define SZ(x) ((int)x.size())
using namespace std;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
const int BufferSize=1<<16;
char buffer[BufferSize],*Bufferhead,*Buffertail;
bool Terminal;
inline char Getchar(){
	if(Bufferhead==Buffertail){
		int l=fread(buffer,1,BufferSize,stdin);
		if(!l){Terminal=1;return 0;}
		Buffertail=(Bufferhead=buffer)+l;
	}
	return *Bufferhead++;
}
template<class T>inline bool read(T &x){
	x=0;char c=Getchar(),rev=0;
	while(c<'0'||c>'9'){rev|=c=='-';c=Getchar();if(Terminal)return 0;}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=Getchar();
	if(c=='.'){
		c=Getchar();double t=0.1;
		while(c>='0'&&c<='9') x=x+(c-'0')*t,c=Getchar(),t=t/10;
	}
	x=rev?-x:x;
	return 1;
}
template<class T1,class T2> inline bool read(T1 &x,T2 &y){return read(x)&read(y);}
template<class T1,class T2,class T3> inline bool read(T1 &x,T2 &y,T3 &z){return read(x)&read(y)&read(z);}
template<class T1,class T2,class T3,class T4> inline bool read(T1 &x,T2 &y,T3 &z,T4 &w){return read(x)&read(y)&read(z)&read(w);}
inline bool reads(char *x){
	char c=Getchar();
	while(c<33||c>126){c=Getchar();if(Terminal)return 0;}
	while(c>=33&&c<=126) (*x++)=c,c=Getchar();
	*x=0;return 1;
}
template<class T>inline void print(T x,const char c='\n'){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[20];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
//--------------------------------head---------------------------------------------

const int inf=0x3f3f3f3f;
const int N=100005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n=100000;
set<int> s[2];
bool v[2][N];

struct node{ll sum;int mx,cnt,mx2,cnt2;};
inline void ins(int a,int b,int &mx,int &cnt,int &mx2,int &cnt2){
	if(a>mx) mx2=mx,cnt2=cnt,mx=a,cnt=b;
	else if(a==mx) cnt+=b;
	else if(a>mx2) mx2=a,cnt2=b;
	else if(a==mx2) cnt2+=b;
}
inline node operator + (const node &a,const node &b){
	int mx=0,cnt=0,mx2=0,cnt2=0;
	ins(a.mx,a.cnt,mx,cnt,mx2,cnt2);
	ins(a.mx2,a.cnt2,mx,cnt,mx2,cnt2);
	ins(b.mx,b.cnt,mx,cnt,mx2,cnt2);
	ins(b.mx2,b.cnt2,mx,cnt,mx2,cnt2);
	return (node){a.sum+b.sum,mx,cnt,mx2,cnt2};
}

struct sgt{
	node p[N<<2];
	int flag[N<<2];
	inline void add(int k,int b){
		if(b>=p[k].mx) return;
		p[k].sum+=(ll)(b-p[k].mx)*p[k].cnt;
		flag[k]=p[k].mx=b;
	}
	inline void push(int k){
		if(flag[k]==-1) return;
		add(ls,flag[k]);add(rs,flag[k]);
		flag[k]=-1;
	}
	inline void build(int l,int r,int k,int b){
		p[k]=(node){(ll)(r-l+1)*b,b,r-l+1,0,0};flag[k]=-1;
		if(l==r) return;
		int mid=l+r>>1;
		build(l,mid,ls,b);build(mid+1,r,rs,b);
	}
	inline void change(int l,int r,int x,int k,int b){
		if(l==r){p[k]=(node){b,b,1,0,0};return;}
		push(k);
		int mid=l+r>>1;
		if(x<=mid) change(l,mid,x,ls,b); else change(mid+1,r,x,rs,b);
		p[k]=p[ls]+p[rs];
	}
	inline void modify(int l,int r,int x,int y,int k,int b){
		if(p[k].mx<=b) return;
		if(x<=l&&r<=y&&p[k].mx2<b){add(k,b);return;}
		push(k);
		int mid=l+r>>1;
		if(x<=mid) modify(l,mid,x,y,ls,b);
		if(y>mid) modify(mid+1,r,x,y,rs,b);
		p[k]=p[ls]+p[rs];
	}
	inline ll get(int l,int r,int x,int y,int k){
		if(x<=l&&r<=y) return p[k].sum;
		push(k);
		int mid=l+r>>1;ll res=0;
		if(x<=mid) res+=get(l,mid,x,y,ls);
		if(y>mid) res+=get(mid+1,r,x,y,rs);
		return res;
	}
	inline void change(int x,int b){change(1,n,x,1,b);}
	inline void modify(int l,int r,int b){modify(1,n,l,r,1,b);}
	inline ll get(int l,int r){return get(1,n,l,r,1);}
}p[2][2];

inline void ins(int c,int l,int r,int k){
//	dprintf("%d %d %d %d\n",c,l,r,k);
	p[c][0].modify(l,r,k);
	set<int>::iterator it=s[c].lower_bound(l);
	vi del(0);
	while((*it)<=r){
		v[c][*it]=1;
		if(v[0][*it]&&v[1][*it]){
			p[0][1].change(*it,p[0][0].get(*it,*it));
			p[1][1].change(*it,p[1][0].get(*it,*it));
		}
		del.pb(*it);it++;
	}
	for(auto i:del) s[c].erase(i);
//	for(auto i:del) dprintf("%d ",i);puts("");
	del.clear();
	p[c][1].modify(l,r,k);
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	for(int i=1;i<=n;i++)
		s[0].insert(i),s[1].insert(i);
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			p[i][j].build(1,n,1,inf*(1-j));
	int Q;read(Q);
	while(Q--){
		int typ,l,r,k;
		read(typ,l,r);r--;
		if(typ==1){
			read(k);
			if(k>0) ins(0,l,r,k); else ins(1,l,r,-k);
		}
		else printf("%lld\n",p[0][1].get(l,r)+p[1][1].get(l,r));
	}
	return 0;
}