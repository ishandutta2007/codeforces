#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 5;

int a[maxN][maxN];
int n;
pair < int, int > order[] = {
	make_pair(0, 0), // 0
	make_pair(0, 1), // 1
	make_pair(0, 2), // 2
	make_pair(0, 3), // 3
	make_pair(1, 0), // 4
	make_pair(2, 0), // 5
	make_pair(3, 0), // 6 no need to search
	make_pair(2, 1), // 7
	make_pair(1, 2), // 8 no need to search
	make_pair(1, 1), // 9
	make_pair(3, 1), // 10 no need to search
	make_pair(1, 3), // 11 no need to search
	make_pair(2, 2), // 12
	make_pair(3, 2), // 13 no need to search
	make_pair(3, 3), // 14 no need to search
	make_pair(2, 3)  // 15 no need to search
};

multiset < int > S;
int sum = 0;

void rec(int have) {
	if (have == n * n) {
		printf("%d\n", sum);
		for (int i = 0; i < n; ++i, printf("\n"))
			for (int j = 0; j < n; ++j)
				printf("%d ", a[i][j]);
		exit(0);
		return ;
	}
	int x = order[have].first, y = order[have].second;
	if (have < 4) {
		vector < int > order;
		for (multiset < int > :: iterator it = S.begin(); it != S.end(); ++it) {
			order.push_back(* it);
		}
		for (int i = 0; i < order.size(); ++i) 
			if (i == 0 || order[i] > order[i - 1]) {
				a[x][y] = order[i];
				S.erase(S.find(order[i]));
				rec(have + 1);
				S.insert(order[i]);
			}
		return ;
	}

	if (have == 4) {
		sum = a[0][0] + a[0][1] + a[0][2] + a[0][3];
	}

	if (have == 6) {
		int t = sum - a[0][0] - a[1][0] - a[2][0];
		if (S.find(t) != S.end()) {
			S.erase(S.find(t));
			a[x][y] = t;
			rec(have + 1);
			S.insert(t);
		}
		return ;
	}
	if (have == 8) {
		int t = sum - a[3][0] - a[2][1] - a[0][3];
		if (S.find(t) != S.end()) {
			S.erase(S.find(t));
			a[x][y] = t;
			rec(have + 1);
			S.insert(t);
		}
		return ;
	}

	if (have == 10) {
		int t = sum - a[0][1] - a[1][1] - a[2][1];
		if (S.find(t) != S.end()) {
			S.erase(S.find(t));
			a[x][y] = t;
			rec(have + 1);
			S.insert(t);
		}
		return ;
	}

	if (have == 11) {
		int t = sum - a[1][0] - a[1][1] - a[1][2];
		if (S.find(t) != S.end()) {
			S.erase(S.find(t));
			a[x][y] = t;
			rec(have + 1);
			S.insert(t);
		}
		return ;
	}

	if (have == 13) {
		int t = sum - a[0][2] - a[1][2] - a[2][2];
		if (S.find(t) != S.end()) {
			S.erase(S.find(t));
			a[x][y] = t;
			rec(have + 1);
			S.insert(t);
		}
		return ;
	}
	if (have == 14) {
		int t = sum - a[3][0] - a[3][1] - a[3][2];
		int t2 = sum - a[0][0] - a[1][1] - a[2][2];
		if (t == t2 && S.find(t) != S.end()) {
			S.erase(S.find(t));
			a[x][y] = t;
			rec(have + 1);
			S.insert(t);
		}
		return ;
	}
	if (have == 15) {
		int t = sum - a[2][0] - a[2][1] - a[2][2];
		int t2 = sum - a[0][3] - a[1][3] - a[3][3];
		if (t == t2 && S.find(t) != S.end()) {
			S.erase(S.find(t));
			a[x][y] = t;
			rec(have + 1);
			S.insert(t);
		}
		return ;
	}

	vector < int > order;
	for (multiset < int > :: iterator it = S.begin(); it != S.end(); ++it) {
		order.push_back(* it);
	}
	for (int i = 0; i < order.size(); ++i) 
		if (i == 0 || order[i] > order[i - 1]) {
			a[x][y] = order[i];
			S.erase(S.find(order[i]));
			rec(have + 1);
			S.insert(order[i]);
		}
	return ;
}

int b[maxN * maxN];

void solve_trivial() {
	sort(b, b + (n * n));
	do {
		for (int i = 0; i < n * n; ++i)
			a[i / n][i % n] = b[i];
		set < int > S;
		for (int i = 0; i < n; ++i) {
			int sum = 0;
			for (int j = 0; j < n; ++j)
				sum += a[i][j];
			S.insert(sum);
			sum = 0;
			for (int j = 0; j < n; ++j)
				sum += a[j][i];
			S.insert(sum);
		}
		int s1 = 0, s2 = 0;
		for (int i = 0; i < n; ++i)
			s1 += a[i][i], s2 += a[i][n - 1 - i];
		S.insert(s1);
		S.insert(s2);
		if (S.size() == 1) {
			printf("%d\n", * S.begin());
			for (int i = 0; i < n; ++i, printf("\n"))
				for (int j = 0; j < n; ++j)
					printf("%d ", a[i][j]);
			return ;
		}
	} while (next_permutation(b, b + n * n));
}

void solve_clever() {
	for (int i = 0; i < n * n; ++i)
		S.insert(b[i]);
	rec(0);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n * n; ++i)
		scanf("%d", &b[i]);

	if (n <= 3) {
		solve_trivial();
	} else {
		solve_clever();
	}

	return 0;
}