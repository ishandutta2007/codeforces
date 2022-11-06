/*
ID: rowdark1
LANG: C++
PROG:
*/

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

#define X first
#define Y second
#define REP_0(i,n)for(int i=0;i<(n);++i)
#define REP_1(i,n)for(int i=1;i<=(n);++i)
#define REP_2(i,a,b)for(int i=(a);i<(b);++i)
#define REP_3(i,a,b)for(int i=(a);i<=(b);++i)
#define REP_4(i,a,b,c)for(int i=(a);i<(b);i+=(c))
#define DOW_0(i,n)for(int i=(n)-1;-1<i;--i)
#define DOW_1(i,n)for(int i=(n);0<i;--i)
#define DOW_2(i,a,b)for(int i=(b);(a)<i;--i)
#define DOW_3(i,a,b)for(int i=(b);(a)<=i;--i)
#define FOREACH(a,b)for(a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b)for(a=(b).rbegin();a!=b.rend();++a)
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
	void init(int _S,int _T);
}E[10001],*V[10001],*PE;
void EDGE::init(int _S,int _T){
	Nxt=V[_S],V[_S]=this,T=_T;
}
int end;

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

map<string,int> M;
map<string,int>::IT iter;
VI B[10011],ANS;

int n;

string s1,s2;

inline int deal(VI &x,VI &y){
	sort(x.begin(),x.end());
	int nowans=0,ccans=0;
	int prex=-1,nc=-1;
	int i=-1,j=0;
	while(++i<int(x.size()))
	{
		while(j!=int(y.size())&&x[i]>y[j]) ++j;
		if(j!=int(y.size())&&x[i]==y[j]) continue;
		else
		{
			if(x[i]!=prex)
			{
				if(nc>nowans)
				{
					nowans=nc,ccans=0;
				}
				if(nc==nowans) ++ccans;
				prex=x[i];
				nc=1;
			}
			else
			{
				++nc;
			}
		}
	}
	if(nc>nowans)
	{
		nowans=nc,ccans=0;
	}
	if(nc==nowans) ++ccans;
	if(nowans==0) return end-y.size();
	return ccans;
}

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>n;
	PE=E;
	while(n--)
	{
		cin>>s1>>s2;
		int i1,i2;
		iter=M.find(s1);
		if(iter==M.end()) M.insert(MP(s1,end)),i1=end++;
		else i1=iter->Y;
		iter=M.find(s2);
		if(iter==M.end()) M.insert(MP(s2,end)),i2=end++;
		else i2=iter->Y;
		PE++->init(i1,i2);
		PE++->init(i2,i1);
		B[i1].PB(i2),B[i2].PB(i1);
	}
	for(int i=0;i<end;++i) B[i].PB(i),sort(B[i].begin(),B[i].end());
	cout<<M.size()<<endl;
	for(iter=M.begin();iter!=M.end();++iter)
	{
		ANS.clear();
		for(PE=V[iter->Y];PE;PE=PE->Nxt)
		{
			for(int j=0;j<int(B[PE->T].size());++j)
			{
				ANS.PB(B[PE->T][j]);
			}
		}
		cout<<iter->X<<" "<<deal(ANS,B[iter->Y])<<endl;
	}
	return 0;
}