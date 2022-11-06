#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 2005

using namespace std;

int a[maxn],n,k,t,ans;

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	    scanf("%d",&a[i]);
    sort(a,a+n);
    t=0;ans=0;
    while (t<n&&a[t]<=k) t++;
    a[t-1]=k;
    for (int i=t;i<n;i++)
        while (a[i-1]*2<a[i]){
        	a[i-1]*=2;
        	ans++;
        }
    printf("%d\n",ans);
    return 0;
}