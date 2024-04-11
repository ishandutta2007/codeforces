#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,l,u,d,r;
char a[MAXN];
int main()
{
    scanf("%d",&n);
    scanf("%s",a);
    int x=strlen(a);
    l=u=d=r=0;
    for(int i=0;i<x;i++)
    {
        if(a[i]=='L') l++;
        if(a[i]=='U') u++;
        if(a[i]=='D') d++;
        if(a[i]=='R') r++;
    }
    printf("%d\n",min(u,d)*2+min(l,r)*2);
    return 0;
}