#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 100020

using namespace std;

int n,m,j,d[42],p,l,r,se,mid;
bool f[maxn];
long long int a[maxn],b[maxn],c[maxn],t;

bool check(int x)
{
	int tmp=m;
	for (int i=0;i<m;i++) a[i]=b[i];
	for (int i=se-x;i<se;i++)
	    for (int j=0;j<=c[i];j++)
	        a[tmp++]=(long long int)1<<j;
    sort(a,a+tmp);
    if (tmp>se-x) return false;
    for (int i=0;i<tmp;i++)
        if (((long long int)2<<c[i])<a[tmp-1-i]) return false;
    return true;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) 
	    scanf("%I64d",&a[i]);
	sort(a,a+n);
	m=0;p=0;
	t=1;
	memset(d,0,sizeof(d));
	memset(b,0,sizeof(b));
	memset(f,true,sizeof(f));
	for (int j=0;j<=40;j++)
	{
		while (p<n&&a[p]==t) p++,d[j]++;
		while (p<n&&a[p]<2*t) b[m++]=a[p],p++;
		t=t*2;
	}
	p=0;
	for (int j=1;j<=40;j++)
		if (d[j]>d[j-1]){
			for (int i=0;i<d[j]-d[j-1];i++) b[m++]=(long long int)1<<j;
		    d[j]=d[j-1];
		}
	for (int j=40;j>=0;j--)
	    for (int i=0;i<d[j]-d[j+1];i++)
	        c[p++]=j;
	se=p;
	l=0;r=p/2;
	mid=(l+r)/2;
	while (l<=r)
	{
		if (check(mid)) l=mid+1;
		else r=mid-1;
		mid=(l+r)/2;
	}
	while ((l>=0)&&!check(l)) l--;
	if (l>=0){
	    for (int i=se-l;i<se;i++) 
		    printf("%d ",i); 
		printf("%d\n",se);
	}
	else printf("-1\n");
	return 0;
}