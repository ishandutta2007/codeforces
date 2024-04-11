#include<bits/stdc++.h>
using namespace std;

int arr[101010];
int main()
{
    long long int a,b,c,d,e,f,g,h,i,j,k,l,m,n;
    scanf("%lld %lld",&n,&k);
    a=min((long long int)10^8,n);
    for(i=0;i<=n;i++)
    {
        if( ( (i*(i+1) )/2)-(n-i)==k )
        {
            printf("%d",n-i);
            return 0;
        }
    }
}