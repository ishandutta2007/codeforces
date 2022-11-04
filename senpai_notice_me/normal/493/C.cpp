#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,Max=-0x7fffffff,a[200005],b[200005],ans[200005],J[200005];
bool cnmp(int x,int y) {return x<y;}
int FindJ(int x)
{
    int l=0,r=m,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(b[mid]<x && b[mid+1]>=x) return mid;
        if(b[mid]>=x) r=mid;
        if(b[mid+1]<x) l=mid+1;
    }
    return l;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cnmp);
	cin>>m;
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(b+1,b+m+1,cnmp);
	a[n+1]=b[m+1]=0x7fffffff;
    for(int i=1;i<=n+1;i++)
    {
        J[i]=FindJ(a[i]);
        ans[i]=(n*3-i+1)-(m*3-J[i]);
        Max=max(Max,ans[i]);
    }
    for(int i=1;i<=n+1;i++)
        if(ans[i]==Max)
        {
            printf("%d:%d",n*3-i+1,m*3-J[i]);
            return 0;
        }
}