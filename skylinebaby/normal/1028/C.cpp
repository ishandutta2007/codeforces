#include<bits/stdc++.h>
using namespace std;
int ar[133333][4];
const int N = 1000000009;
	int cnt;
	int xu;
	int xdw;
	int xl;
	int xr;
void init()
{
	cnt = 0;
	xu=N;
	xdw=-N;
	xl=-N;
	xr=N;
}
int main()
{
	int n;
	scanf("%d",&n);
	int u=N;
	int dw=-N;
	int l=-N;
	int r=N;
	for(int i = 0;i<n;i++) 
	{
		for(int j = 0;j<4;j++)scanf("%d",&ar[i][j]);
		l = max(ar[i][0],l);
		dw = max(ar[i][1],dw);
		r = min(ar[i][2],r);
		u = min(ar[i][3],u);		
	}
init();
		for(int i = 0;i<n;i++) 
		{
			if (ar[i][3]==u) 
			{
				cnt++;
				if (cnt==1) continue;
			}
			xl = max(ar[i][0],xl);
			xdw = max(ar[i][1],xdw);
			xr = min(ar[i][2],xr);
			xu = min(ar[i][3],xu);		
		}
		if (xl<=xr&&xdw<=xu)
		{
			printf("%d %d\n",xl,xdw);
			return 0;
		}
init();
		for(int i = 0;i<n;i++) 
		{
			if (ar[i][2]==r)			{
				cnt++;
				if (cnt==1) continue;
			}
			xl = max(ar[i][0],xl);
			xdw = max(ar[i][1],xdw);
			xr = min(ar[i][2],xr);
			xu = min(ar[i][3],xu);		
		}
		if (xl<=xr&&xdw<=xu)
		{
			printf("%d %d\n",xl,xdw);
			return 0;
		}
init();
		for(int i = 0;i<n;i++) 
		{
			if (ar[i][1]==dw)			{
				cnt++;
				if (cnt==1) continue;
			}
			xl = max(ar[i][0],xl);
			xdw = max(ar[i][1],xdw);
			xr = min(ar[i][2],xr);
			xu = min(ar[i][3],xu);		
		}
		if (xl<=xr&&xdw<=xu)
		{
			printf("%d %d\n",xl,xdw);
			return 0;
		}
init();
		for(int i = 0;i<n;i++) 
		{
			if (ar[i][0]==l)			{
				cnt++;
				if (cnt==1) continue;
			}
			xl = max(ar[i][0],xl);
			xdw = max(ar[i][1],xdw);
			xr = min(ar[i][2],xr);
			xu = min(ar[i][3],xu);		
		}
		if (xl<=xr&&xdw<=xu)
		{
			printf("%d %d\n",xl,xdw);
			return 0;
		}
	return 0;
}