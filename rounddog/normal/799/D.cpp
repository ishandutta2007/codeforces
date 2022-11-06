#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 100020

using namespace std;

int n;
bool f[42][maxn];
long long int s,t,a,b,h,w,c[maxn];

int main()
{
	scanf("%d%d%d%d%d",&a,&b,&h,&w,&n);
	for (int i=0;i<n;i++) scanf("%d",&c[i]);
	sort(c,c+n);
	memset(f,false,sizeof(f));
	f[0][h]=true;
	f[0][w]=true; 
	if (h>=a&&w>=b||h>=b&&w>=a){
	    printf("0\n");
		return 0;
	} 
	s=h*w;
	for (int i=1;i<=min(34,n);i++)
	{
		for (int j=1;j<maxn;j++)
		{
		    if (f[i-1][j]){
		    	f[i][j]=true;
		    	if (i<=n){
				    if (c[n-i]*j<maxn) f[i][c[n-i]*j]=true;
				    if (s/j>=b&&c[n-i]*j>=a||s/j>=a&&c[n-i]*j>=b){
				    	printf("%d\n",i);
				    	return 0;
				    }
				}
		    }
		}
		s*=c[n-i];
	}
	printf("-1\n");
	return 0;
}