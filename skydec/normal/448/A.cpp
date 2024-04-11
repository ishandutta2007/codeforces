#include<stdio.h>
using namespace std;
int n,A,B;
int main()
{
    A=0;B=0;
    for(int i=1;i<=3;i++)
    {
            int u;scanf("%d",&u);A+=u;
            }
    for(int i=1;i<=3;i++)
    {
            int u;scanf("%d",&u);B+=u;
            }
    int ans=A/5;
    if(A%5!=0)ans++;
    ans+=B/10;
    if(B%10!=0)ans++;
    scanf("%d",&n);
    if(ans<=n)printf("YES");else printf("NO");
    return 0;
}