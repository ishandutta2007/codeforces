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

const int maxn  =   5005;

int n,a[maxn];
long long sum[maxn];
int f[maxn][maxn];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    int ans=1;
    for (int i=1;i<=n;++i){
        int k=i-1;
        int ma=-1000000000;
        if (i==1) ma=0;
        for (int j=i;j<=n;++j){
            while (k>0 && sum[i-1]-sum[max(0,k-1)]<=sum[j]-sum[i-1]){
                ma=max(f[k][i-1],ma);
                --k;
            }
            f[i][j]=ma+1;
        }
        ans=max(ans,f[i][n]);
    }
    printf("%d\n",n-ans);
    
    return 0;
}