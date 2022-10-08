#include<cstdio>
#include<algorithm>
using namespace std;
int a[4];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;scanf("%d",&n);a[n]=1;
    int x,y;
    scanf("%d%d",&x,&y),swap(a[x],a[y]);
    scanf("%d%d",&x,&y),swap(a[x],a[y]);
    scanf("%d%d",&x,&y),swap(a[x],a[y]);
    for(int i=1;i<=3;i++)if(a[i])printf("%d\n",i);
    return 0;
}