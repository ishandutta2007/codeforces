#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1000005
#define ll long long
#define mod 1000000007
using namespace std;
ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if(b & 1) ns = ns * a % mod;
	return ns;
}
ll hs[maxn];
ll pw[maxn], bpw[maxn];
char s[maxn], t[maxn];
ll gt(int l, int r)
{
	ll ns = hs[r] - hs[l - 1];
	ns = ns * bpw[l - 1] % mod;
	if(ns < 0) ns += mod;
	return ns;
}
int main()
{
	pw[0] = bpw[0] = 1;
	ll bks = ksm(30, mod - 2);
	for(int i = 1; i < maxn; i++)
		pw[i] = pw[i - 1] * 30 % mod, 
		bpw[i] = bpw[i - 1] * bks % mod;
	scanf("%s", s);
	scanf("%s", t + 1);
	int n = strlen(s), m = strlen(t + 1);
	if(s[0] == '1') 
		for(int i = 0; i < n; i++)
			s[i] = '1' + '0' - s[i];
	hs[0] = 0;
	for(int i = 1; i <= m; i++)
		hs[i] = (hs[i - 1] + pw[i] * (t[i] - 'a')) % mod;
	int cn[2] = {0, 0};
	for(int i = 0; i < n; i++)
		cn[s[i] - '0']++;
	int ans = 0;
	for(int x = 1; x <= m; x++)
	{
		if(1ll * x * cn[0] > m) continue;
		int lst = m - x * cn[0];
		if(lst % cn[1]) continue;
		int y = lst / cn[1];
		if(!y) continue;
		int npl = 1;
		int ls = -1, rs = -1;
		int fl = 1;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '0')
			{
				if(gt(npl, npl + x - 1) != gt(1, x)) fl = 0;
				npl += x;
			}
			else
			{
				if(ls == -1) ls = npl, rs = npl + y - 1;
				else if(gt(npl, npl + y - 1) != gt(ls, rs)) fl = 0;
				npl += y;
			}
		}
		if(x == y && gt(1, x) == gt(ls, rs)) fl = 0;
		if(fl) ans++;//, cout<<x<<endl;
	}
	printf("%d\n", ans);
	return 0;
}