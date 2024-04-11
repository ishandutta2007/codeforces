#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define all(a) a.begin(),a.end()
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
//--------------------------------head---------------------------------------------

const int N=25,M=5005;int mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int cell[M],C[N][N],CNT;
int c,c0,c1,c2,cnt,d,O,L=2,R=5001;

inline int sum(int x,int y,int k=0){
	if(!k) k=++L;
	printf("+ %d %d %d\n",x,y,k);
	++CNT;cell[k]=(cell[x]+cell[y])%mod;
	return k;
}
inline int power(int x,int k=0){
	if(!k) k=++L;
	printf("^ %d %d\n",x,k);
	++CNT;cell[k]=exp(cell[x],d);
	return k;
}
inline int zero(){
	int ans=--R,t=--R,y=mod-1;
	while(y){
		t=sum(t,t,t);y>>=1;
		if(y&1) ans=sum(ans,t);
	}
	return ans;
}
inline int multi(int x,int y){
	int k=--R;
	int ans=sum(O,O,k),t=sum(x,O,--R);
	while(y){
		if(y&1) ans=sum(ans,t,ans);
		t=sum(t,t,t);y>>=1;
	}
	return ans;
}
inline int neg(int x){return multi(x,mod-1);}
inline int sub(int x,int y){
	int t=neg(y);
	return sum(x,t,t);
}
inline int sqr(int x){
	int a[N],b=++L;
	b=multi(b,c);a[0]=multi(x,1);
	for(int i=1;i<=cnt;i++)
		a[i]=sum(a[i-1],b);
	int ans=sum(O,O);
	for(int i=0;i<=cnt;i++)
		if(cnt-i&1) ans=sub(ans,multi(power(a[i]),C[cnt][i])); else ans=sum(ans,multi(power(a[i]),C[cnt][i]));
	ans=multi(sub(ans,sum(multi(x,c1),multi(++L,c0))),exp(c2,mod-2));
	return ans;
}

inline int find(int c,int &c2,int &c1,int &c0,int &cnt){
	static int a[N],pw[N];
	for(int i=0;i<d;i++) a[i]=0;a[d]=1;
	pw[0]=1;for(int i=1;i<=d;i++) pw[i]=(ll)pw[i-1]*c%mod;
	int m=d;cnt=0;
	while(m>2){
		cnt++;
		for(int i=0;i<=m;i++){
			for(int j=0;j<i;j++)
				ch(a[j],(ll)C[i][j]*a[i]%mod*pw[i-j]);
			a[i]=0;
		}
		while(m>=0&&!a[m]) m--;
	}
	if(m==2) {c2=a[2],c1=a[1],c0=a[0];return 1;}
	return 0;
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
	freopen("output.txt","w",stdout);
#endif
	for(int i=0;i<=15;i++){
		C[i][i]=C[i][0]=1;
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(int i=1;i<=5000;i++) cell[i]=1;
	scanf("%d%d",&d,&mod);
	int x=1,y=2;
	cell[x]=rand()%mod;cell[y]=rand()%mod;
	O=zero();
	while(1){
		c=rand()%mod;
		if(find(c,c2,c1,c0,cnt)) break;
	}
	int p1=sqr(sum(x,y)),p2=sqr(sub(x,y));
	int g=sub(p1,p2),ans=multi(g,exp(4,mod-2));
	printf("f %d\n",ans);
	if(cell[ans]^(1ll*cell[x]*cell[y]%mod)) dprintf("false");
	debug(CNT);
	debug(cnt);
	return 0;
}