#include<stdio.h>
using namespace std;
int n;
int data[105];
int ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&data[i]);
    for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++)
    {
            int reu=0;
            for(int k=1;k<i;k++)reu+=data[k];
            for(int k=j+1;k<=n;k++)reu+=data[k];
            for(int k=i;k<=j;k++)reu+=(1-data[k]);
            if(reu>ans)ans=reu;
            }
    printf("%d\n",ans);
    return 0;
}