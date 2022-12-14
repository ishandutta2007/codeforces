#include <bits/stdc++.h>
using namespace std;

#define N 5050

char s[N];

int n;

const int K = 26;

vector <int> v[K];

char tmp[N];

int id[N];

bool cmp(int i, int j) {
	return tmp[i] < tmp[j];
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i ++) v[s[i]-'a'].push_back(i);
	int ans = 0;
	for (int k = 0; k < K; k ++) {
		int m = v[k].size();
		if (m <= 1) {
			ans += m;
			continue;
		}
		for (int i = 0; i < m; i ++) id[i] = i;
		int mx = 0;
		for (int d = 1; d < n; d ++) {
			for (int i = 0; i < m; i ++) tmp[i] = s[(v[k][i]+d)%n];
			sort(id, id + m, cmp);
			int now = 0;
			for (int i = 0; i < m; i ++) {
				bool bad = 0;
				if (i && tmp[id[i]] == tmp[id[i-1]]) bad = 1;
				if (i < m - 1 && tmp[id[i+1]] == tmp[id[i]]) bad = 1;
				if (!bad) now ++;
			}
			mx = max(mx, now);
		}
		ans += mx;
	}
	printf("%.10lf\n", 1.0 * ans / n);


	return 0;
}