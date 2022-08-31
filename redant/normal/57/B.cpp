#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
#define MX 100005
#define SI ({int x;scanf("%d",&x);x;})

LL a[MX], count[MX], vsum[MX];
int markk[MX];

int main()
{
	int n = SI, m = SI, k = SI;

	for(int i = 0; i < m; ++i)
	{
		int x = SI, y = SI, z = SI;
		a[x] += z, a[y+1] -= z;
		count[x+1] += 1, count[y+1] -= 1;
		vsum[y+1] -= (y-x);
	}

	for(int i = 0; i < k; ++i)  markk[SI]++;
	
	LL ans = 0, cura = 0, curv = 0, active = 0;
	for(int i = 1; i <= n; ++i)
	{
		active += count[i];
		curv += ( vsum[i] + active );
		cura += a[i]; 
		ans  += markk[i] * ( cura + curv );
	}

	cout<<ans<<endl;

	return 0;
}