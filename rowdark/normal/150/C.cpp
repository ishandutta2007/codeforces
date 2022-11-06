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

struct LineTree{
    LD Sum,MaxL,MaxR,MaxH;
}LT[1048576];

void Insert(int P,LD Zh){
    P+=524288;
    LT[P].Sum+=Zh;
    LT[P].MaxL=max((long double)0,LT[P].Sum);
    LT[P].MaxR=max((long double)0,LT[P].Sum);
    LT[P].MaxH=max((long double)0,LT[P].Sum);
    while(P>>=1)
    {
        LT[P].Sum+=Zh;
        LT[P].MaxL=max(LT[P*2].MaxL,LT[P*2].Sum+LT[P*2+1].MaxL);
        LT[P].MaxR=max(LT[P*2+1].MaxR,LT[P*2+1].Sum+LT[P*2].MaxR);
        LT[P].MaxH=max(max(LT[P*2].MaxH,LT[P*2+1].MaxH),LT[P*2].MaxR+LT[P*2+1].MaxL);
    }
}

LD MaxL,Ans;

int XX[500001];

LD Sum[500001];

void GetMax(int NL,int NR,int L,int R,int P){
    if(NL==L&&NR==R)
    {
        Ans=max(max(Ans,LT[P].MaxH),MaxL+LT[P].MaxL);
        MaxL=max(MaxL+LT[P].Sum,LT[P].MaxR);
        return;
    }
    int Mid=(NL+NR)>>1;
    if(R<=Mid)
    {
        GetMax(NL,Mid,L,R,P*2);
    }
    else if(Mid<L)
    {
        GetMax(Mid+1,NR,L,R,P*2+1);
    }
    else
    {
        GetMax(NL,Mid,L,Mid,P*2);
        GetMax(Mid+1,NR,Mid+1,R,P*2+1);
    }
}

int N,M,C,i,j,k,l;

LD ANS;

int main(){
//  freopen("a.in","r",stdin);
//  freopen("a.out","w",stdout);
    cin>>N>>M>>C;
    REP_1(i,N) cin>>XX[i],Sum[i]+=(XX[i]-XX[i-1])/2.0;
    REP_1(i,N-1) cin>>j,Sum[i+1]-=C/100.0*j;
    REP_1(i,N) Insert(i,Sum[i]);
    REP_1(i,N) Sum[i]+=Sum[i-1];
    REP_1(i,M)
    {
        cin>>j>>k;
        MaxL=Ans=0;
        GetMax(0,524287,j+1,k,1);
        ANS+=Ans;
    }
    cout<<fixed<<setprecision(10)<<ANS<<endl;
    cin>>N;
}