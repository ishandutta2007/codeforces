#include<bits/stdc++.h>
using namespace std;
struct node{
	int val,id;
} a[100001];
int t,n,minn;
bool cmp(node x,node y)
{
	if(x.val==y.val)
		return x.id<y.id;
	return x.val<y.val;
}
bool judge()
{
	for(int i=1;i<=n;i++)
		if(a[i].id!=i)
			if(a[i].val%minn)
				return 0;
	return 1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		minn=1e9;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i].val);
			minn=min(minn,a[i].val);
			a[i].id=i;
		}
		sort(a+1,a+1+n,cmp);
		if(judge())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}