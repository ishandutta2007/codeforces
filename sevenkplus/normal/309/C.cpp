#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000010
int n,m,a[N],b[40];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for(int i=0,x;i<m;i++)scanf("%d",&x),b[x]++;
    int S=0;
    for(int i=0;i<30;i++)
    {
        int t=b[i];
        for(int j=0;j<n&&t>0;j++)
            if(a[j]&1)
            {
                S++,t--,a[j]--;
            }
        for(int j=0;j<n&&t>0;j++)
        {
            while(a[j]>0&&t>0)a[j]--,t--,S++;
        }
        for(int j=0;j<n;j++)a[j]/=2;
    }
    printf("%d\n",S);
    return 0;
}