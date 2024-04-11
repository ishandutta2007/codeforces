#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&k);
        bool f=false;
        for(int i=0;i*3<=k;i++)
            if((k-i*3)%7==0) {f=true; break;}
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}