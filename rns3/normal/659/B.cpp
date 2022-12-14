#include <bits/stdc++.h>
using namespace std;

#define M 200001

int a[M], b[M];
vector<int> v[M];
vector<string> w[M];

bool cmp(int x, int y) {
	if(a[x] != a[y]) return a[x] > a[y];
	return 0;
}

int main() {
	///freopen("B.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) {
        string A;
		cin >> A;
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
        w[x].push_back(A);
	}
    for(int i = 1; i <= m; i ++) {
        int sz = v[i].size();
        for(int j = 0; j < sz; j ++) a[j] = v[i][j];
		for(int j = 0; j < sz; j ++) b[j] = j;
		sort(b, b + sz, cmp);
        if(sz > 2 && a[b[1]] == a[b[2]]) {
        	puts("?");
			continue;
        }
		cout << w[i][b[0]] << " " << w[i][b[1]] << endl;
    }
}