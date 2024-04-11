#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef unsigned long long ULL;
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

struct Tpoint
{
    double x,y;
    Tpoint(){}
    Tpoint(double _x,double _y){x=_x;y=_y;}
    inline void read(){scanf("%lf%lf",&x,&y);}
    inline void show(){printf("%lf %lf\n",x,y);}
    inline double norm(){ return sqrt( sqr(x)+sqr(y) ); }
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x+b.x,a.y+b.y); }
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x-b.x,a.y-b.y); }
inline Tpoint operator *(const Tpoint &a,const double &b){ return Tpoint(a.x*b,a.y*b); }
inline Tpoint operator /(const Tpoint &a,const double &b){ return Tpoint(a.x/b,a.y/b); }
inline double det(const Tpoint &a,const Tpoint &b){ return a.x*b.y-a.y*b.x; }
inline double dot(const Tpoint &a,const Tpoint &b){ return a.x*b.x+a.y*b.y; }
//=============================================================================================

char s[100005],s1[100005],s2[100005];
int cnt[15],c1[15],c2[15];

inline int solve(char s[])
{
    int id1[100],id2[100];
    int res=0;
    int n=strlen(s);
    for (int i=0;i<n;++i)
        id1[i]=i;
    do{
        for (int i=0;i<n;++i)
            id2[i]=i;
        do{
            int inc=0;
            int cur=0;
            for (int i=0;i<n;++i){
                int st=s[id1[i]]-'0'+s[id2[i]]-'0'+inc;
                if (st%10) break;
                inc=st/10;
                ++cur;
            }
            res=max(res,cur);
        }while (next_permutation(id2,id2+n));
    }while (next_permutation(id1,id1+n));
    return res;
}

int main()
{
    scanf("%s",s);
//printf("best = %d\n",solve(s));
    for (int i=0;s[i];++i){
        ++cnt[s[i]-'0'];
    }
    int n=strlen(s);
    for (int i=0;i<=9;++i)
        c1[i]=c2[i]=cnt[i];
    int cur=0,x,y;
    for (int i=1;i<=9;++i){
        int j=10-i;
        if (c1[i]==0 || c2[j]==0) continue;
        
        --c1[i];
        --c2[j];
        
        int c=1;
        for (int j=0;j<=9;++j){
            c+=min(c1[j],c2[9-j]);
        }
        if (c1[0]>c2[9] && c2[0]>c1[9]){
            c+=min(c1[0]-c2[9],c2[0]-c1[9]);
        }
        
        if (c>cur){
            cur=c;
            x=i;
            y=j;
        }
        
        ++c1[i];
        ++c2[j];
    }
    if (cur){
        n=strlen(s);
        --c1[x];
        --c2[y];
        while (c1[0]>c2[9] && c2[0]>c1[9]){
            --c1[0];
            --c2[0];
            s1[n-1]='0';
            s2[n-1]='0';
            --n;
        }
        s1[n-1]=x+'0';
        s2[n-1]=y+'0';
        --n;
        
        for (int i=0;i<=9;++i)
        while (c1[i]>0 && c2[9-i]>0){
            --c1[i];
            --c2[9-i];
            s1[n-1]=i+'0';
            s2[n-1]=9-i+'0';
            --n;
        }
    }
    while (c1[0] && c2[0]){
        --c1[0];--c2[0];
        s1[n-1]=s2[n-1]='0';
        --n;
    }
    int bak=n;
    for (int i=0;i<=9;++i)
    while (c1[i]>0){
        s1[n-1]=i+'0';
        --c1[i];
        --n;
    }
    n=bak;
    for (int i=0;i<=9;++i)
    while (c2[i]>0){
        s2[n-1]=i+'0';
        --n;
        --c2[i];
    }
    
    puts(s1);
    puts(s2);
    
    return 0;
}