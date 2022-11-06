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
#define FOREACH(a,b) for(typeof(b.begin()) a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b) for(typeof(b.rbegin()) a=(b).rbegin();a!=b.rend();++a)
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
T By(T x,T y,T P){
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
T Mul(T x,T y,T P){
	T F1=1;x%=P;
	while(y)
	{
		if(y&1)
		{
			F1=By(F1,x,P);
		}
		x=By(x,x,P);
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

struct EDGE{
	int T;EDGE *Nxt;
};

template<class T>
void UpdataMin(T &x,T y){
	if(y<x)
	{
		x=y;
	}
}

template<class T>
void UpdataMax(T &x,T y){
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
	char buff[MaxBuffer];
	char *buf;
	void init(int size=MaxBuffer)
	{
		fread(buff,1,size,stdin);
	}
	template<class T>
	bool readInterger(T &x)
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
vector<int> V[100002];
vector<int> ansH,ansT;
PII E[100002];
int Common[100002];
int calcunion(int i,int j){
	if(V[i].size()>V[j].size()) swap(i,j);
	int l=0;
	for(int k=0;k<int(V[i].size());++k)
	{
		l+=binary_search(V[j].begin(),V[j].end(),V[i][k]);
	}
	return int(V[i].size()+V[j].size()-l);
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int N,M,H,T;
	cin>>N>>M>>H>>T;
	for(int i=1;i<=M;++i)
	{
		cin>>E[i].X>>E[i].Y;
		V[E[i].X].PB(E[i].Y);
		V[E[i].Y].PB(E[i].X);
	}
	REP_1(i,N) sort(V[i].begin(),V[i].end());
	bool flag=false;
	REP_1(i,M)
	{
		int x=E[i].X,y=E[i].Y;
		if(H>T&&V[x].size()<V[y].size()||H<T&&V[x].size()>V[y].size()) swap(x,y);
		if(int(V[x].size())>=H+1&&int(V[y].size())>=T+1&&calcunion(x,y)>=H+T+2)
		{
			cout<<"YES"<<endl;
			cout<<x<<" "<<y<<endl;
			for(int i=0;i<int(V[x].size());++i)
			{
				++Common[V[x][i]];
			}
			for(int i=0;i<int(V[y].size());++i)
			{
				++Common[V[y][i]];
			}
			for(int i=0;i<int(V[x].size());++i)
			{
				if(int(ansH.size())==H) break;
				if(V[x][i]!=y&&Common[V[x][i]]!=2) ansH.PB(V[x][i]);
			}
			for(int i=0;i<int(V[y].size());++i)
			{
				if(int(ansT.size())==T) break;
				if(V[y][i]!=x&&Common[V[y][i]]!=2) ansT.PB(V[y][i]);
			}
			if(int(ansH.size())<H)
			{
				for(int i=0;i<int(V[x].size());++i)
				{
					if(int(ansH.size())==H) break;
					if(Common[V[x][i]]==2)
					{
						ansH.PB(V[x][i]);
						--Common[V[x][i]];
					}
				}
			}
			if(int(ansT.size())<T)
			{
				for(int i=0;i<int(V[y].size());++i)
				{
					if(int(ansT.size())==T) break;
					if(Common[V[y][i]]==2)
					{
						ansT.PB(V[y][i]);
						--Common[V[y][i]];
					}
				}
			}
			REP_0(i,H) cout<<ansH[i]<<(i==H-1?'\n':' ');
			REP_0(i,T) cout<<ansT[i]<<(i==T-1?'\n':' ');
			flag=true;
			break;
		}
	}
	if(!flag) cout<<"NO"<<endl;
	return 0;
}