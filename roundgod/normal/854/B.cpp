#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;
int n,k;
int main()
{
    scanf("%d %d",&n,&k);
    if(n==k||k==0) printf("0 "); else printf("1 ");
    if(k<=n/3) printf("%d\n",2*k);
    else printf("%d\n",n-k);
    return 0;
}