#include<bits/stdc++.h>
#define MAXN 10
using namespace std;
int n,k;
bool a[MAXN],b[MAXN];
int main()
{
    scanf("%d %d",&n,&k);
    memset(a,false,sizeof(a));
    memset(b,false,sizeof(b));
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]=true;
    }
    for(int i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);
        b[x]=true;
    }
    for(int i=0;i<=99;i++)
    {
        int t=i;
        bool f1=false,f2=false;
        while(t>=0)
        {
            int x=t%10;
            if(a[x]) f1=true;
            if(b[x]) f2=true;
            t=t/10;
            if(t==0) break;
        }
        if(f1&&f2)
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}