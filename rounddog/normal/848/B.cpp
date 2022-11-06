#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 600020

using namespace std;

struct point{
	int g,x,t,num,num2;
};

bool cmp(point u,point v)
{
	int t1=u.x-u.t,t2=v.x-v.t;
	return (t1<t2||t1==t2&&(u.g>v.g||u.g==v.g&&((u.x<v.x)^u.g)));
}

bool cmp2(point u,point v)
{
	int t1=u.x-u.t,t2=v.x-v.t;
	return (t1<t2||t1==t2&&(u.g<v.g||u.g==v.g&&((u.x<v.x)^u.g)));
}

int n,m,k,r;
point a[maxn];
int p,q,ans1[maxn],ans2[maxn],s[maxn];

int main()
{
	scanf("%d%d%d",&k,&m,&n);
	for (int i=0;i<k;i++)
	{
		scanf("%d%d%d",&a[i].g,&a[i].x,&a[i].t);
		a[i].g--;
		a[i].num=i;
	}
	sort(a,a+k,cmp);
	for (int i=0;i<k;i++){
		s[i]=a[i].num;
	    a[i].num2=i;
	}
	sort(a,a+k,cmp2);
	for (int i=0;i<k;i++)
	{
	    if (a[i].g) p=m,q=a[i].x;
		else p=a[i].x,q=n;
		int tmp=s[i];
		ans1[tmp]=p;
		ans2[tmp]=q;
	}
	for (int i=0;i<k;i++) printf("%d %d\n",ans1[i],ans2[i]);
	//for (int i=0;i<k;i++)
	    //printf("%d\n",a[i].num);
    return 0;
}