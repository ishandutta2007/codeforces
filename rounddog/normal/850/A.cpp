#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 1234

struct point{
    int a[5];
};

point h[maxn];
int cnt,q[maxn],n;
bool f;

int check(point x,point y,point z)
{
	int tmp=0;
	for (int i=0;i<5;i++)
	    tmp+=(y.a[i]-x.a[i])*(z.a[i]-x.a[i]);
    return tmp;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<5;j++)
		    scanf("%d",&h[i].a[j]);
	}
	if (n>11) printf("0\n");
	else{
		cnt=0;
		for (int i=0;i<n;i++)
		{
			f=true;
			for (int j=0;j<n;j++)
			    for (int k=0;k<n;k++)
			        if (i!=j&&i!=k&&j!=k&&check(h[i],h[j],h[k])>0) f=false;
            if (f) q[cnt++]=i;
        }
        printf("%d\n",cnt);
        for (int i=0;i<cnt;i++) printf("%d\n",1+q[i]);
    }
    return 0;
}