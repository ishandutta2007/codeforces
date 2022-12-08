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
	while(c<'0'||c>'9'){c=Getchar();rev|=c=='-';if(Terminal)return 0;}
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
const int N=200005,M=700005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{int typ,x,y,w;}p[M],tmp[M];
int n,m,Q,a[N],last[N],pre[N];
ll c[N],ans[N];
set<int> s[N];

inline void add(int x,int y){
	while(x<=n) c[x]+=y,x+=x&-x;
}
inline ll get(int x){
	ll ans=0;
	while(x) ans+=c[x],x-=x&-x;
	return ans;
}
inline void add(int x,int y,int z){
	if(!x||!y) return;
	p[++m]=(node){0,x,y,z};
}
inline ui get(int x,int y,int q){
	x--;Q++;
	if(x) p[++m]=(node){Q,x,q,-1};
	p[++m]=(node){Q,y,q,1};
}
void solve(int l,int r,int x,int y){
	if(x>y) return;
	if(l==r){
		for(int i=x;i<=y;i++)
			if(!p[i].typ) add(p[i].y,p[i].w); else ans[p[i].typ]+=p[i].w*get(p[i].y);
		for(int i=x;i<=y;i++)
			if(!p[i].typ) add(p[i].y,-p[i].w);
		return;
	}
	int mid=l+r>>1;
	for(int i=x;i<=y;i++)
		if(!p[i].typ&&p[i].x<=mid) add(p[i].y,p[i].w);
		else if(p[i].typ&&p[i].x>mid) ans[p[i].typ]+=p[i].w*get(p[i].y);
	for(int i=x;i<=y;i++)
		if(!p[i].typ&&p[i].x<=mid) add(p[i].y,-p[i].w);
	int tl=x,tr=y;
	for(int i=x;i<=y;i++)
		if(p[i].x<=mid) tmp[tl++]=p[i]; 
	for(int i=y;i>=x;i--)
		if(p[i].x>mid) tmp[tr--]=p[i];
	memcpy(p+x,tmp+x,sizeof(node)*(y-x+1));
	solve(l,mid,x,tr);solve(mid+1,r,tl,y);
}
inline void make(int i,int k){
	add(pre[i],i,pre[i]-i);
	pre[i]=k;
	add(pre[i],i,i-pre[i]);
}
inline void del(int k,int p){
	set<int>::iterator it=s[k].find(p);
	int l,r;
	++it;
	if(it==s[k].end()){s[k].erase(p);return;}
	r=*it;
	--it;--it;l=*it;
	make(r,l);s[k].erase(p);
}
inline void ins(int k,int p){
	s[k].insert(p);
	set<int>::iterator it=s[k].find(p);
	int l,r;
	++it;
	if(it!=s[k].end()){
		r=*it;
		make(r,p);
	}
	--it;--it;
	l=*it;
	make(p,l);
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
	int Q;
	read(n);read(Q);
	for(int i=1;i<=n;i++)
		s[i].insert(0);
	for(int i=1;i<=n;i++){
		read(a[i]);
		pre[i]=last[a[i]];
		last[a[i]]=i;
		s[a[i]].insert(i);
		add(pre[i],i,i-pre[i]);
	}
	for(int i=1;i<=Q;i++){
		int t;read(t);
		if(t==1){
			int p,x,k;read(p,x);
			del(a[p],p);ins(x,p);
			a[p]=x;
		}
		else{
			int l,r;read(l,r);
			get(l,r,r);
		}
	}
//	return 0;
	solve(1,n,1,m);
	for(int i=1;i<=::Q;i++) print(ans[i]);
	return 0;
}