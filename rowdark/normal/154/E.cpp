#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<iomanip>

using namespace std;

#define REP_0(i,N) for(int i=0;i<N;++i)
#define REP_3(i,a,b) for(int i=(a);i<=(b);++i)
#define DOW_0(i,N) for(int i=(N)-1;i>-1;--i)
#define X first
#define Y second
#define MP make_pair
#define PI 3.1415926535897932384626433832795

typedef long double LD;

#define MAXN 100000

pair<LD,LD> P[MAXN+5];

bool In[MAXN+5];
int Convex[MAXN+5];

int Circle[MAXN+5];

int H,T,Lc;

LD r;

int N;

pair<LD,LD> operator +(pair<LD,LD> A,pair<LD,LD> B){
	return pair<LD,LD>(A.X+B.X,A.Y+B.Y);
}

pair<LD,LD> operator -(pair<LD,LD> A,pair<LD,LD> B){
	return pair<LD,LD>(A.X-B.X,A.Y-B.Y);
}

pair<LD,LD> operator *(pair<LD,LD> A,LD B){
	return pair<LD,LD>(A.X*B,A.Y*B);
}

pair<LD,LD> operator /(pair<LD,LD> A,LD B){
	return pair<LD,LD>(A.X/B,A.Y/B);
}

LD MySqrt(LD A){
	if(A<=1e-6) return 0;
	return sqrt(A);
}

LD Mode2(pair<LD,LD> A){
	return MySqrt(A.X*A.X+A.Y*A.Y);
}

LD operator ^(pair<LD,LD> A,pair<LD,LD> B){
	return A.X*B.Y-A.Y*B.X;
}

bool Cross(pair<LD,LD> A,pair<LD,LD> B,pair<LD,LD> C){
	return ((B-A)^(C-A))<=0;
}

pair<LD,LD> GetO(pair<LD,LD> A,pair<LD,LD> B){
	pair<LD,LD> Vy(A.Y-B.Y,B.X-A.X);
	LD M=Mode2(Vy);
	Vy=Vy/M*MySqrt(r*r-M*M/4);
	pair<LD,LD> O=(A+B)/2+Vy;
	return O;
}

bool InCircle(pair<LD,LD> A,pair<LD,LD> B,pair<LD,LD> C){
	pair<LD,LD> O=GetO(A,C);
	return Mode2(O-B)<r+1e-6;
}

LD GetAns(pair<LD,LD> A,pair<LD,LD> B){
	pair<LD,LD> O=GetO(A,B);
	A=A-O,B=B-O;
	LD x=atan2(A.Y,A.X),y=atan2(B.Y,B.X);
	if(y<x) y+=2*PI;
	return ((y-x)*r*r-(A^B))/2;
}

LD Ans;

int main() {
//    freopen("a.in", "r", stdin);
 //   freopen("a.out", "w", stdout);
    cin>>N>>r;
    if(N==1)
    {
		cout<<"0.0"<<endl;
		return 0;
	}
    REP_0(i,N) cin>>P[i].X>>P[i].Y;
    sort(P,P+N);
    T=-1;
    REP_0(i,N)
    {
		while(H<T&&Cross(P[Convex[T-1]],P[Convex[T]],P[i]))
		{
			In[Convex[T]]=0;
			--T;
		}
		In[i]=1;
		Convex[++T]=i;
	}
	In[0]=0;
	H=T;
	DOW_0(i,N)
	{
		if(!In[i])
		{
			while(H<T&&Cross(P[Convex[T-1]],P[Convex[T]],P[i]))
			{
				In[Convex[T]]=0;
				--T;
			}
			In[i]=1;
			Convex[++T]=i;
		}
	}
	N=T;
	H=0,T=-1;
	REP_0(i,N)
	{
		while(H<T&&InCircle(P[Circle[T-1]],P[Circle[T]],P[Convex[i]]))
		{
			--T;
		}
		Circle[++T]=Convex[i];
	}
	bool Ch=1;
	while(H+1!=T&&Ch)
	{
		Ch=0;
		while(H+1!=T&&InCircle(P[Circle[T]],P[Circle[H]],P[Circle[H+1]])) ++H,Ch=1;
		while(H+1!=T&&InCircle(P[Circle[T-1]],P[Circle[T]],P[Circle[H]])) --T,Ch=1;
	}
	Circle[T+1]=Circle[H];
	REP_3(i,H,T)
	{
		Ans+=(P[Circle[i]]^P[Circle[i+1]])/2+GetAns(P[Circle[i]],P[Circle[i+1]]);
	}
	cout<<fixed<<setprecision(10)<<Ans<<endl;
	cin>>Ans;
    return 0;
}