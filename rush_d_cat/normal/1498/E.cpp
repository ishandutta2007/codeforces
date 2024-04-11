#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, k[N];
pair<int,int> f[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &k[i]);
	}
	vector< pair<int, pair<int,int> > > v;
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			int x = i, y = j;
			if (k[x] < k[y]) swap(x, y);
			v.push_back( make_pair(k[x] - k[y], make_pair(x, y)) );
		}
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0; i --) {
		int x = v[i].second.first;
		int y = v[i].second.second;
		printf("? %d %d\n", x, y);
		fflush(stdout);
		char s[10];
		scanf("%s", s);
		if (s[0] == 'Y') {
			printf("! %d %d\n", x, y); exit(0);
		}
	}
	printf("! %d %d\n", 0, 0); exit(0);
}