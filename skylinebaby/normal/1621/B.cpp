#include<bits/stdc++.h>
using namespace std;
int inf = 2123456789;
int a[212345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int mn = 1000000001;
		int mx = 0;
		int mnc = 0;
		int mxc = 0;
		int totc = 0;
		for(int i = 0; i < n; i++)
		{
			int l, r, c;
			scanf("%d %d %d", &l, &r, &c);
			if(!i)
			{
				mn = min(mn, l);
				mx = max(mx, r);
				mnc = mxc = totc = c;
			}
			else
			{
				if(l <= mn && r >= mx)
				{
					mnc = min(mnc, c);
					mxc = min(mxc, c);
					totc = min(totc, c);
					if(l < mn || r > mx)
					{
						if(l < mn)
						{
							totc = c;
							mnc = c;
							mn = l;
						}
						if(r > mx)
						{
							totc = c;
							mx = r;
							mxc = c;
						}						
					}
				}
				else if(l < mn)
				{
					totc = inf;
					mn = l;
					mnc = c;
				}
				else if(r > mx)
				{
					totc = inf;
					mx = r;
					mxc = c;
				}
				else if(l == mn)
				{
					mnc = min(mnc, c);
				}
				else if(r == mx)
				{
					mxc = min(mxc, c);
				}
			}
			printf("%d\n", min(mxc + mnc, totc));
		}
	}
	return 0;
}