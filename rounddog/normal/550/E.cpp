#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 1000020

using namespace std;
int a[maxn],x,y,n,cnt;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	    scanf("%d",&a[i]);
	if (n==1) {
		if (a[1]) printf("NO\n");
		else printf("YES\n0\n");
		return 0;
	}
	if (a[n]==1){
		printf("NO\n");
	}
	else if (a[n-1]==0)
	{
		int j=n-2;
		while (j>0&&a[j]==1) j--;
		if (j<=0){
			printf("NO\n");
		}
		else {
			printf("YES\n");cnt=0;
			for (int i=1;i<n-1;i++)
			{
				printf("%d->",a[i]);
				if (i==j) printf("("),cnt++;
				if (i==j-1) printf("("),cnt++;
			}
			if (cnt==2) printf("%d))->%d\n",a[n-1],a[n]);
			else if (cnt==1) printf("%d)->%d\n",a[n-1],a[n]);
			else if (cnt==0) printf("%d->%d\n",a[n-1],a[n]);
		}
	}
	else {
		printf("YES\n");
        for (int i=1;i<n;i++)
			printf("%d->",a[i]);
		printf("%d\n",a[n]);
	}
	return 0;
}