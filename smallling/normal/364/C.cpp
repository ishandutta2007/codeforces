#include<cstdio>

using namespace std;

int n,cnt;
int flag[1000010],a[1000010];

int main()
{
    scanf("%d",&n);
    for(int i=2;i<=1000000&&cnt<n;i++)
        if(!flag[i])
        {
            a[++cnt]=i;
            for(int j=i+i;j<=1000000;j+=i)
                flag[j]=1;
            for(int j=1;j<=cnt;j++)
                if(1ll*a[j]*i<=2*n*n)a[++cnt]=a[j]*i;
        }
    for(int i=cnt;i>cnt-n;i--)printf("%d ",a[i]);
}