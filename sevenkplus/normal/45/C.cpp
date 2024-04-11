#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
#define abs(x) ((x) > 0 ? (x) : -(x))
using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, PII> PIII;

const int N = 200005;

bool sex[N];
long long v[N];
int prev[N], next[N];
bool av[N];
priority_queue<PIII> heap;
PII ans[N];
int n, cans;

PIII make_triple(long long x, int y, int z)
{return make_pair(x, make_pair(y, z));}

int main()
{
	scanf("%d\n", &n);
	for (int i = 1; i <= n; ++i) {
		char c;
		scanf("%c", &c);
		sex[i] = (c == 'B');
	}
	for (int i = 1; i <= n; ++i) scanf("%lld", &v[i]);
	for (int i = 1; i <= n; ++i) {
		next[i] = i + 1;
		prev[i] = i - 1;
	}
	next[0] = 1;
	prev[n + 1] = n;
	for (int i = 2; i <= n; ++i) if (sex[i] ^ sex[i - 1]) 
		heap.push(make_triple(-abs(v[i] - v[i - 1]) * 200000 - i, i - 1, i));
	memset(av, 1, sizeof(av));
	while (!heap.empty()) {
		PIII piii = heap.top();
		heap.pop();
		int x = piii.second.first, y = piii.second.second;
		if (!av[x] || !av[y]) continue;
		int p = prev[x], q = next[y];
		next[p] = q;
		prev[q] = p;
		av[x] = av[y] = false;
		if (p != 0 && q != n + 1 && (sex[p] ^ sex[q]))
			heap.push(make_triple(-abs(v[p] - v[q]) * 200000 - q, p, q));
		ans[++cans] = make_pair(x, y);
	}
	printf("%d\n", cans);
	for (int i = 1; i <= cans; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
}