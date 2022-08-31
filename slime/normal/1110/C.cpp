#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
#define mod 998244353
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		int r = 1;
		while(r < n) r = r * 2 + 1;
		if(r != n) printf("%d\n", r);
		else
		{
			int fl = 0;
			for(int g = 2; g * g <= r; g++)
			{
				if(r % g) continue;
				printf("%d\n", r / g);
				fl = 1;
				break;
			}
			if(!fl) printf("1\n");
		} 
	 } 
	return 0;
}