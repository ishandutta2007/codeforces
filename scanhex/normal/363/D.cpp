#include <iostream>
#include <algorithm>
#pragma comment(linker, "/STACK:2000000")                     
typedef long long ll;

using namespace std;

bool comp(int a, int b)
{
	return a > b;
}	
const int MAXN = (int)1e5;
ll ans;
int b[MAXN];
ll p[MAXN];

bool eval(int M, ll a1)
{
	ans = 0;
	for (int i = 0; i < M; ++i)
		{
			if (b[M - i - 1] + a1 >= p[i])
			{
				ans += p[i];
				a1 -= b[M - i - 1] >= p[i] ? 0 : p[i] - b[M - i - 1];		
			}
			else
				return false;	
		}
 	return true;
}

int main()
{	
	int n, m;
	ll a;
	cin >> n >> m >> a;  
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	for (int i = 0; i < m; ++i)
		cin >> p[i];
	sort(b, b + n, comp);
	sort(p, p + m);
	int L = 0, R = min(n, m) + 1; 
	while (R - L > 1)
	{
		int M = (R + L) / 2; 
		if (eval(M, a))
			L = M;
		else
			R = M;
	}
	eval(L, a);
	if (ans >= a)
		ans -= a;
	else
		ans = 0;
	cout << L << ' ' << ans;
}