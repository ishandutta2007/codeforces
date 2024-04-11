#include <bits/stdc++.h>
using namespace std;

#define N 200020
vector <int> v[N];
int n, x;

int main() {
	///freopen("in.txt", "r", stdin);
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		scanf("%d", &x);
		//cout << x << endl;
		if (i == 0) {
			v[cnt ++].push_back(x);
			continue;
		}
		else {
			int st = -1, en = cnt;
			while (st < en - 1) {
				int mid = (st + en) >> 1;
				if (*(--v[mid].end()) < x) en = mid;
				else st = mid;
			}
			if (en == cnt) {
				v[cnt ++].push_back(x);
			}
			else v[en].push_back(x);
		}
	}

	for (int i = 0; i < cnt; i ++) {
		for (auto y : v[i]) printf("%d ", y); puts("");
	}
}