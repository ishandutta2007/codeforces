#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int a[MAXN];
int main()
{
    scanf("%d",&n);
    if(n%10<=5) printf("%d\n",n-n%10); else printf("%d\n",n+10-n%10);
    return 0;
}