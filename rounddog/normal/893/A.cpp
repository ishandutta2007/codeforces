#include<bits/stdc++.h>
#define maxn 200005

using namespace std;

int a,b;
bool f;

int main()
{
    int n,k;
    scanf("%d",&n);
    a=1;b=2;f=true;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        if (a+b+k==6) {f=false;break;}
        else if (a==k) b=6-a-b; else a=6-a-b;
    }
    if (f) printf("YES\n"); else printf("NO\n");return 0;
}