#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
using namespace std;

#define PB push_back
#define MP make_pair

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

struct Tpoint
{
    double x,y;
    Tpoint(){}
    Tpoint(double a,double b){x=a;y=b;}
    inline double norm(){return sqrt(sqr(x)+sqr(y));}
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){return Tpoint(a.x+b.x,a.y+b.y);}
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){return Tpoint(a.x-b.x,a.y-b.y);}
inline Tpoint operator *(const Tpoint &a,const double &b){return Tpoint(a.x*b,a.y*b);}
inline Tpoint operator /(const Tpoint &a,const double &b){return Tpoint(a.x/b,a.y/b);}
inline double dot(const Tpoint &a,const Tpoint &b){return a.x*b.x+a.y*b.y;}
inline double det(const Tpoint &a,const Tpoint &b){return a.x*b.y-a.y*b.x;}
//==============================================================================================

const int maxn  =   1000005;
const int maxq  =   10005;

int Q,cnt[maxq],out[maxq],next[maxn][26];
char s[maxn];
map<int,int> hash;

int main()
{
    scanf("%s",s);
    int Q;
    scanf("%d",&Q);
    for (int i=0;i<Q;++i){
        char tmp[100];
        scanf("%s",tmp);
        int stat=0;
        for (int j=0;tmp[j];++j)
            stat|=1<<tmp[j]-'a';
        if (!hash.count(stat)) hash[stat]=hash.size()-1;
        out[i]=stat;
    }
    int n=strlen(s);
    memset(next[n],-1,sizeof(next[n]));
    for (int i=n-1;i>=0;--i){
        memcpy(next[i],next[i+1],sizeof(next[i]));
        next[i][s[i]-'a']=i;
    }
    
    for (int i=0;i<n;++i){
        vector<PII> a;
        int stat=0;
        for (int j=0;j<26;++j)
        if (next[i][j]!=-1){
            a.PB(MP(next[i][j],j));
            stat|=1<<j;
        }
        sort(a.begin(),a.end());
        
        for (int j=(int)a.size()-1;j>=0;--j){
            if (i==0 || !((stat>>s[i-1]-'a')&1)){
                if (hash.count(stat)) ++cnt[hash[stat]];
            }
            stat-=1<<a[j].second;
        }
    }
    
    for (int i=0;i<Q;++i)
        printf("%d\n",cnt[hash[out[i]]]);
    

    return 0;
}