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

pair<int,int> P[201];
int N;

int dp[2002];

const int minv=1U<<31;

struct node{
    int l,r,st,ed;
    node(){}
    node(int l,int r,int st,int ed):l(l),r(r),st(st),ed(ed){}
};

node fdp[2][101][101];

int solve(int x,int st,int flag){
    for(int i=1;i<=N;++i) dp[i]=minv;
    dp[x]=st+P[x].Y;
    for(int i=1;i<x;++i){
        if(P[i].X>=st) UpdateMax(dp[x],P[i].X+P[i].Y);
    }
    for(int i=x;i<=N;++i) if(dp[i]!=minv){
        int mt=dp[i];
        for(int j=i+1;j<=N;++j){
            if(P[j].X<=dp[i]) UpdateMax(dp[j],max(mt,P[j].X+P[j].Y));
            if(P[j].X-P[j].Y<=dp[i]) UpdateMax(dp[j],max(mt,P[j].X));
            mt=max(mt,P[j].X+P[j].Y);
        }
    }
    int ret=0;
    for(int i=x;i<=N;++i){
        if(dp[i]!=minv){
            fdp[flag][x][i]=node(x,i,st,dp[i]);
        }
        else fdp[flag][x][i]=node(minv,minv,minv,minv);
    }
    return ret;
}

vector<int> V;

int main(){
    scanf("%d",&N);
    for(int i=1;i<=N;++i){
        scanf("%d%d",&P[i].X,&P[i].Y);
    }
    sort(P+1,P+N+1);
    for(int i=1;i<=N;++i){
        solve(i,P[i].X,0);
        V.push_back(P[i].X+P[i].Y);
        solve(i,P[i].X-P[i].Y,1);
        V.push_back(P[i].X);
    }
    V.push_back(minv);
    sort(V.begin(),V.end());
    V.resize(unique(V.begin(),V.end())-V.begin());
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=N;++i){
        //flag 1
        {
            int extra=0;
            for(int j=0;V[j]<P[i].X-P[i].Y;++j){
                UpdateMax(extra,dp[j]);
            }
            for(int j=i;j<=N;++j) if(fdp[1][i][j].l!=minv){
                UpdateMax(dp[LB(V.begin(),V.end(),fdp[1][i][j].ed)-V.begin()],extra+fdp[1][i][j].ed-fdp[1][i][j].st);
            }
        }
        //flag 0
        {
            int extra=0;
            for(int j=0;V[j]<P[i].X;++j){
                UpdateMax(extra,dp[j]);
            }
            for(int j=i;j<=N;++j) if(fdp[0][i][j].l!=minv){
                UpdateMax(dp[LB(V.begin(),V.end(),fdp[0][i][j].ed)-V.begin()],extra+fdp[0][i][j].ed-fdp[0][i][j].st);
            }
        }
    }
    int ans=0;
    for(int i=0;i<int(V.size());++i){
        UpdateMax(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}