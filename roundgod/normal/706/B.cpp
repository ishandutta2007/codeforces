#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXN 100000
#define INF 10000000
using namespace std;
int n,q;
int fee[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&fee[i]);
    }
    sort(fee,fee+n);
    scanf("%d",&q);
    int x;
    for(int i=0;i<q;i++)
    {
        scanf("%d",&x);
        printf("%d\n",upper_bound(fee,fee+n,x)-fee);
    }
    return 0;
}