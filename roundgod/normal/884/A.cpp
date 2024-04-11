#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,t;
int a[MAXN];
int main()
{
    scanf("%d %d",&n,&t);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        t-=86400-x;
        if(t<=0&&ans==0) ans=i+1;
    }
    printf("%d\n",ans);
    return 0;
}