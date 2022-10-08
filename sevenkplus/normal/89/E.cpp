#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010],b[2010],n,S=1000000007,W;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    while(!a[n-1])n--;
    for(int w=0;w<n;w++)
    {
        for(int i=0;i<n;i++)b[i]=a[i];
        for(int i=w;i<n;i++)if(b[i])b[i]--;
        int w0=0,w1=0;
        for(int i=0,la=0;i<n;i++)
            w0+=max(0,b[i]-la),
            w1+=b[i],la=b[i];
        int T=2*n+2+(n-w)+3*w1+2*w0;
        for(int i=0;i<n;i++)
        if(T<S)S=T,W=w;
    }
    for(int i=W;i<n;i++)if(a[i])a[i]--;
    for(int i=0;i<n;i++)
    {
        while(a[i])
        {
            int j=i;
            while(a[j])a[j]--,j++;
            for(int k=0;k<j-i;k++)printf("AR");
            printf("A");
            for(int k=0;k<j-i;k++)printf("L");
            printf("A");
        }
        printf("AR");
    }
    printf("A");
    for(int i=W;i<n;i++)printf("L");
    printf("A");puts("");
    return 0;
}