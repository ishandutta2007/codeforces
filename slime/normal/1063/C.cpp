#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define ll long long
#define ld double
#define mod 1000000007
using namespace std;
int read()
{
	char inp[10];
	scanf("%s", inp);
	if(inp[0] == 'w') return 1;
	return 0;
}
int ex[2];
int main()
{
	int n;
	scanf("%d", &n);
	int ntp = 0, dvs = 4000000;
	int bg = 0;
	int up = -1, ns = 0, lp = 0;
	ex[0] = ex[1] = 1;
	for(int i = 1; i <= n; i++)
	{
		if(i == 1)
		{
		//	printf("0 0\n");
			cout<<0<<" "<<0<<endl;
			fflush(stdout);
			bg = read();
		}
		else 
		{
			if(ntp == 0)
			{
				if(up == -1)
				{
					int ots = (ns + dvs) * 2;
				//	printf("0 %d\n", ots);
					cout<<"0 "<<ots<<endl;
					fflush(stdout);
					int ans = read();
					if(ans == bg) ns += dvs, ex[0] = 2 * ns + 1;
					else
					{
						up = ns + dvs, lp = ns;
						ex[0] = 2 * up - 1;
					}
				}
				else
				{
					int mid = (up + lp) >> 1;
					if(mid == up || mid == lp)
					{
						ntp = 1;
						up = -1, ns = 0;
					}
					else
					{
					//	printf("0 %d\n", 2 * mid);
						cout<<0<<" "<<2 * mid<<endl;
						fflush(stdout);	
						int ans = read();
						if(ans == bg) lp = mid, ex[0] = 2 * lp + 1;
						else up = mid, ex[0] = 2 * up - 1;
					}
				}
			}
			if(ntp == 1)
			{
				if(up == -1)
				{
					int ots = (ns + dvs) * 2;
				//	printf("%d 0\n", ots);
					cout<<ots<<" "<<0<<endl;
					fflush(stdout);
					int ans = read();
					if(ans == bg) ns += dvs, ex[1] = 2 * ns + 1;
					else
					{
						up = ns + dvs, lp = ns;
						ex[1] = 2 * up - 1;
					}
				}
				else
				{	
					int mid = (up + lp) >> 1;
					cout<<2 * mid<<" "<<0<<endl;
					fflush(stdout);
					int ans = read();
					if(ans == bg) lp = mid, ex[1] = 2 * lp + 1;
					else up = mid, ex[1] = 2 * up - 1;
				}
			}
		}
	} 
//	printf("%d %d %d %d", 0, ex[0], ex[1], 0);
	cout<<0<<" "<<ex[0]<<" "<<ex[1]<<" "<<0<<endl;
	fflush(stdout);
	return 0;
}