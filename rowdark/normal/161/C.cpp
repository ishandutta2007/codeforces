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
#define REP_0(i,n) for(int i=0;i<(n);++i)
#define REP_1(i,n) for(int i=1;i<=(n);++i)
#define REP_2(i,a,b) for(int i=(a);i<(b);++i)
#define REP_3(i,a,b) for(int i=(a);i<=(b);++i)
#define REP_4(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DOW_0(i,n) for(int i=(n)-1;-1<i;--i)
#define DOW_1(i,n) for(int i=(n);0<i;--i)
#define DOW_2(i,a,b) for(int i=(b);(a)<i;--i)
#define DOW_3(i,a,b) for(int i=(b);(a)<=i;--i)
#define FOREACH(a,b) for(a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b) for(a=(b).rbegin();a!=b.rend();++a)
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
                        if(F1<0||F1>=P) F1-=P;
                }
                x<<=1;
                if(x<0||x>=P) x-=P;
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
	if(y==0) return x;
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

int A,B,C,D,F1,F2,F3,F4,F5;

bool Whole1,Whole2;
bool Get1,Get2;
bool Now1,Now2;

int ANS;

int Cx(int A1,int A2,int B1,int B2)
{
	int Zh=min(A2,B2)-max(A1,B1)+1;
	return Zh<0?0:Zh;
	
}

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>A>>B>>C>>D,--A,--C;
	DOW_0(i,31)
	{
		F1=A>>i,F2=B>>i;
		Get1=F1!=F2&&(F2-F1!=1||F2%2==1);
		F3=C>>i,F4=D>>i;
		Get2=F3!=F4&&(F4-F3!=1||F4%2==1);
		F5=(1<<(i+1))-1;
		if(Get1&&Get2)
		{
			if(Whole1)
			{
				if(Whole2)
				{
					UpdataMax(ANS,F5);
					break;
				}
				if(Now2)
				{
					UpdataMax(ANS,F5-(C&F5));
					UpdataMax(ANS,(D&F5));
				}
				else
				{
					UpdataMax(ANS,(D&F5)-(C&F5));
				}
			}
			else if(Whole2)
			{
				if(Now1)
				{
					UpdataMax(ANS,F5-(A&F5));
					UpdataMax(ANS,(B&F5));
				}
				else
				{
					UpdataMax(ANS,(B&F5)-(A&F5));
				}
			}
			else
			{
				if(Now1)
				{
					if(Now2)
					{
						UpdataMax(ANS,Cx((A&F5)+1,F5,(C&F5)+1,F5));
						UpdataMax(ANS,Cx(1,B&F5,1,D&F5));
						UpdataMax(ANS,Cx(1,B&F5,(C&F5)+1,F5));
						UpdataMax(ANS,Cx((A&F5)+1,F5,1,D&F5));
					}
					else
					{
						UpdataMax(ANS,Cx((A&F5)+1,F5,(C&F5)+1,D&F5));
						UpdataMax(ANS,Cx(1,B&F5,(C&F5)+1,D&F5));
					}
				}
				else if(Now2)
				{
					UpdataMax(ANS,Cx((C&F5)+1,F5,(A&F5)+1,B&F5));
					UpdataMax(ANS,Cx(1,D&F5,(A&F5)+1,B&F5));
				}
				else
				{
					UpdataMax(ANS,Cx((A&F5)+1,B&F5,(C&F5)+1,D&F5));
				}
			}
		}
		if(Get1)
		{
			if(Now1)
			{
				Whole1=1;
			}
			else
			{
				Now1=1;
			}
		}
		if(Get2)
		{
			if(Now2)
			{
				Whole2=1;
			}
			else
			{
				Now2=1;
			}
		}
	}
	cout<<ANS<<endl;
	cin>>A;
	return 0;
}