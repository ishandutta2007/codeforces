#include <bits/stdc++.h>
#define M(x) (x >= mod ? x - mod : x)
using namespace std;
int T , n , a[110000] , d[110000] , tot , lp[110000] , rp[110000] , tl , tr;
long long ans;
const int mod = 998244353;
struct item
{
	long long num , sum;
	item operator + ( const item &x ) const
	{
		return (item){(num + x.num) % mod , (sum + x.sum) % mod};
	}
	item operator - ( const item &x ) const
	{
		return (item){(num + mod - x.num) % mod , (sum + mod - x.sum) % mod};
	}
	item pr( long long x )
	{
		return (item){num , (sum + num * x % mod) % mod};
	}
} ndp[110000] , ldp[110000];
int main()
{
	scanf("%d" , &T);  
	while(T--)
	{
		scanf("%d" , &n); ans = 0; tl = tr = 0;
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
		for(int i = n ; i >= 1 ; i-- )
		{
			tot = 0;
			for(int j = 1 ; j * j <= a[i] ; j++ )
				if(j == 1 || (a[i] + j - 1) / j != (a[i] + j - 2) / (j - 1)) d[++tot] = j;
			for(int j = sqrt(a[i]) + 1 ; j >= 1 ; j-- )
			{
				int qwq = (a[i] + j - 1) / j;
				if((a[i] + qwq - 1) / qwq != j) continue;
				if(d[tot] != qwq) d[++tot] = qwq;
			}
			tr = 0;
			for(int j = tot ; j >= 1 ; j-- ) rp[++tr] = (a[i] + d[j] - 1) / d[j];
			int it = 1 , las = 0;
			for(int j = 1 ; j <= tr ; j++ )
			{
				while(lp[it] < rp[j] && it <= tl) it++;
				if(j) ndp[j - 1] = (ldp[it - 1] - ldp[las]).pr(d[tr + 1 - (j - 1)] - 1); 
				las = it - 1;
			}
			ndp[tr] = (ldp[tl] - ldp[las]).pr(d[1] - 1);
			ndp[tr].num++;
//			cerr << endl;
			for(int j = 1 ; j <= tr ; j++ ) (ans += ndp[j].sum) %= mod;
			tl = 0;
			for(int j = tot ; j >= 1 ; j-- ) 
				lp[++tl] = a[i] / d[j] , ldp[tl] = ndp[tl] + ldp[tl - 1];
//			for(int j = 1 ; j <= tr ; j++ )
//				cerr << d[tot + 1 - j] << ": " << lp[j] << " - " << rp[j] << ' ' << ndp[j].num << ' ' << ndp[j].sum << endl;
		}
		printf("%lld\n" , ans);
	}
	return 0;
}
/*
1
4
3 2 1 4
*/