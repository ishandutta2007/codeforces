#include<cstdio>
#include<algorithm>
using namespace std;
pair<int,int>a[20];
int main()
{
    int n,m,s=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d%d",&a[i].second,&a[i].first);
    sort(a,a+m);
    for(int i=m-1;i>=0;i--)
        if(n>a[i].second)
            s+=a[i].second*a[i].first,n-=a[i].second;
        else
            s+=n*a[i].first,n=0;
    printf("%d\n",s);
    return 0;
}