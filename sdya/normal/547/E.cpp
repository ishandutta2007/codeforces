#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <complex>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000000103LL;
const long long Q = 997LL;
const int maxN = 210000;
const int maxQ = 510000;

int n, q;
string s[maxN];
vector < long long > h[maxN];
long long p[maxN];

char t[maxN];
int l[maxQ], r[maxQ], k[maxQ];
int lens[maxN], m;
vector < int > questions[maxN];

unordered_map < int, int > cnt[maxN];
unordered_map < int, int > bearbyhash[maxN];
map < string, int > bh[110];

vector < pair < int, int > > w[maxN];

void buildHash(int v) {
	h[v].resize(s[v].size());
	long long value = 0;
	for (int i = 0; i < s[v].size(); ++i) {
		value = (value * Q + (s[v][i] - 'a' + 1)) % P;
		h[v][i] = value;
	}
}

inline long long gethash(int v, int l, int r) {
	long long res = h[v][r] - (l == 0 ? 0 : p[r - l + 1] * h[v][l - 1]);
	res %= P;
	if (res < 0) {
		res += P;
	}
	return res;
}

const int L = 10;

void process(int v) {
	for (int i = 0; i < m; ++i) {
		if (lens[i] > s[v].size()) {
			break;
		}

		for (int j = 0; j <= s[v].size() - lens[i]; ++j) {
			if (lens[i] <= L) {
				map < string, int > ::iterator it = bh[lens[i]].find(s[v].substr(j, lens[i]));
				if (it != bh[lens[i]].end()) {
					++cnt[v][it->second];
				}
			} else {
				long long t = gethash(v, j, j + lens[i] - 1);
				unordered_map < int, int > ::iterator it = bearbyhash[lens[i]].find(t);
				if (it != bearbyhash[lens[i]].end()) {
					++cnt[v][it->second];
				}
			}
		}
	}

	for (unordered_map < int, int > ::iterator it = cnt[v].begin(); it != cnt[v].end(); ++it) {
		w[it->first].push_back(make_pair(it->second, v));
	}
}

long long res[maxQ];

long long ft[maxN];

void update(int k, long long value) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		ft[i] += value;
	}
}

long long get(int k) {
	long long res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += ft[i];
	}
	return res;
}

long long get(int l, int r) {
	return get(r) - get(l - 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &t);
		s[i] = t;
		int l = s[i].size();
		for (int j = 0; j <= l; ++j) {
			t[j] = 0;
		}
		lens[m ++] = l;
		buildHash(i);
		bearbyhash[l][h[i].back()] = i;
		if (l <= L) {
			bh[l][s[i]] = i;
		}
	}

	p[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		p[i] = (p[i - 1] * Q) % P;
	}

	sort(lens, lens + m);
	m = unique(lens, lens + m) - lens;

	for (int i = 0; i < n; ++i) {
		process(i);
	}

	for (int i = 0; i < q; ++i) {
		scanf("%d%d%d", &l[i], &r[i], &k[i]);
		--l[i];
		--r[i];
		--k[i];
		questions[bearbyhash[s[k[i]].size()][h[k[i]].back()]].push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < w[i].size(); ++j) {
			update(w[i][j].second, w[i][j].first);
		}

		for (int j = 0; j < questions[i].size(); ++j) {
			int index = questions[i][j];
			int cl = l[index];
			int cr = r[index];
			res[index] = get(cl, cr);
		}

		for (int j = 0; j < w[i].size(); ++j) {
			update(w[i][j].second, -w[i][j].first);
		}
	}

	for (int i = 0; i < q; ++i) {
		printf("%I64d\n", res[i]);
	}


	return 0;
}