#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

map<int, int> m;
set<int> s;

void add(int x) {
	if (m[x] == 0) {
		s.insert(x);
	}
	if (m[x] == 1) {
		s.erase(x);
	}
	m[x]++;
}

void del(int x) {
	if (m[x] == 1) {
		s.erase(x);
	}
	if (m[x] == 2) {
		s.insert(x);
	}
	m[x]--;
}

void wr() {
	if (!s.size()) {
		printf("Nothing\n");
	} else {
		printf("%d\n", *(--s.end()));
	}
}

int a[1000000];

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int n, k;
	cin >> n >> k;
	forn (i, n) {
		scanf("%d", &a[i]);
		m[a[i]] = 0;
	}
	forn (i, k) {
		add(a[i]);
	}
	wr();
	forn (i, n - k) {
		add(a[i + k]);
		del(a[i]);
		wr();
	}
}