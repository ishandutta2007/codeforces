#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int M = 7005;
using bs = bitset<M>;

const int N = 100005;
bs mem[N];

vector<int> divs(int x)
{
	vector<int> ans;
	for (int i = 1; i * i <= x; ++i)
	{
		if (x % i == 0)
		{
			ans.push_back(i);
			if (i * i != x)
				ans.push_back(x / i);
		}
	}
	return ans;
}

int sqfree[M];
void init()
{
	fill(sqfree, sqfree + M, true);
	for (int i = 2; i < M; ++i)
		for (int j = i * i; j <= M; j += i * i)
			sqfree[j] = false;
}
bool trash = (init(), false);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	bs empty = {0};
	const int KEK = 100;
	vector<bs> masks(KEK);
	for (int i = 1; i < KEK; ++i)
	{
		for (int j = i; j < M; j += i)
			if (sqfree[j / i])
			masks[i][j] = true;
	}
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			 int x, y;
			 cin >> x >> y;
			 --x;
			 mem[x] = empty;
			 for (int z : divs(y))
//				 if (sqfree[y / z])
					 mem[x][z] = true;
		}
		if (t == 2)
		{
			int x, y, z;
			cin >> x >> y >> z;
			--x, --y, --z;
			mem[x] = mem[y] ^ mem[z];
		}
		if (t == 3)
		{
			int x, y, z;
			cin >> x >> y >> z;
			--x, --y, --z;
			mem[x] = mem[y] & mem[z];
		}
		if (t == 4)
		{
			 int x, y;
			 cin >> x >> y;
			 --x;
			 int ans = 0;
			 if (y < KEK)
				 ans = (mem[x] & masks[y]).count() & 1;
			 else
			 {
				 for (int z = y; z < M; z += y)
					 if (sqfree[z / y])
						 ans ^= mem[x][z];
			 }
			 cout << ans;
		}
	}
	cout << '\n';
	return 0;
}