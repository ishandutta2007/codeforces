#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 511;

char chr[N];
vector <int> edges[N];
int parse(string str, int &node_cnt)
{
	if(str.size() == 1)
	{
		chr[node_cnt] = str[0];
		return node_cnt ++;
	}
	int op_pos = 0;
	int left_cnt = 0;
	int n = str.size();
	int cur_id;
	for(int i = 0; i < n; i ++)
		if(str[i] == '(')
			left_cnt ++;
		else if(str[i] == ')')
			left_cnt --;
		else if(left_cnt == 0 && (str[i] == '|' || str[i] == '&' || str[i] == '?'))
		{
			op_pos = i;
			cur_id = node_cnt;
			chr[node_cnt ++] = str[i];
		}
	edges[cur_id].push_back(parse(str.substr(1, op_pos - 2), node_cnt));
	edges[cur_id].push_back(parse(str.substr(op_pos + 2, n - op_pos - 3), node_cnt));

	return cur_id;
}

const int Mod = (int)1e9 + 7;

void dwt_and(int x[], int l, int r)
{
	if(l + 1 == r)
		return;
	int mid = (l + r) >> 1;
	dwt_and(x, l, mid);
	dwt_and(x, mid, r);
	for(int i = l; i < mid; i ++)
		x[i] = (x[i] + x[i - l + mid]) % Mod;
}
void rdwt_and(int x[], int l, int r)
{
	if(l + 1 == r)
		return;
	int mid = (l + r) >> 1;
	for(int i = l; i < mid; i ++)
		x[i] = (x[i] - x[i - l + mid] + Mod) % Mod;
	rdwt_and(x, l, mid);
	rdwt_and(x, mid, r);
}

void dwt_or(int x[], int l, int r)
{
	if(l + 1 == r)
		return;
	int mid = (l + r) >> 1;
	dwt_or(x, l, mid);
	dwt_or(x, mid, r);
	for(int i = l; i < mid; i ++)
		x[i - l + mid] = (x[i - l + mid] + x[i]) % Mod;
}
void rdwt_or(int x[], int l, int r)
{
	if(l + 1 == r)
		return;
	int mid = (l + r) >> 1;
	for(int i = l; i < mid; i ++)
		x[i - l + mid] = (x[i - l + mid] - x[i] + Mod) % Mod;
	rdwt_or(x, l, mid);
	rdwt_or(x, mid, r);
}

int dp[N][1 << 16];
int tmp1[1 << 16];
int tmp2[1 << 16];
int tmp3[1 << 16];
void dfs(int cur)
{
	if(edges[cur].size() == 0)
	{
		if(chr[cur] == 'd' || chr[cur] == '?')
			dp[cur][0xFF00] ++;
		if(chr[cur] == 'D' || chr[cur] == '?')
			dp[cur][0x00FF] ++;

		if(chr[cur] == 'c' || chr[cur] == '?')
			dp[cur][0xF0F0] ++;
		if(chr[cur] == 'C' || chr[cur] == '?')
			dp[cur][0x0F0F] ++;

		if(chr[cur] == 'b' || chr[cur] == '?')
			dp[cur][0xCCCC] ++;
		if(chr[cur] == 'B' || chr[cur] == '?')
			dp[cur][0x3333] ++;

		if(chr[cur] == 'a' || chr[cur] == '?')
			dp[cur][0xAAAA] ++;
		if(chr[cur] == 'A' || chr[cur] == '?')
			dp[cur][0x5555] ++;
	}
	else
	{
		dfs(edges[cur][0]);
		dfs(edges[cur][1]);
		if(chr[cur] == '|' || chr[cur] == '?')
		{
			for(int i = 0; i < (1 << 16); i ++)
			{
				tmp1[i] = dp[edges[cur][0]][i];
				tmp2[i] = dp[edges[cur][1]][i];
			}
			dwt_or(tmp1, 0, (1 << 16));
			dwt_or(tmp2, 0, (1 << 16));
			memset(tmp3, 0, sizeof(tmp3));
			for(int i = 0; i < (1 << 16); i ++)
				tmp3[i] = (long long)tmp1[i] * tmp2[i] % Mod;
			rdwt_or(tmp3, 0, (1 << 16));
			for(int i = 0; i < (1 << 16); i ++)
				dp[cur][i] = (dp[cur][i] + tmp3[i]) % Mod;
		}

		if(chr[cur] == '&' || chr[cur] == '?')
		{
			for(int i = 0; i < (1 << 16); i ++)
			{
				tmp1[i] = dp[edges[cur][0]][i];
				tmp2[i] = dp[edges[cur][1]][i];
			}
			dwt_and(tmp1, 0, (1 << 16));
			dwt_and(tmp2, 0, (1 << 16));
			memset(tmp3, 0, sizeof(tmp3));
			for(int i = 0; i < (1 << 16); i ++)
				tmp3[i] = (long long)tmp1[i] * tmp2[i] % Mod;
			rdwt_and(tmp3, 0, (1 << 16));
			for(int i = 0; i < (1 << 16); i ++)
				dp[cur][i] = (dp[cur][i] + tmp3[i]) % Mod;
		}
	}
}

pair <int, int> check[N];
int main()
{
	ios :: sync_with_stdio(false);
	string str;
	cin >> str;
	int node_cnt = 0;
	int root = parse(str, node_cnt);

	
	memset(dp, 0, sizeof(dp));
	dfs(root);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		int tmp = (a ^ 1);
		tmp += ((b ^ 1) << 1);
		tmp += ((c ^ 1) << 2);
		tmp += ((d ^ 1) << 3);
		check[i] = make_pair(tmp, e);
	}

	int ans = 0;
	for(int i = 0; i < (1 << 16); i ++)
	{
		bool flag = true;
		for(int j = 0; j < n; j ++)
			if(((i >> check[j].first) & 1) != check[j].second)
				flag = false;
		if(flag)
		{
			ans += dp[root][i];
			ans %= Mod;
		}
	}
	cout << ans << '\n';

	return 0;
}