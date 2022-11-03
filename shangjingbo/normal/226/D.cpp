#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<string> VS;

inline void print(int a[],int n)
{
    int cnt=0;
    for (int i=0;i<n;++i) cnt+=a[i];
    
    printf("%d",cnt);
    for (int i=0;i<n;++i)if (a[i]) printf(" %d",i+1);
    puts("");
}

const int maxn  =   105;

int n,m,a[maxn][maxn];
int rsel[maxn],csel[maxn],rs[maxn],cs[maxn];
int rid[maxn],cid[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    //n=m=100;
    //srand(time(0)^15126513);
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            scanf("%d",&a[i][j]);
            //a[i][j]=rand()%2*2-1;
        }
    }
    
    memset(rs,0,sizeof(rs));
    memset(cs,0,sizeof(cs));
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cs[j]+=a[i][j];
            rs[i]+=a[i][j];
        }
    }
    for (int i=0;i<n;++i){
        rid[i]=i;
        rsel[i]=0;
    }
    for (int i=0;i<m;++i){
        cid[i]=i;
        csel[i]=0;
    }
    bool change=true;
    while (change){
        change=false;
        random_shuffle(rid,rid+n);
        random_shuffle(cid,cid+m);
        if (rand()&1){
            for (int i=0;i<n;++i){
                int r=rid[i];
                if (rs[r]<0){
                    rsel[r]^=1;
                    change=true;
                    for (int j=0;j<m;++j){
                        cs[j]-=a[r][j];
                        rs[r]-=a[r][j];
                        a[r][j]*=-1;
                        cs[j]+=a[r][j];
                        rs[r]+=a[r][j];
                    }
                }
            }
            for (int i=0;i<m;++i){
                int c=cid[i];
                if (cs[c]<0){
                    csel[c]^=1;
                    change=true;
                    for (int j=0;j<n;++j){
                        cs[c]-=a[j][c];
                        rs[j]-=a[j][c];
                        a[j][c]*=-1;
                        cs[c]+=a[j][c];
                        rs[j]+=a[j][c];
                    }
                }
            }
        }else{
            for (int i=0;i<m;++i){
                int c=cid[i];
                if (cs[c]<0){
                    csel[c]^=1;
                    change=true;
                    for (int j=0;j<n;++j){
                        cs[c]-=a[j][c];
                        rs[j]-=a[j][c];
                        a[j][c]*=-1;
                        cs[c]+=a[j][c];
                        rs[j]+=a[j][c];
                    }
                }
            }
            for (int i=0;i<n;++i){
                int r=rid[i];
                if (rs[r]<0){
                    rsel[r]^=1;
                    change=true;
                    for (int j=0;j<m;++j){
                        cs[j]-=a[r][j];
                        rs[r]-=a[r][j];
                        a[r][j]*=-1;
                        cs[j]+=a[r][j];
                        rs[r]+=a[r][j];
                    }
                }
            }
        }
    }
    print(rsel,n);
    print(csel,m);
    
    return 0;
}