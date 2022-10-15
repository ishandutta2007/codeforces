#include<bits/stdc++.h>
#define MAXN 500
using namespace std;
int k;
int a[MAXN];
int main()
{
    scanf("%d",&k);
    if(k==0)
    {
        printf("a\n");
        return 0;
    }
    int s=0;
    a[0]=0;
    int save=0;
    for(int i=1;s<=100001;i++)
    {
        a[i]=s;
        s+=i;
        save=i;
    }
    int cnt=0;
    while(k>0)
    {
        int x=(int)(upper_bound(a,a+save,k)-a)-1;
        k-=a[x];
        for(int i=0;i<x;i++)
            printf("%c",(char)cnt+97);
        cnt++;
    }
    return 0;
}