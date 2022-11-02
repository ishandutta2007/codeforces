#include<cstdio>
#include<algorithm>
#include<cstdlib>

int a[111111];
int v[111111];
long long s[111111];

int main()
{
    srand(19951112);
    long long r=0,t=0;
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        r+=1LL*a[i]*i;
        v[i]=1;
        s[i]=s[i-1]+a[i];
    }
    for(i=0;i<1000;i++)
    {
        k=1;
        t=0;
        for(j=1;j<=n;j++)
        {
            if(v[j]&&1LL*a[j]*k+s[n]-s[j]<0)v[j]=0;
            if(!v[j]&&1LL*a[j]*k+s[n]-s[j]>=0)v[j]=1;
            if(v[j])
            {
                s[j]=s[j-1]+a[j];
                t+=1LL*a[j]*k;
                k++;
            }
            else s[j]=s[j-1];
        }
        r=std::max(r,t);
    }
    printf("%I64d",r);
}