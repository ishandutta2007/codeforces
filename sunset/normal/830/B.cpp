#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair < int, int > pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 100005;

vector < int > v[MAXN];
int n, bit[MAXN], cur;
LL ans;

inline int Lowbit(int x) { return x & -x; }
inline int Modify(int x) { for (; x <= n; x += Lowbit(x)) bit[x] ++; }
inline int Query(int x) { int ret = 0; for (; x; x -= Lowbit(x)) ret += bit[x]; return ret; }

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
		v[Read()].pb(i);
	for (int i = 1; i <= 100000; i ++)
		if (v[i].size())
		{
			int j = 0;
			while (j < v[i].size() && v[i][j] < cur)
				j ++;
			for (int k = 0; k < v[i].size(); k ++)
			{
				int nxt = v[i][(j + k) % v[i].size()];
				if (nxt >= cur)
					ans += nxt - cur - Query(nxt) + Query(cur);
				else
					ans += nxt + n - cur - Query(nxt) - Query(n) + Query(cur);
				Modify(cur = nxt);
			}
		}
	cout << ans << endl;
	return 0;
}