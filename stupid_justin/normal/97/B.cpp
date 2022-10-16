#include<bits/stdc++.h>
using namespace std;
const int N=150005;
int n,len,tot;
struct point{
	int x,y;
}a[N],ans[N],p[N];
bool cmp(const point &a,const point &b)
{
	if(a.x!=b.x)return a.x<b.x;
	else return a.y<b.y;
}
void msort(int l,int r)
{
	if(l==r){ans[++tot]=a[l];return;}
	if(l>r)return;
	int mid=(l+r)>>1;
	msort(l,mid-1);msort(mid+1,r);
	for(int i=l;i<=r;++i)
	{
		point tmp;
		tmp.x=a[mid].x;
		tmp.y=a[i].y;
		ans[++tot]=tmp;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	msort(1,n);
	sort(ans+1,ans+tot+1,cmp);
	ans[0].x=ans[0].y=1000000007;
	for(int i=1;i<=tot;++i)
	{
		if(ans[i].x!=ans[i-1].x||ans[i].y!=ans[i-1].y)
			p[++len]=ans[i];
	}
	printf("%d\n",len);
	for(int i=1;i<=len;++i)
		printf("%d %d\n",p[i].x,p[i].y);
	return 0;
}