#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define em emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 200005, MaxX = 1000005;

int N, M, a[MaxN], l[MaxN], r[MaxN], x[MaxN], ans[MaxN];
std::vector<int> p[MaxX], q[MaxX];

int count(int i, int j) {
	return std::lower_bound(all(p[i]), j+1) - p[i].begin();
}
int get(std::vector<int> &v, int j, int k) {
	auto i = lower_bound(all(v), j);
	if (i != v.end() && *i <= k) return *i+1;
	else return -1;
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		p[a[i]].pb(i);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &l[i], &r[i], &x[i]);
		l[i]--; r[i]--;
		q[x[i]].pb(i);
	}

	for (int i = 0; i < MaxX; i++) {
		std::vector<int> v;
		for (int j = 0; j < sz(p[i]); j++) {
			if (j == 0 || p[i][j-1] != p[i][j] - 1) v.pb(p[i][j]-1);
			if (j == sz(p[i])-1 || p[i][j+1] != p[i][j]+1) v.pb(p[i][j]+1);
		}
		for (int j : q[i]) {
			if (count(i, r[j]) - count(i, l[j]-1) == 0) ans[j] = l[j]+1;
			else ans[j] = get(v, l[j], r[j]);
		}
	}
	for (int i = 0; i < M; i++) printf("%d\n", ans[i]);
}