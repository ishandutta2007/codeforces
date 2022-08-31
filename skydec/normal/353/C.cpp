#include<stdio.h>
#define MAXN 110000
using namespace std;
int sum[MAXN];int data[MAXN];
char str[MAXN];
int n;int ans=0;
void Max(int &a,int b){if(b>a)a=b;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            scanf("%d",&data[i]);
            sum[i]=data[i]+sum[i-1];
            }
    scanf("%s",str+1);
    int tot=0;
    for(int i=n;i>=1;i--)
    {
            if(str[i]=='1')Max(ans,tot+sum[i-1]),tot+=data[i];
            }
    Max(ans,tot);
    printf("%d\n",ans);
    return 0;
}