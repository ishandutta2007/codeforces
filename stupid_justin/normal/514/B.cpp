#include<bits/stdc++.h>
using namespace std;	
int n,xzero,yzero,xone,yone,t=0;
long double xielv[10005],xielvtmp;
bool flag;
int main()
{
	cin>>n>>xzero>>yzero;
	for (int i=1;i<=n;++i)
	{
		flag=1;
		cin>>xone>>yone;
		if (xone==xzero) xielvtmp=1000000000000;
		else xielvtmp=(yone-yzero-0.0)/(xone-xzero-0.0);
		for (int i=1;i<=t;++i) 
		{
			if (xielvtmp==xielv[i]) 
			{
				flag=0;
				break;
			}
		}
		if (flag) 
		{
			t++;
			xielv[t]=xielvtmp;
		}
	}
	cout<<t<<endl;
	return 0;
}