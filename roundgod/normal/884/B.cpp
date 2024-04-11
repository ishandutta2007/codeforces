#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,x;
int a[MAXN];
int main()
{
    scanf("%d %d",&n,&x);
    int s=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s+=a[i];
    }
    if(s+n-1==x) printf("YES\n"); else printf("NO\n");
    return 0;
}