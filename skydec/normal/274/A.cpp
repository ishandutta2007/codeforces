#include<stdio.h>
#include<map>
#include<algorithm>
#define MAXN 110000
using namespace std;
int data[MAXN];int n;
map<int,int>ls;
int main()
{
    int k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&data[i]);
    sort(data+1,data+1+n);
    int ans=0;
    for(int i=1;i<=n;i++)
    if((data[i]%k)||(ls[data[i]/k]==0))
    ans++,ls[data[i]]=1;
    printf("%d\n",ans);
    return 0;
}