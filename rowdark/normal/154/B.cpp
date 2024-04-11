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
#define DOW_0(i,n) for(i=(n)-1;-1<i;--i)
#define DOW_1(i,n) for(i=(n);0<i;--i)
#define DOW_2(i,a,b) for(i=(b);(a)<i;--i)
#define DOW_3(i,a,b) for(i=(b);(a)<=i;--i)
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

int Su[100001],From[100001],Last,N,M,L,G;
int Cc2[100001];
bool In[100001];
char S[10];

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	REP_3(i,2,100000)
	{
		if(!From[i]) Su[++Last]=i,From[i]=Last;
		REP_1(j,From[i])
		{
			if(i*Su[j]>100000)
			{
				break;
			}
			From[i*Su[j]]=j;
		}
	}
	cin>>N>>M;
	while(M--)
	{
		cin>>S>>N;
		if(S[0]=='-')
		{
			if(In[N])
			{
				cout<<"Success\n";
				In[N]=0;
				while(N!=1)
				{
					L=Su[From[N]];
					Cc2[From[N]]=0;
					while(N%L==0) N/=L; 
				}
			}
			else
			{
				cout<<"Already off\n";
			}
		}
		else
		{
			if(In[N])
			{
				cout<<"Already on\n";
			}
			else
			{
				G=N;
				while(G!=1)
				{
					L=Su[From[G]];
					if(Cc2[From[G]]!=0) break;
					while(G%L==0) G/=L;
				}
				if(G!=1)
				{
					cout<<"Conflict with "<<Cc2[From[G]]<<endl;
				}
				else
				{
					cout<<"Success\n";
					G=N;
					In[N]=1;
					while(G!=1)
					{
						L=Su[From[G]];
						Cc2[From[G]]=N;
						while(G%L==0) G/=L; 
					}
				}
			}
		}
	}
	cin>>N;
	return 0;
}