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

int n;

vector<int> xs;
vector<int> ts;

int o[1001000][4];
int fs[1001000][4];

int cnt[1001000];
int ans[1001000];
bool out[1001000];

void getAns(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	getAns(l,mid),getAns(mid+1,r);
	{
		int v=l;
		int j=mid+1;
		for(int i=l;i<=mid;++i){
			while(j<=r&&o[j][1]<o[i][1]){
				if(o[j][0]==3){
					ans[o[j][3]]+=cnt[o[j][2]];
				}
				fs[v][0]=o[j][0];
				fs[v][1]=o[j][1];
				fs[v][2]=o[j][2];
				fs[v][3]=o[j][3];
				++j,++v;
			}
			if(o[i][0]==1){
				++cnt[o[i][2]];
			}
			else if(o[i][0]==2){
				--cnt[o[i][2]];
			}
			fs[v][0]=o[i][0];
			fs[v][1]=o[i][1];
			fs[v][2]=o[i][2];
			fs[v][3]=o[i][3];
			++v;
		}
		while(j<=r){
			if(o[j][0]==3){
				ans[o[j][3]]+=cnt[o[j][2]];
			}
			fs[v][0]=o[j][0];
			fs[v][1]=o[j][1];
			fs[v][2]=o[j][2];
			fs[v][3]=o[j][3];
			++j,++v;
		}
		for(int i=l;i<=mid;++i){
			if(o[i][0]==1){
				--cnt[o[i][2]];
			}
			else if(o[i][0]==2){
				++cnt[o[i][2]];
			}
		}
		for(int i=l;i<=r;++i){
			o[i][0]=fs[i][0];
			o[i][1]=fs[i][1];
			o[i][2]=fs[i][2];
			o[i][3]=fs[i][3];
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",o[i],o[i]+1,o[i]+2);
		ts.PB(o[i][1]);
		xs.PB(o[i][2]);
		o[i][3]=i;
		out[i]=o[i][0]==3;
	}
	sort(ts.begin(),ts.end());
	sort(xs.begin(),xs.end());
	REP_1(i,n){
		o[i][1]=lower_bound(ts.begin(),ts.end(),o[i][1])-ts.begin();
		o[i][2]=lower_bound(xs.begin(),xs.end(),o[i][2])-xs.begin();
	}
	getAns(1,n);
	for(int i=1;i<=n;++i) if(out[i]) printf("%d\n",ans[i]);
	return 0;
}