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

#define maxn 505

int n,score[maxn][maxn];
int out[maxn],key[maxn],ans[maxn];
VI card;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            int x;
            scanf("%d",&x);
            score[i][x]=j;
        }
        ans[i]=n;
        out[i]=-1;
    }
    
    for (int i=0;i<n;++i){
        int x;
        scanf("%d",&x);
        key[x]=i;
    }
    
    for (int i=1;i<=n;++i){
        if (card.size()<2){
            card.push_back(i);
        }else{
            if (key[card[1]]>key[i]){
                card[1]=i;
            }
        }
        if (card.size()==2){
            if (key[card[1]]<key[card[0]]) swap(card[0],card[1]);
        }
        
        for (int j=0;j<n;++j){
            int x=card[0];
            if (x==j+1){
                if (card.size()<2) continue;
                x=card[1];
            }
            if (score[j][x]<ans[j]){
                ans[j]=score[j][x];
                out[j]=i;
            }
        }
    }
    
    for (int i=0;i<n;++i)
        printf("%d ",out[i]);
    
    return 0;
}