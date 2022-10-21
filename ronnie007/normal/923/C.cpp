#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
template<class T, class T2> inline void chkmax(T &x, const T2 &y) { if(x < y) x = y; }
template<class T, class T2> inline void chkmin(T &x, const T2 &y) { if(x > y) x = y; }
const int MAXN = (int)3e5 + 42;

int n;
int a[MAXN], p[MAXN];

void read()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> p[i];
}

int psz = 2;
int to[MAXN * 30][2]; 
int cnt[MAXN * 30];

void add(int x)
{
	int u = 1;
	for(int l = 30; l >= 0; l--)
	{
		int bit = (x >> l) & 1;
		if(to[u][bit] == -1)
			to[u][bit] = psz++;
	
		u = to[u][bit];
		cnt[u]++;
	} 
}

void rem(int x)
{
	int u = 1;
	for(int l = 30; l >= 0; l--)
	{
		int bit = (x >> l) & 1;
		if(to[u][bit] == -1)
			to[u][bit] = psz++;
	
		u = to[u][bit];
		cnt[u]--;
	} 
}

int get_value(int x)
{
	int ret = 0, u = 1;
	for(int l = 30; l >= 0; l--)
	{
		int bit = (x >> l) & 1;
		if(to[u][bit] != -1 && cnt[to[u][bit]])
			ret += (bit << l), u = to[u][bit];
		else
			ret += (bit ^ 1) << l, u = to[u][bit ^ 1];
	}

	return ret;
}

void solve()
{
	memset(to, -1, sizeof(to));
	for(int i = 0; i < n; i++)
		add(p[i]);

	for(int i = 0; i < n; i++)
	{
		int x = get_value(a[i]);
		cout << (x ^ a[i]) << " ";
		rem(x);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}