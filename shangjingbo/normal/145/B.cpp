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

int main()
{
    int c4,c7,c47,c74;
    cin >> c4 >> c7 >> c47 >> c74;
    int n=c47+c74+1;//total blocks
    //start with 4
    //x blocks 4  x/(x-1) blocks 7
    if (c47==c74){
        //x-1 blocks 7
        if (n%2==1){
            int b4=(n+1)/2;
            int b7=n-b4;
            if (c4>=b4 && c7>=b7){
                while (c4>b4){
                    printf("4");
                    --c4;
                }
                for (int i=0;i<b4;++i){
                    printf("4");
                    if (i<b7){
                        printf("7");
                        --c7;
                    }
                    if (i+1==b7){
                        while (c7>0){
                            printf("7");
                            --c7;
                        }
                    }
                }
                return 0;
            }
        }
    }else if (c47==c74+1){
        //x blocks 7
        if (n%2==0){
            int b4=n/2;
            int b7=n-b4;
            if (c4>=b4 && c7>=b7){
                while (c4>b4){
                    printf("4");
                    --c4;
                }
                for (int i=0;i<b4;++i){
                    printf("4");
                    if (i<b7){
                        printf("7");
                        --c7;
                    }
                    if (i+1==b7){
                        while (c7>0){
                            printf("7");
                            --c7;
                        }
                    }
                }
                return 0;
            }
        }
    }
    
    //start with 7
    //7-->4 4-->7
    swap(c47,c74);
    swap(c4,c7);
    if (c47==c74){
        //x-1 blocks 7
        if (n%2==1){
            int b4=(n+1)/2;
            int b7=n-b4;
            if (c4>=b4 && c7>=b7){
                for (int i=0;i<b4;++i){
                    printf("7");
                    --c4;
                    if (i+1==b4){
                        while (c4>0){
                            printf("7");
                            --c4;
                        }
                    }
                    while (i==0 && c7>b7){
                        printf("4");
                        --c7;
                    }
                    if (i<b7){
                        printf("4");
                        --c7;
                    }
                }
                return 0;
            }
        }
    }else if (c47==c74+1){
        //x blocks 7
        if (n%2==0){
            int b4=n/2;
            int b7=n-b4;
            //printf("%d %d\n",b4,b7);
            if (c4>=b4 && c7>=b7){
                for (int i=0;i<b4;++i){
                    printf("7");
                    --c4;
                    if (i+1==b4){
                        while (c4>0){
                            printf("7");
                            --c4;
                        }
                    }
                    while (i==0 && c7>b7){
                        printf("4");
                        --c7;
                    }
                    if (i<b7){
                        printf("4");
                        --c7;
                    }
                }
                return 0;
            }
        }
    }
    puts("-1");
    
    return 0;
}