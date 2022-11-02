#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 30111;
const int K = 1024;
const int Mod1 = (int)1e7 + 19;
const int Mod2 = (int)1e9 + 7;
const int Inf = 0x3f3f3f3f;
typedef long long intl;

int type[N];
int value[N];
int mass[N];
int st[N], ed[N];

intl dp[K];
void dfs(int left, int right, vector <int> ex, int max_mass)
{	
	intl tmp[K];
	memcpy(tmp, dp, sizeof(dp));
	vector <int> nxt_ex;
	for(auto &i : ex)
		if(st[i] <= left && ed[i] >= right)
		{
			for(int j = max_mass; j >= mass[i]; j --)
				dp[j] = max(dp[j], dp[j - mass[i]] + value[i]);
		}
		else if(!(ed[i] <= left || st[i] >= right))
			nxt_ex.push_back(i);
	
	int mid = (left + right) >> 1;
	if(left + 1 == right)
	{
		if(type[left] == 3)
		{
			intl ans = 0;
			intl cur = 0;
			intl base = 1;
			for(int i = 1; i <= max_mass; i ++)
			{
				cur = max(cur, dp[i]);
				ans += cur % Mod2 * base % Mod2;
				ans %= Mod2;
				base = base * Mod1 % Mod2;
			}
			cout << ans << '\n';
		}
	}
	else
	{
		dfs(left, mid, nxt_ex, max_mass);
		dfs(mid, right, nxt_ex, max_mass);
	}
	memcpy(dp, tmp, sizeof(tmp));
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
	{
		cin >> value[i] >> mass[i];
		st[i] = 0;
		ed[i] = Inf;
	}
	int q;
	cin >> q;
	int cnt = n;
	for(int i = 0; i < q; i ++)
	{
		cin >> type[i];
		if(type[i] == 1)
		{
			cnt ++;
			cin >> value[cnt] >> mass[cnt];
			st[cnt] = i;
			ed[cnt] = Inf;
		}
		else if(type[i] == 2)
		{
			int x;
			cin >> x;
			ed[x] = i;
		}
	}
	vector <int> ex;
	for(int i = 1; i <= cnt; i ++)
		ex.push_back(i);
	dfs(0, q, ex, k);
	return 0;
}