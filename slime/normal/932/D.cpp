#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long

#define maxn 400005
using namespace std;
ll dep[maxn];
ll fa[maxn][20], mxs[maxn][20], pre[maxn][20];
ll sum[maxn][20];
ll w[maxn];
int main()
{
	int last = 0;
	int q;
	scanf("%d", &q);
	w[1] = 0;
	dep[1] = 1;
	int cnt = 1;
	for(int i = 0; i < q; i++)
	{
		ll tp, p, q;
		scanf("%I64d%I64d%I64d", &tp, &p, &q);
		p ^= last, q ^= last;
		if(tp == 1)
		{
			cnt++;
			fa[cnt][0] = p, w[cnt] = q;
			mxs[cnt][0] = w[cnt];
			
			for(int i = 1; i < 20; i++)
				fa[cnt][i] = fa[fa[cnt][i - 1]][i - 1], 
				mxs[cnt][i] = 
				max(mxs[cnt][i - 1], 
				mxs[fa[cnt][i - 1]][i - 1]);
				
			int npl = p;
			for(int i = 19; i >= 0; i--)
				if(mxs[npl][i] < w[cnt])
					npl = fa[npl][i];
			pre[cnt][0] = npl;
			dep[cnt] = dep[npl] + 1;
			
			sum[cnt][0] = w[cnt];
			for(int i = 1; i < 20; i++)
				pre[cnt][i] = pre[pre[cnt][i - 1]][i - 1], 
				sum[cnt][i] = sum[cnt][i - 1] + sum[pre[cnt][i - 1]][i - 1];
		}
		else
		{
			int nlen = 0, npl = p;
			for(int i = 19; i >= 0; i--)
				if(q >= sum[npl][i])
				{
				//	cout<<i<<" "<<sum[npl][i]<<endl;
					if(pre[npl][i])
						nlen += (1 << i);
					else 
					{
						nlen = dep[p];
						break;
					} 
					q -= sum[npl][i];
					npl = pre[npl][i];
				}
			printf("%d\n", nlen);
			last = nlen;
		}	
	} 
	
	return 0;
}
/*
2
1 1 1
2 2 1
*/