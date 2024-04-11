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
int a[200002];
LL sum[200101];
int anspos,anstype,ansr;
LL ansnumer=0,ansdomin=1;

inline bool lessthan(LL x,LL y,LL z,LL w){
	if(x<0&&z<0) return lessthan(-z,w,-x,y);
	if(x<0) return true;
	if(z<0) return false;
	if(x/y!=z/w){
		return x/y<z/w;
	}
	x%=y,z%=w;
	return x*w<y*z;
}

void getValue2(int x,int r,LL &ret1,LL &ret2){
	LL tmp=sum[x+1]-sum[x-r-1]+sum[n]-sum[n-r];
	LL sf=a[x]+a[x+1];
	ret1=tmp*2-sf*(2*r+2);
	ret2=(2*r+2)*2;
}

void getValue(int x,int r,LL &ret1,LL &ret2){
	LL tmp=sum[x]-sum[x-r-1]+sum[n]-sum[n-r];
	LL sf=a[x];
	ret1=tmp-sf*(2*r+1);
	ret2=2*r+1;
}

int main(){
	scanf("%d",&n);
	REP_1(i,n){
		scanf("%d",a+i);
	}
	sort(a+1,a+n+1);
	REP_1(i,n) sum[i]=sum[i-1]+a[i];
	anspos=1,anstype=1,ansr=0;
	REP_1(i,n){
		if(i!=n){
			//i-r...i,i+1,n-r+1..n
			int LR=0,RR=min(n-i-1,i-1);
			while(LR+5<=RR){
				int mid1=(LR*2+RR)/3;
				int mid2=(LR+RR*2)/3;
				LL num1,dom1,num2,dom2;
				getValue2(i,mid1,num1,dom1);
				getValue2(i,mid2,num2,dom2);
				if(lessthan(num1,dom1,num2,dom2)){
					LR=mid1;
				}
				else{
					RR=mid2;
				}
			}
			REP_3(j,LR,RR){
				LL num,dom;
				getValue2(i,j,num,dom);
				if(lessthan(ansnumer,ansdomin,num,dom)){
					ansnumer=num,ansdomin=dom;
					anspos=i,anstype=2,ansr=j;
				}
			}
		}
		{
			//i-r...i,n-r+1..n
			int LR=0,RR=min(n-i,i-1);
			while(LR+5<=RR){
				int mid1=(LR*2+RR)/3;
				int mid2=(LR+RR*2)/3;
				LL num1,dom1,num2,dom2;
				getValue(i,mid1,num1,dom1);
				getValue(i,mid2,num2,dom2);
				if(lessthan(num1,dom1,num2,dom2)){
					LR=mid1;
				}
				else{
					RR=mid2;
				}
			}
			REP_3(j,LR,RR){
				LL num,dom;
				getValue(i,j,num,dom);
				if(lessthan(ansnumer,ansdomin,num,dom)){
					ansnumer=num,ansdomin=dom;
					anspos=i,anstype=1,ansr=j;
				}
			}
		}
	}
	vector<int> ans;
	REP_3(i,anspos-ansr,anspos) ans.push_back(a[i]);
	if(anstype==2) ans.push_back(a[anspos+1]);
	REP_3(i,n-ansr+1,n) ans.push_back(a[i]);
	printf("%d\n",int(ans.size()));
	REP_0(i,int(ans.size())) printf("%d%c",ans[i],i==int(ans.size())-1?'\n':' ');
	return 0;
}