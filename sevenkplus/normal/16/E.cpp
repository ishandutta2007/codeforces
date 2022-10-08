#include<cstdio>
double f[1<<18],a[18][18];
int n,p[20];
int main()
{
    int i,j,k,l;
    for(i=0;i<20;i++)
        p[i]=1<<i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%lf",&a[i][j]);
    int P=1<<n;
    f[P-1]=1;
    for(i=P-1;i>0;i--)
    {
        for(l=j=0;j<n;j++)
            if(i&p[j])
                l++;
        l=l*(l-1)/2;
        for(j=0;j<n;j++)if(i&p[j])
            for(k=j+1;k<n;k++)if(i&p[k])
                f[i^p[k]]+=f[i]*a[j][k]/l,f[i^p[j]]+=f[i]*a[k][j]/l;
    }
    for(int i=0;i<n;i++)
    {
        printf("%.12lf",f[1<<i]);
        if(i==n-1)
            puts("");
        else
            printf(" ");
    }
    return 0;
}