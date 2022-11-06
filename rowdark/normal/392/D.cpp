#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<bitset>
#include<iomanip>
#include<complex>
#include<utility>

#define X first
#define Y second
#define REP_0(i,n) for(int i=0;i<(n);++i)
#define REP_1(i,n) for(int i=1;i<=(n);++i)
#define REP_2(i,a,b) for(int i=(a);i<(b);++i)
#define REP_3(i,a,b) for(int i=(a);i<=(b);++i)
#define REP_4(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DOW_0(i,n) for(int i=(n)-1;-1<i;--i)
#define DOW_1(i,n) for(int i=(n);0<i;--i)
#define DOW_2(i,a,b) for(int i=(b);(a)<i;--i)
#define DOW_3(i,a,b) for(int i=(b);(a)<=i;--i)
#define FOREACH(a,b) for(typeof((b).begin()) a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b) for(typeof((b).rbegin()) a=(b).rbegin();a!=(b).rend();++a)
#define PB push_back
#define PF push_front
#define MP make_pair
#define IS insert
#define ES erase
#define IT iterator
#define RI reserve_iterator
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define ALL(x) x.begin(),x.end()

#define PI 3.1415926535897932384626433832795
#define EXP 2.7182818284590452353602874713527

using namespace std;

typedef long long LL;
typedef long double LD;
typedef double DB;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef pair<int,PII> PIII;
typedef pair<LD,int> PLDI;
typedef vector<PII> VII;

template<class T>
T Mul(T x,T y,T P){
	T F1=0;
	while(y)
	{
		if(y&1)
		{
			F1+=x;
			if(F1<0||F1>=P)F1-=P;
		}
		x<<=1;
		if(x<0||x>=P)x-=P;
		y>>=1;
	}
	return F1;
}

template<class T>
T Pow(T x,T y,T P){
	T F1=1;x%=P;
	while(y)
	{
		if(y&1)
		{
			F1=Mul(F1,x,P);
		}
		x=Mul(x,x,P);
		y>>=1;
	}
	return F1;
}

template<class T>
T Gcd(T x,T y){
	if(y==0)return x;
	T z;
	while(z=x%y){
		x=y,y=z;
	}
	return y;
}

template<class T>
void UpdateMin(T &x,T y){
	if(y<x)
	{
		x=y;
	}
}

template<class T>
void UpdateMax(T &x,T y){
	if(x<y)
	{
		x=y;
	}
}

template<class T>
T Sqr(const T x){
	return x*x;
}

template<class T>
T Abs(const T x){
	return x<0?-x:x;
}

#define MaxBuffer 20000000
class ReadBuffer{
	private:
	char buff[MaxBuffer];
	char *buf;
	public:
	void init(int size=MaxBuffer)
	{
		fread(buff,1,size,stdin);
		buf=buff;
	}
	template<class T>
	bool readInteger(T &x)
	{
		x=0;
		while(*buf&&isspace(*buf)) ++buf;
		if(*buf==0) return false;
		static bool flag;
		flag=0;
		if(*buf=='-') flag=true;
		else x=*buf-'0';
		while(isdigit(*++buf)) x=x*10+*buf-'0';
		if(flag) x=-x;
		return true;
	}
	template<class T>
	bool readFloat(T &x)
	{
		long double nowpos=0.1;
		x=0;
		while(*buf&&isspace(*buf)) ++buf;
		if(*buf==0) return false;
		static bool flag,decimal;
		decimal=flag=0;
		if(*buf=='-') flag=true,++buf;
		else if(*buf=='.') decimal=true;
		while(isdigit(*buf)||*buf=='.')
		{
			if(*buf=='.') decimal=true;
			else
			{
				if(decimal)
				{
					x+=nowpos*(*buf-'0');
					nowpos*=0.1;
				}
				else
				{
					x=x*10+*buf-'0';
				}
			}
			++buf;
		}
		return true;
	}
	bool readChar(char c)
	{
		if(*buf==0) return 0;
		return c=*buf++,1;
	}
	bool readString(char *s)
	{
		while(*buf&&isspace(*buf)) ++buf;
		if(!*buf) return false;
		while(!isspace(*buf)) *s++=*buf++;
		*s++=0;
		return true;
	}
	int countSpacetonext(){
		int total=0;
		while(*buf&&*buf==' ') ++total,++buf;
		return total;
	}
	bool splitBycharactor(char *s,char Split='\n'){
		while(*buf&&*buf!=Split) *s++=*buf++;
		*s++=0;
		return *buf!=0;
	}
};

struct EDGE{
	int T;EDGE *Nxt;
};

int ans;
int a[3][101001];
int value[301001][3];
int c[101001],n;
vector<pair<int,pair<int,int> > > V;
struct node{
	int minv,cover,minadd;
	int l,r;
	int getminadd(){
		return minadd;
	}
	void Cover(int x){
		cover=minadd=x;
		minv=l+x;
	}
	int getans(int x){
		return minv;
	}
}seg[262160];

void build(int l,int r,int x){
	seg[x].l=l,seg[x].r=r;
	seg[x].cover=-1;
	if(l==r){
		seg[x].Cover(c[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,x*2);
	build(mid+1,r,x*2+1);
	seg[x].minadd=min(seg[x*2+1].minadd,seg[x*2].minadd);
	seg[x].minv=min(seg[x*2+1].minv,seg[x*2].minv);
}

void Cover(int l,int r,int ll,int rr,int c,int x){
	if(l==ll&&r==rr){
		seg[x].Cover(c);
		return;
	}
	if(seg[x].cover!=-1){
		seg[x*2].Cover(seg[x].cover);
		seg[x*2+1].Cover(seg[x].cover);
		seg[x].cover=-1;
	}
	int mid=(l+r)>>1;
	if(mid<ll){
		Cover(mid+1,r,ll,rr,c,x*2+1);
	}
	else if(rr<=mid){
		Cover(l,mid,ll,rr,c,x*2);
	}
	else{
		Cover(l,mid,ll,mid,c,x*2);
		Cover(mid+1,r,mid+1,rr,c,x*2+1);
	}
	seg[x].minadd=min(seg[x*2+1].minadd,seg[x*2].minadd);
	seg[x].minv=min(seg[x*2+1].minv,seg[x*2].minv);
}
int getmin(int l,int r,int v,int x){
	if(seg[x].minadd>=v) return n+1;
	if(l==r) return l;
//	if(seg[x].minadd<v) return l;
	int mid=(l+r)/2;
	int y=getmin(l,mid,v,x*2);
	if(y!=n+1) return y;
	return getmin(mid+1,r,v,x*2+1);
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d",&n);
	REP_1(i,3*n) value[i][0]=value[i][1]=value[i][2]=3*n+1;
	REP_0(i,3){
		REP_1(j,n){
			scanf("%d",a[i]+j);
			V.PB(MP(a[i][j],MP(i,j)));
		}
	}
	sort(V.begin(),V.end());
	{
		int cnt=0;
		for(int i=0;i<int(V.size());++i){
			if(i==0||V[i].X!=V[i-1].X){
				++cnt;
			}
			if(value[cnt][V[i].Y.X]==3*n+1){
				value[cnt][V[i].Y.X]=V[i].Y.Y;
				a[V[i].Y.X][V[i].Y.Y]=cnt;
			}
			else a[V[i].Y.X][V[i].Y.Y]=-1;
		}
	}
	{
		int base=0;
		for(int i=1;i<=n;++i){
			if(a[2][i]!=-1){
				if(value[a[2][i]][0]>n&&value[a[2][i]][1]>n){
					base=i;
				}
			}
		}
		DOW_1(i,n){
			c[i]=base;
			if(a[1][i]!=-1&&value[a[1][i]][0]>n){
				base=max(base,value[a[1][i]][2]);
			}
		}
		c[0]=base;
	}
	build(0,n,1);
	int ans=seg[1].minv+n;
	DOW_1(i,n){
		if(a[0][i]!=-1){
			int x=value[a[0][i]][1];
			int y=value[a[0][i]][2];
			if(x>n&&y>n) break;
			int z=x<n+1?x-1:n;
			int w=getmin(0,n,y,1);
			if(w<=z){
				Cover(0,n,w,z,y,1);
			}
		}
		ans=min(ans,i-1+seg[1].minv);
	}
	printf("%d\n",ans);
	scanf("%d",&ans);
	return 0;
}