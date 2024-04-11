#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<iomanip>
#include<cassert>
#include<memory>
#include<string>
#include<string.h>
#include<math.h>

using namespace std;

typedef double ld;
typedef long long li;
typedef pair<int, int> pt;

const int N = 300 * 1000 + 5;
int a[N];
int n;

void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
}

void solve() {
	li ans = 0;
	multiset<int> r;
	for (int i = 0; i < n; ++i) {
		if (r.size() && *r.begin() < a[i]) {
			int b = *r.begin();
			ans += a[i] - b;
			r.erase(r.begin());
			r.insert(a[i]);
		}
		r.insert(a[i]);
	}
	cout << ans << endl;
}

int main() {

	srand(time(NULL));

	read();
	solve();

	return 0;
}