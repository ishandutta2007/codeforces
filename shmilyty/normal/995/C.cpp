#include<bits/stdc++.h>
using namespace std;
int n,f[100001];
double x[100001],y[100001],X,Y;
double rua(double x,double y)
{
	return x*x+y*y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf %lf",&x[i],&y[i]);
	for(int i=n;i>=1;i--)
		if(rua(X-x[i],Y-y[i])>=rua(X+x[i],Y+y[i]))
		{
			X+=x[i];
			Y+=y[i]; 
			f[i]=1;
		}
		else
		{
			X-=x[i];
			Y-=y[i];
			f[i]=-1;
		}
	for(int i=1;i<=n;i++)
		cout<<f[i]<<" ";
	return 0;
}