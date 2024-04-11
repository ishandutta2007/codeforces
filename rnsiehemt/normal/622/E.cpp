#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define em emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 500005;

int N, ans;
std::vector<int> e[MaxN], v;

void ho(int i, int p, int d) {
	if (sz(e[i]) == 1) v.pb(d);
	for (int j : e[i]) if (j != p) ho(j, i, d+1);
}
int go(int i) {
	v.clear();
	ho(i, 0, 1);
	std::sort(all(v));
	int k = 0;
	for (int i : v) {
		if (i > k) k = i;
		else k++;
	}
	return k;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		int x, y; scanf("%d%d", &x, &y); x--; y--;
		e[x].pb(y); e[y].pb(x);
	}
	for (int i : e[0]) domax(ans, go(i));
	printf("%d\n", ans);
}