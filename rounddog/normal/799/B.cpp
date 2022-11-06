#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 200020

using namespace std;

struct cloth{
	int p,num;
};

bool cmp(cloth x,cloth y)
{
	return x.p<y.p;
}

cloth a[maxn],b[maxn],c[maxn];
bool f[maxn];
int n,m,a1,b1,c1,a2,b2,c2,s[maxn],t[maxn],d[maxn];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	     scanf("%d",&d[i]);
	for (int i=1;i<=n;i++)
	     scanf("%d",&s[i]);
	for (int i=1;i<=n;i++)
	     scanf("%d",&t[i]);
    a1=b1=c1=0;
    for (int i=1;i<=n;i++)
    {
	    if (s[i]==1||t[i]==1) a[++a1].num=i,a[a1].p=d[i];
	    if (s[i]==2||t[i]==2) b[++b1].num=i,b[b1].p=d[i];
	    if (s[i]==3||t[i]==3) c[++c1].num=i,c[c1].p=d[i]; 
	}
	a2=b2=c2=1;
	scanf("%d",&m);
	sort(a+1,a+a1+1,cmp);
	sort(b+1,b+b1+1,cmp);
	sort(c+1,c+c1+1,cmp);
	memset(f,true,sizeof(f));
	while (m--)
	{
		int t;
		scanf("%d",&t);
		if (t==1){
			while (a2<=a1&&!f[a[a2].num]) a2++;
			if (a2>a1) printf("-1 "); else printf("%d ",a[a2].p),f[a[a2].num]=false,a2++;
		}
		if (t==2){
			while (b2<=b1&&!f[b[b2].num]) b2++;
			if (b2>b1) printf("-1 "); else printf("%d ",b[b2].p),f[b[b2].num]=false,b2++;
		}
		if (t==3){
			while (c2<=c1&&!f[c[c2].num]) c2++;
			if (c2>c1) printf("-1 "); else printf("%d ",c[c2].p),f[c[c2].num]=false,c2++;
		}
	}
	printf("\n");
	return 0;
}