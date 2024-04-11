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

LL F[31][31];
LL n;
int m;
struct matrix{
	LL M[31][31];
	LL *operator [](const int dn){
		return M[dn];
	}
	void Rot(int x){
		for(int i=0;i<m;++i) for(int j=0;j<=m;++j) F[i][j]=M[i][j];
		int f=x;
		for(int i=0;i<m;++i){
			M[f][m]=F[i][m];
			int g=x;
			for(int j=0;j<m;++j){
				M[f][g]=F[i][j];
				if(++g==m) g=0;
			}
			if(++f==m) f=0;
		}
	}
}M[64][30],C,E;
LL now[33];
LL D[33];
vector<LL> Dec;
const int mod=1000000007;
void Mul(matrix &A,matrix &B){
	for(int i=0;i<=m;++i) for(int j=0;j<=m;++j) for(int k=0;k<=m;++k){
		C[i][j]+=B[i][k]*A[k][j];
		if(C[i][j]>=mod) C[i][j]%=mod;
	}
	for(int i=0;i<=m;++i) for(int j=0;j<=m;++j) A[i][j]=C[i][j],C[i][j]=0;
}
void Mul(LL A[],matrix &B){
	for(int i=0;i<=m;++i) for(int j=0;j<=m;++j){
		D[i]+=B[i][j]*A[j];
		if(D[i]>=mod) D[i]%=mod;
	}
	for(int i=0;i<=m;++i) A[i]=D[i],D[i]=0;
}
void solve(){
	cin>>n>>m;
	for(int i=0;i<=m;++i){
		E[i][i]=1;
	}
	for(int j=0;j<=m;++j) M[0][0][j][j]=M[0][0][0][j]=1;
	for(int i=1;i<m;++i){
		M[0][i]=M[0][0];
		M[0][i].Rot(i);
	}
	while(n){
		Dec.push_back(n%m);
		n/=m;
	}
	for(int i=1;i<int(Dec.size());++i){
		M[i][0]=E;
		for(int j=0;j<m;++j){
			Mul(M[i][0],M[i-1][j]);
		}
		for(int j=1;j<m;++j){
			M[i][j]=M[i][0];
			M[i][j].Rot(j);
		}
	}
	now[m]=1;
	int presum=0;
	for(int i=int(Dec.size())-1;i>=0;--i){
		for(int j=0;j<Dec[i];++j){
			Mul(now,M[i][(j+presum)%m]);
		}
		presum+=Dec[i];
		if(presum>=m) presum%=m;
	}
	LL ans=0;
	for(int i=0;i<=m;++i){
//		cout<<i<<" "<<now[i]<<endl;
		ans+=now[i];
		if(ans>=mod) ans-=mod;
	}
	cout<<ans<<endl;
}

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	solve();
	cin>>n;
	return 0;
}