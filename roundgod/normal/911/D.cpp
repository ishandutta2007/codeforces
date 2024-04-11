#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,m,k;
int a[MAXN];
bool f;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[j]<a[i]) cnt++;
    if(cnt&1) f=true; else f=false;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int x=(r-l)*(r-l+1)/2;
        if(x&1) f=!f;
        if(f) puts("odd"); else puts("even");
    }
    return 0;
}