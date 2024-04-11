#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll n,k;
int main()
{
    scanf("%I64d%I64d",&n,&k);
    if(k==1) printf("1\n");
    else if(k==2) printf("%I64d\n",n*(n-1)/2+1);
    else if(k==3) printf("%I64d\n",n*(n-1)*(n-2)/3+n*(n-1)/2+1);
    else if(k==4) printf("%I64d\n",n*(n-1)*(n-2)*(n-3)*3/8+n*(n-1)*(n-2)/3+n*(n-1)/2+1);
    return 0;
}