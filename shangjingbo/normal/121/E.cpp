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

const int blockSize =   100000/81+1;
const int blockNum  =   1300;
const int maxn      =   100000;

bool isLucky[10000];
int n,m;
int a[maxn],shift[blockNum],ans[blockNum];
int cnt[blockNum][10005];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    int len=0,lucky[100];
    memset(isLucky,false,sizeof(isLucky));
    for (int l=1;l<=4;++l){
        for (int i=0;i<1<<l;++i){
            int x=0;
            for (int j=0;j<l;++j)
            if ((i>>j)&1) x=x*10+4;
            else x=x*10+7;
            isLucky[x]=true;
            lucky[len++]=x;
        }
    }
    sort(lucky,lucky+len);
    reverse(lucky,lucky+len);
    
    scanf("%d%d",&n,&m);
    int B=(n-1)/blockSize+1;
    memset(shift,0,sizeof(shift));
    memset(ans,0,sizeof(ans));
    memset(cnt,0,sizeof(cnt));
    
    int id=0;
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
        if ((id+1)*blockSize==i) ++id;
        ++cnt[id][a[i]];
        if (isLucky[a[i]]) ++ans[id];
    }
    
    while (m--){
        char op[10];
        scanf("%s",op);
        int l,r,d;
        if (op[0]=='c'){
            scanf("%d%d",&l,&r);
            --l;--r;
            int out=0;
            int s=l%blockSize,lid=l/blockSize;
            if (s){
                s=blockSize-s;
                while (l<=r && s){
                    --s;
                    if (isLucky[a[l]+shift[lid]]) ++out;
                    ++l;
                }
                ++lid;
            }
            int t=r%blockSize,rid=r/blockSize;
            if (t!=blockSize-1){
                while (l<=r && t>=0){
                    --t;
                    if (isLucky[a[r]+shift[rid]]) ++out;
                    --r;
                }
                --rid;
            }
            
            if (l<=r){
                for (int i=lid;i<=rid;++i) out+=ans[i];
            }
            
            printf("%d\n",out);
        }else{
            scanf("%d%d%d",&l,&r,&d);
            --l;--r;
            int s=l%blockSize,lid=l/blockSize;
            if (s){
                s=blockSize-s;
                while (l<=r && s){
                    --s;
                    if (isLucky[a[l]+shift[lid]]) --ans[lid];
                    --cnt[lid][a[l]];
                    
                    a[l]+=d;
                    if (isLucky[a[l]+shift[lid]]) ++ans[lid];
                    ++cnt[lid][a[l]];
                    ++l;
                }
                ++lid;
            }
            int t=r%blockSize,rid=r/blockSize;
            if (t!=blockSize-1){
                while (l<=r && t>=0){
                    --t;
                    if (isLucky[a[r]+shift[rid]]) --ans[rid];
                    --cnt[rid][a[r]];
                    a[r]+=d;
                    if (isLucky[a[r]+shift[rid]]) ++ans[rid];
                    ++cnt[rid][a[r]];
                    --r;
                }
                --rid;
            }
            
            if (l<=r){
                for (int i=lid;i<=rid;++i){
                    shift[i]+=d;
                    int delta=shift[i];
                    ans[i]=0;
                    for (int j=0;j<len;++j){
                        if (lucky[j]-delta>=0){
                            ans[i]+=cnt[i][lucky[j]-delta];
                        }else break;
                    }
                }
            }
        }
    }
    
    //printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
    
    return 0;
}