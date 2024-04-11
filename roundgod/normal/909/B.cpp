#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
int main()
{
    scanf("%d",&n);
    if(n%2==1) printf("%d\n",(n+1)*(n+1)/4); else printf("%d\n",n/2*(n/2+1));
    return 0;
}