#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 1000005
using namespace std;
int n,m,k;
int main()
{
    int cnt=0;
    scanf("%d %d %d",&n,&m,&k);
    int x,num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",&x);
        if(x>m&&x<k) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}