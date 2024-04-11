#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 300040

using namespace std;

int n,a[maxn],l1,r1,l2,r2,ans1,ans2,b[maxn],c[maxn],maxm;

int main()
{
	scanf("%d",&n);maxm=0;
	for (int i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
	    maxm=max(maxm,a[i]);
	}
	if (n==1){
		printf("%d\n",a[0]);
		return 0;
	}
    for (int i=1;i<n-1;i++)
        b[i]=min(max(a[i-1],a[i+1]),a[i]);
    b[0]=max(a[0],a[1]);b[n-1]=max(a[n-1],a[n-2]);
    c[0]=a[0];
    for (int i=1;i<n;i++)
        c[i]=max(a[i-1],a[i]);
    l1=(n-1)/2;
    r1=n/2;
    l2=n/2;
    r2=(n+1)/2;
    ans1=max(b[l1],b[r1]);
    ans2=max(c[l2],c[r2]);
    for (int i=0;i<n-2;i++)
    {
   	    //printf("\n%d %d %d %d\n",l1,r1,l2,r2);
    	if ((n-i)%2){
    	    printf("%d ",ans1);
    	    l1--;r1++;
    		ans1=max(ans1,b[l1]);
    		ans1=max(ans1,b[r1]);
    	}
    	else{
    		printf("%d ",ans2);
    		l2--;r2++;
    		ans2=max(ans2,c[l2]);
    		ans2=max(ans2,c[r2]);
    	}
    }
    printf("%d %d\n",maxm,maxm);
    return 0;
}