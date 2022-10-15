#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define MAXN 100
#define INF 100000000
using namespace std;
int n,x,y,z,cnt;
int main()
{
     scanf("%d%d%d",&x,&y,&z);
     cnt=INF;
    for(int i=1;i<=100;i++)
    {
        n=max(x-i,i-x)+max(i-y,y-i)+max(z-i,i-z);
        cnt=min(cnt,n);
    }
    printf("%d\n",cnt);
    return 0;
}