#include<stdio.h>
#include<math.h>

const long long int c=1000000007;

mod(long long int n)
{
    long long int x;
    if(n<15) {
        x=pow(2,n);
        return x;
    }
    if(n%2==0) {
        x=mod(n/2);
        x=x*x;
        x=x%c;
        return x;
    }
    if(n%2==1) {
        x=mod(n/2);
        x=x*x;
        x=x*2;
        x=x%c;
        return x;
    }
}

main()
{
    long long int x,k,i,a,q,y,z,ans;
    scanf("%I64d %I64d", &x, &k);
    z=mod(k);
    y=(2*x-1)%c;
    ans=(z*y+1)%c;
    if(x==0) ans=0;
    printf("%I64d\n", ans);

}