#include<bits/stdc++.h> 
#define maxn 200020
#define mod 1000000007

using namespace std;

struct point{
	int d,num;
};

bool cmp(point x,point y)
{
	return x.d>y.d;
}

point b[maxn];
int a[maxn],n,ans[maxn];

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for (int i=0;i<n;i++)
	{
	    scanf("%d",&b[i].d);
	    b[i].num=i;
	}
	sort(b,b+n,cmp);
	for (int i=0;i<n;i++)
        ans[b[i].num]=a[i];
    for (int i=0;i<n-1;i++) printf("%d ",ans[i]);
    printf("%d\n",ans[n-1]);
    return 0;
}