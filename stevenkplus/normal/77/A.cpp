#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

const int inf = 1 << 30;
const pii BAD(inf, inf);
const int MAXN = 50;
const int MAXM = 50;

int N = 7, M;

int exp[3];
int assigned[3];

pii likes[MAXM];
int assign[MAXN];

pii compute() {
	int low = inf, high = 0;
	for(int i = 0; i < 3; ++i) {
		if (assigned[i] == 0) {
			return BAD;
		}
		int val = exp[i] / assigned[i];
		low = min(low, val);
		high = max(high, val);
	}

	int likings = 0;
	for(int i = 0; i < M; ++i) {
		if (assign[likes[i].first] == assign[likes[i].second]) {
			++likings;
		}
	}

	int diff = high - low;
	return pii(diff, -likings);
}

pii ans = BAD;

void rec(int n) {
	if (n > N) {
		ans = min(ans, compute());
	} else {
		for(int i = 0; i < 3; ++i) {
			assign[n] = i;
			++assigned[i];
			rec(n + 1);
			--assigned[i];
		}
	}
}

map<string, int> mymap;
int mapsize = 0;
int get(string &name) {
	int &ret = mymap[name];
	if (ret) return ret;
	return ret = ++mapsize;
}

char buf[123456];

int main() {
	scanf("%d", &M);
	for(int i = 0; i < M; ++i) {
		string s1, s2;
		scanf("%s", buf);
		s1 = string(buf);
		scanf("%s", buf);
		scanf("%s", buf);
		s2 = string(buf);

		likes[i] = pii(get(s1), get(s2));
	}

	for(int i = 0; i < 3; ++i) {
		scanf("%d", exp + i);
	}
	rec(1);

	printf("%d %d\n", ans.first, -ans.second);
	return 0;
}