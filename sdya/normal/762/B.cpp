#define _CRT_SECURE_NO_WARNINGS
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
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 310000;

int a, b, c;
int n;
vector < int > p, q;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &a, &b, &c);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int v;
		scanf("%d", &v);
		char s[10];
		for (int j = 0; j < 10; ++j) {
			s[j] = 0;
		}
		scanf("%s", &s);
		if (s[0] == 'U') {
			p.push_back(v);
		} else {
			q.push_back(v);
		}
	}
	
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());

	int x = min(a, (int)p.size());
	int y = min(b, (int)q.size());

	int rem = p.size() - x + q.size() - y;
	rem = min(rem, c);

	printf("%d", x + y + rem);

	long long price = 0;
	vector < int > d;
	for (int i = 0; i < p.size(); ++i) {
		if (i < x) {
			price += p[i];
		} else {
			d.push_back(p[i]);
		}
	}
	for (int i = 0; i < q.size(); ++i) {
		if (i < y) {
			price += q[i];
		} else {
			d.push_back(q[i]);
		}
	}
	sort(d.begin(), d.end());
	for (int i = 0; i < rem; ++i) {
		price += d[i];
	}

	cout << " " << price << endl;



	return 0;
}