#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct State {
	int g, r, h, s;
	State() : g(0), r(0), h(0), s(0) {}
	State(int g, int r, int h, int s) : g(g), r(r), h(h), s(s) {}
	bool operator < (const State &other) const {
		return make_pair(make_pair(g, r), make_pair(h, s)) < make_pair(make_pair(other.g, other.r), make_pair(other.h, other.s));
	}
};

const int maxN = 11000;
set < State > states[maxN];
bool G = false, R = false, H = false, S = false;
int n;
string c;

void dfs(int step, int g, int r, int h, int s) {
	State current(g, r, h, s);
	if (states[step].count(current)) {
		return;
	}
	states[step].insert(current);

	if (G && R && H && S) {
		cout << "Gryffindor" << endl;
		cout << "Hufflepuff" << endl;
		cout << "Ravenclaw" << endl;
		cout << "Slytherin" << endl;
		exit(0);
	}

	if (step == n) {
		int x = min(min(g, r), min(h, s));
		if (g == x) {
			G = true;
		}
		if (r == x) {
			R = true;
		}
		if (h == x) {
			H = true;
		}
		if (s == x) {
			S = true;
		}
		return;
	}

	if (c[step] == 'G') {
		dfs(step + 1, g + 1, r, h, s);
	}
	if (c[step] == 'R') {
		dfs(step + 1, g, r + 1, h,  s);
	}
	if (c[step] == 'H') {
		dfs(step + 1, g, r, h + 1, s);
	}
	if (c[step] == 'S') {
		dfs(step + 1, g, r, h, s + 1);
	}
	if (c[step] == '?') {
		int x = min(min(g, r), min(h, s));
		if (g == x) {
			dfs(step + 1, g + 1, r, h, s);
		}
		if (r == x) {
			dfs(step + 1, g, r + 1, h,  s);
		}
		if (h == x) {
			dfs(step + 1, g, r, h + 1, s);
		}
		if (s == x) {
			dfs(step + 1, g, r, h, s + 1);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	cin >> c;
	dfs(0, 0, 0, 0, 0);

	if (G) {
		cout << "Gryffindor" << endl;
	}
	if (H) {
		cout << "Hufflepuff" << endl;
	}
	if (R) {
		cout << "Ravenclaw" << endl;
	}
	if (S) {
		cout << "Slytherin" << endl;
	}

	return 0;
}