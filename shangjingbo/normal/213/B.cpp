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

const int base  =   1000000007;
const int maxn  =   105;

int C[maxn][maxn],f[11][maxn];

inline void Plus(int &a,int b)
{
    a+=b;
    if (a>=base) a-=base;
}

int main()
{
    int n,cnt[11];
    scanf("%d",&n);
    for (int i=0;i<=101;++i){
        C[i][0]=1;
        for (int j=1;j<=i;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%base;
    }
    for (int i=0;i<10;++i) scanf("%d",&cnt[i]);
    
    memset(f,0,sizeof(f));
    f[10][0]=1;
    for (int i=9;i>=0;--i){
        for (int j=cnt[i];j<=n;++j)
            for (int k=0;k+j<=n;++k)
            if (f[i+1][k]){
//printf("%d %d %d\n",i+1,k,f[i+1][k]);
                //x_0+x_1+..x_k=j
                LL mul=C[k+j][k];
                if (i==0){
                    if (k==0) mul=0;
                    else mul=C[k+j-1][k-1];
                }
                Plus(f[i][j+k],(int)(f[i+1][k]*mul%base));
            }
    }
    
    int ans=0;
    for (int i=1;i<=n;++i)
        Plus(ans,f[0][i]);
    printf("%d\n",ans);
    
    return 0;
}