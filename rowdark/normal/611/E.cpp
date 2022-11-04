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

int n,A[10];
int t[1000001];
int B[10];
int C[10];

int main(){
	scanf("%d%d%d%d",&n,A+0,A+1,A+2);
	REP_1(i,n) scanf("%d",t+i);
	sort(t+1,t+n+1);
	sort(A,A+3);
	A[3]=A[0]+A[1];
	A[4]=A[0]+A[2];
	A[5]=A[1]+A[2];
	A[6]=A[0]+A[1]+A[2];
	for(int i=0;i<7;++i) B[i]=upper_bound(t+1,t+n+1,A[i])-t-1;
	if(B[6]<n){
		printf("-1\n");
	}
	else{
		int ans=0;
		C[6]=B[6]-B[5];
		C[5]=B[5]-B[4];
		C[4]=B[4]-max(B[3],B[2]);
		C[0]=B[0],C[1]=B[1]-B[0],C[2]=B[2]-B[1];
		if(C[5]>C[0]) C[0]=0;
		else C[0]-=C[5];
		if(C[4]>C[1]){
			C[0]-=C[4]-C[1];
			if(C[0]<0) C[0]=0;
			C[1]=0;
		}
		else C[1]-=C[4];
		if(A[3]>=A[2]){
			C[2]=B[2]-B[1],C[3]=B[3]-B[2];
			if(C[3]>C[2]){
				C[1]-=C[3]-C[2];
				if(C[1]<0){
					C[0]+=C[1];
					if(C[0]<0) C[0]=0;
					C[1]=0;
				}
				C[2]=0;
			}
			else C[2]-=C[3];
			if(C[2]>max((C[0]+C[1]+1)/2,C[1])){
				ans=C[6]+C[5]+C[4]+C[3]+max((C[0]+C[1]+1)/2,C[1])+(C[2]-max((C[0]+C[1]+1)/2,C[1])+1)/2;
			}
			else{
				ans=C[6]+C[5]+C[4]+C[3]+max((C[0]+C[1]+C[2]+2)/3,max((C[1]+C[2]+1)/2,C[2]));
			}
		}
		else{
			C[2]=B[2]-B[1];
			if(C[2]>max((C[0]+C[1]+1)/2,C[1])){
				C[3]=B[3]-B[1];
				C[2]-=max((C[0]+C[1]+1)/2,C[1]);
				if(C[2]>C[3]) C[2]-=C[3];
				else C[3]=C[2],C[2]=0;
				ans=C[6]+C[5]+C[4]+max((C[0]+C[1]+1)/2,C[1])+max(C[2],(C[2]+C[3]+1)/2);
			}
			else{
				ans=C[6]+C[5]+C[4]+max((C[0]+C[1]+C[2]+2)/3,max((C[1]+C[2]+1)/2,C[2]));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}