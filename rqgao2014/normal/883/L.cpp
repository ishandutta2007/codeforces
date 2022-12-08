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
const int N=200005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

struct node{
	int pos,id;
	ll ti;
};
struct node2{
	int pos,id;
	ll ti;
};

inline bool operator < (const node &a,const node &b){
	if(a.pos!=b.pos) return a.pos<b.pos;
	if(a.ti!=b.ti) return a.ti<b.ti;
	return a.id<b.id;
}
inline bool operator < (const node2 &a,const node2 &b){
	return a.ti>b.ti;
}

int n,k,m;
HEAP(node2) q;
set<node> s;
set<node>::iterator L,R;

inline void p(int a,ll b){
#ifdef rqgao2014
	printf("%d %lld\n",a,b);
#else
	printf("%d %I64d\n",a,b);
#endif
}

//pos,id,ti

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	read(n,k,m);
	for(int i=1;i<=k;i++){
		int x;read(x);
		s.insert((node){x,i,0});
	}
	for(int i=1;i<=m;i++){
		ll t;int a,b,c;
		read(t,a,b);
		while(!q.empty()){
			node2 tmp=q.top();
			if(tmp.ti<=t) s.insert((node){tmp.pos,tmp.id,tmp.ti}),q.pop(); else break;
		}
		if(!SZ(s)){
			node2 fir=q.top();
			while(!q.empty()&&q.top().ti==fir.ti){
				node2 tmp=q.top();
				s.insert((node){tmp.pos,tmp.id,tmp.ti}),q.pop();
			}
		}
//		debug(SZ(s));
		R=s.lower_bound((node){a,0,0});
		if(R==s.begin()){
			int id=(*R).id,pos=(*R).pos;
			ll ti=max(t,(*R).ti);
			s.erase(*R);
			q.push((node2){b,id,ti+abs(pos-a)+abs(a-b)});
			p(id,ti-t+abs(pos-a));
			continue;
		}
		L=R;L--;c=(*L).pos;
		L=s.lower_bound((node){c,0,0});
		if(R==s.end()){
			int id=(*L).id,pos=(*L).pos;
			ll ti=max(t,(*L).ti);
			s.erase(*L);
			q.push((node2){b,id,ti+abs(pos-a)+abs(a-b)});
			p(id,ti-t+abs(pos-a));
			continue;
		}
//		assert((*L).pos<=a);
//		assert((*R).pos>=a);
		node res=*L;
		if(mp(abs((*R).pos-a),mp((*R).ti,(*R).id))<mp(abs(a-res.pos),mp(res.ti,res.id))) res=*R;
		int id=res.id,pos=res.pos;
		ll ti=max(t,res.ti);
		s.erase(res);
		q.push((node2){b,id,ti+abs(pos-a)+abs(a-b)});
		p(id,ti-t+abs(pos-a));
	}
	return 0;
}