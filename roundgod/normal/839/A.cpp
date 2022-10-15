#include<bits/stdc++.h>
#define MAXN 10000
using namespace std;
int n,k;
int main()
{
    scanf("%d %d",&n,&k);
    int s=0,cnt=0,f=1,t=-1;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        s+=x;
        cnt+=min(s,8);
        s-=min(s,8);
        if(cnt>=k&&f) {t=i+1; f=0;}
    }
    if(t==-1) printf("-1\n"); else printf("%d\n",t);
    return 0;
}