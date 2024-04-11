#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#define MAXN 1005
#define INF 10000
using namespace std;
int n,m;
char a[MAXN],b[MAXN];
int main()
{
    scanf("%d %d",&n,&m);
    scanf("%s",a);
    scanf("%s",b);
    int ans=INF;
    int t=0;
    for(int i=0;i<=m-n;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
            if(a[j]!=b[j+i]) cnt++;
        if(cnt<ans)
        {
            ans=cnt;
            t=i;
        }
    }
    printf("%d\n",ans);
    for(int j=0;j<n;j++)
         if(a[j]!=b[j+t])printf("%d ",j+1);
    return 0;
}