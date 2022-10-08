#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010],n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int S=0;
        for(int j=1;j*j<=x;j++)
            if(x%j==0)
            {
                if(a[j]<i-y)S++;
                a[j]=i;
                if(j*j!=x)
                {
                    if(a[x/j]<i-y)S++;
                    a[x/j]=i;
                }
            }
        printf("%d\n",S);
    }
    return 0;
}