#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ll_i;
struct edge { int u, v; ll w; };

char buf[100001];
string s[100000];

int hoge(int i, int l, int r) {
	int j = l;
	while (j < r && s[j].length() == i) j++;
	if (j == r) return 1;
	bool flag0 = false, flag1 = false, flag2 = false;
	for (char c = 'a'; c <= 'z'; c++) {
		int _j = j;
		while (j < r && s[j][i] == c) j++;
		if (_j == j) continue;
		switch (hoge(i + 1, _j, j)) {
		case 0:
			flag1 = true;
			break;
		case 1:
			flag0 = true;
			break;
		case 3:
			flag2 = true;
			break;
		}
	}
	if (flag2) return 2;
	else if (flag0 && flag1) return 2;
	else if (flag0 && !flag1) return 0;
	else if (!flag0 && flag1) return 1;
	else return 3;
}

int main() {
	int n, k; cin >> n >> k;
	for (int j = 0; j < n; j++) {
		scanf("%s", buf);
		s[j] = string(buf);
	}
	sort(s, s + n);
	switch (hoge(0, 0, n)) {
	case 0:
		cout << ((k % 2 == 0) ? "Second" : "First") << endl;
		break;
	case 1:
		cout << "Second" << endl;
		break;
	case 2:
		cout << "First" << endl;
		break;
	case 3:
		cout << "Second" << endl;
		break;
	}
}