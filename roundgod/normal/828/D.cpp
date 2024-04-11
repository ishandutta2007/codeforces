#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,k,mem[MAXN];
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++)
        mem[i]=1;
    if((n-1)%k==0) printf("%d\n",2*(n-1)/k);
    else if((n-1)%k==1) printf("%d\n",2*(n-2)/k+1);
    else printf("%d\n",2*((n-1)/k)+2);
    for(int i=2;i<=n-k;i++)
    {
        printf("%d %d\n",mem[(i-2)%k],i);
        mem[(i-2)%k]=i;
    }
    for(int i=0;i<k;i++)
    {
        printf("%d %d\n",mem[i],n-k+1+i);
    }
    return 0;
}