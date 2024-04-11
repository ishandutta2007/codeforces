#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define ld double
#define maxn 500005
using namespace std;
const ll mod = 1000000007;
ll sum[maxn];
ll x[maxn];
int main()
{
	int q;
	int cnt = 0;
	scanf("%d", &q);
	ld ans = 0;
	for(int i = 1; i <= q; i++)
	{
		int tp;
		scanf("%d", &tp);
		if(tp == 2) printf("%.12lf\n", ans);
		else
		{
			scanf("%I64d", &x[++cnt]);
		//	cout<<x[cnt]<<endl;
			sum[cnt] = x[cnt] + sum[cnt - 1];
			int l = 1, r = cnt - 1;
			while(l < r)
			{
				int mid = (l + r) >> 1;
				if(x[mid] * mid >= sum[mid - 1] + x[cnt])
					r = mid;
				else l = mid + 1;
			}
			ans = x[cnt] - (sum[l - 1] + x[cnt]) / (ld)l;
			ans = max(ans, x[cnt] - sum[cnt] / (ld)cnt);
		} 
	}
	return 0; 
}