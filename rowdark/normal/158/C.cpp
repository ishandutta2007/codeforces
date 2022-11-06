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

class Path{
	private:
		string S[10001];
		int Len;
	public:
		void Print()
		{
			cout<<'/';
			REP_0(i,Len) cout<<S[i]<<'/';
			cout<<endl;
		}
		void Change(vector<string> SS,bool Reset)
		{
			if(Reset) Len=0;
			REP_0(i,(int)SS.size())
			{
				if(SS[i]=="..")
				{
					--Len;
				}
				else
				{
					S[Len++]=SS[i];
				}
			}
		}
}P;

int N,M;

bool Reset;

vector<string> Vs;

string ML;

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>N;
	while(N--)
	{
		cin>>ML;
		if(ML=="pwd")
		{
			P.Print();
		}
		else
		{
			cin>>ML,Vs.clear();
			if(ML[ML.length()-1]!='/') ML+='/';
			if(ML[0]=='/') Reset=1,ML=ML.substr(1,ML.length()-1);
			else Reset=0;
			while(ML.length()!=0)
			{
				M=ML.find('/');
				Vs.PB(ML.substr(0,M));
				ML=ML.substr(M+1,ML.length()-M+1);
			}
			P.Change(Vs,Reset);
		}
	}
	cin>>N;
	return 0;
}