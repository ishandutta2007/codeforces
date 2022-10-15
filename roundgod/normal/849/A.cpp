#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;
int n;
int f;
int main()
{
    f=1;
    scanf("%d",&n);
    if(n%2==0) f=0;
    int x;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if((i==0||i==n-1)&&(x%2==0)) f=0;
    }
    if(f) printf("Yes\n"); else printf("No\n");
    return 0;
}