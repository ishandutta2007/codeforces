#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAXN 100010
#define INF 1000000001
using namespace std;
int a[4],num[MAXN],n;
int main()
{
    fill(a,a+3,INF);
    scanf("%d",&n);
    int cnt=0,x;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(num[i]!=a[0]&&num[i]!=a[1]&&num[i]!=a[2])
        {
            cnt++;
            a[cnt-1]=num[i];
        }
        if(cnt>3) break;
    }
    if(cnt==1||cnt==2) printf("YES\n");
    else if(cnt==4) printf("NO\n");
    else
    {
        sort(a,a+3);
        if(a[0]+a[2]==2*a[1]) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}