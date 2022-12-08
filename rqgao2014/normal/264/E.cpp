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
const int N=200555,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,m,a[N],dp[N];
set<pii> num,pos;

struct sgt{
	int p[N<<2],pos[N],n;
	void build(int l,int r,int k=1){
		if(l==r){pos[l]=k;return;}
		int mid=l+r>>1;
		build(l,mid,ls);build(mid+1,r,rs);
	}
	inline int get(int l,int r,int x,int y,int k){
		if(x<=l&&r<=y) return p[k];
		int mid=l+r>>1,res=0;
		if(x<=mid) gmax(res,get(l,mid,x,y,ls));
		if(y>mid) gmax(res,get(mid+1,r,x,y,rs));
		return res;
	}
/*	inline void change(int l,int r,int x,int k,int b){
		if(l==r){p[k]=b;return;}
		int mid=l+r>>1;
		if(x<=mid) change(l,mid,x,ls,b); else change(mid+1,r,x,rs,b);
		p[k]=max(p[ls],p[rs]);
	}*/
	inline void change(int x,int y){
		int k=pos[x];p[k]=y;
		while(k>>1)
			k>>=1,p[k]=max(p[ls],p[rs]);
	}
	inline int get(int l,int r){
		if(l>r) return 0;
		return get(1,n,l,r,1);
	}
}t1,t2;

inline void change(int x,int y){
	dp[x]=y;
	t1.change(x,y);
	t2.change(a[x],y);
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	read(n,m);
	t1.n=n;t2.n=m+10;
	t1.build(1,n);t2.build(1,m+10);
	for(int i=1;i<=m;i++){
		int typ;
		read(typ);
		if(typ==1){
			int p,h;read(p,h);
			vector<pii> tmp;tmp.clear();
			vi pp;pp.clear();
			p=n+1-p;h=h+m-i;a[p]=h;
			set<pii>::iterator it=num.begin();
			while(it!=num.end()&&(*it).FF<h){
				if((*it).SS<p) tmp.pb(mp((*it).SS,dp[(*it).SS])),change((*it).SS,0); else pp.pb((*it).SS);
				it++;
			}
			change(p,t1.get(1,p-1)+1);
			for(pii j:tmp)
				change(j.FF,j.SS);
			sort(pp.begin(),pp.end());
			for(int j=0;j<SZ(pp);j++){
				gmax(dp[pp[j]],dp[p]+1);
				for(int jp=0;jp<j;jp++)
					if(a[pp[jp]]>a[pp[j]]) gmax(dp[pp[j]],dp[pp[jp]]+1);
				change(pp[j],dp[pp[j]]);
			}
			num.insert(mp(h,p));pos.insert(mp(p,h));
		}
		else{
			int x,p,h;read(x);
			set<pii>::iterator it=pos.end();
			for(int j=1;j<=x;j++){
				it--;
				change((*it).FF,0);
			}
			p=(*it).FF;h=(*it).SS;
			for(int j=1;j<x;j++){
				it++;
				change((*it).FF,t2.get((*it).SS+1,m+10)+1);
			}
			num.erase(mp(h,p));pos.erase(mp(p,h));
		}
		print(t1.get(1,n));
	}
	return 0;
}