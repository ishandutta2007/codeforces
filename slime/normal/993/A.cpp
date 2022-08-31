#include <iostream>
#include <cstdio>
using namespace std;
struct th
{
	int a[2];
	th(){a[0] = 1000, a[1] = -1000;}
	void upd(int x)
	{
		a[1] = max(a[1], x), a[0] = min(a[0], x);
	}
	bool check(int x)
	{
		if(x >= a[0] && x <= a[1]) return 1;
		return 0;
	}
}ns[4];
int main()
{
	for(int i = 0; i < 4; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ns[0].upd(x), ns[1].upd(y);
	}
	for(int i = 0; i < 4; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ns[2].upd(x + y), ns[3].upd(x - y);
	}
	bool fl = 0;
	for(int i = -100; i <= 100; i++)
		for(int j = -100; j <= 100; j++)
		{
			bool nf = 0;
			for(int k = 0; k < 4; k++)
			{
				int nss = 0;
				if(!k) nss = i;
				else if(k == 1) nss = j;
				else if(k == 2) nss = i + j;
				else nss = i - j;
				if(!ns[k].check(nss)) nf = 1;
 			}
 			if(!nf)
 			{
 				fl = 1;
 				break;
			}
		}
	if(fl) printf("YES\n");
	else printf("NO\n");
	return 0;
}