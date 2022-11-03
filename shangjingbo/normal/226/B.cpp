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

long long ans[100005],sum[100005];
int a[100005],n;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    reverse(a,a+n);
    
    sum[0]=0;
    for (int i=0;i<n;++i){
        sum[i+1]=sum[i]+a[i];
    }
    
    int sqrtn=(int)sqrt(n);
    int q,k;
    memset(ans,-1,sizeof(ans));
    for (scanf("%d",&q);q--;){
        scanf("%d",&k);
        if (k<=sqrtn && ans[k]!=-1) printf("%I64d ",ans[k]);
        else{
            long long res=0;
            long long len=1;
            for (long long i=1,x=1;i<n;i+=len,++x){
                len*=k;
                res+=x*(sum[min(i+len,(long long)n)]-sum[i]);
            }
            if (k<=sqrtn) ans[k]=res;
            printf("%I64d ",res);
        }
    }
    
    return 0;
}