#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[1005];

int find0(int l,int r,int t){
	if (l==r) return l;
	int mid=(l+r)>>1;
	printf("? ");
	for (int i=1;i<=n;i++)
		if (i>=l&&i<=mid) printf("1"); else printf("0");
	printf("\n");
	fflush(stdout);

	int t2; scanf("%d",&t2);
	int s=mid-l+1;
	int k=(s+t2-t)>>1;
	if (k) return find0(l,mid,t);
	return find0(mid+1,r,t);
}

int find1(int l,int r,int t){
	if (l==r) return l;
	int mid=(l+r)>>1;
	printf("? ");
	for (int i=1;i<=n;i++)
		if (i>=l&&i<=mid) printf("0"); else printf("1");
	printf("\n");
	fflush(stdout);

	int t2; scanf("%d",&t2);
	int s=mid-l+1;
	int k=(s+t2-t)>>1;
	if (k) return find1(l,mid,t);
	return find1(mid+1,r,t);
}

int main()
{
	int p1,p0; scanf("%d",&n);

	printf("? ");
	for (int i=1;i<=n;i++) printf("0");
	printf("\n");
	fflush(stdout);

	int t; scanf("%d",&t);

	printf("? ");
	for (int i=1;i<n;i++) printf("0");
	printf("1\n");
	fflush(stdout);

	int t2; scanf("%d",&t2);
	if (t>t2){ p1=n; p0=find0(1,n,t); }
		else{ p0=n; p1=find1(1,n,n-t); }

	printf("! %d %d\n",p0,p1);
	fflush(stdout);
	return 0;
}