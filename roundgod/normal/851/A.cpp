#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;
int n,k,t;
int main()
{
    scanf("%d %d %d",&n,&k,&t);
    if(t<=k) printf("%d\n",t);
    else if (t<=n) printf("%d\n",k);
    else printf("%d\n",k-t+n);
    return 0;
}