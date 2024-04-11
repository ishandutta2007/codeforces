#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<sstream>
#define SS stringstream
#define pw(x) (1ll << (x))
#define m0(x) memset(x, 0, sizeof(x))
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

int kk, n;
int q[2222][2222];
int MAX = 40;

int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	cin >> kk;
	int n = 2;
	q[0][n] = 1;
	q[0][n + 1] = 1;
	n += 2;
	for (int i = 0; i < MAX; i++) {
		q[n - 1][n] = 1;
		q[n - 1][n + 1] = 1;
		q[n - 2][n] = 1;
		q[n - 2][n + 1] = 1;
		n += 2;
	}
	int k = n;
	n++;
	for (int i = 0; i < MAX; i++) {
		q[n - 1][n] = 1;
		n++;		
	}
	q[n - 1][1] = 1;
	for (int i = 1; i < 30; i++) if (kk & pw(i)) {
		q[i + i][k + i] = 1;
		q[i + i + 1][k + i] = 1;
	}
	if (kk % 2) {
		q[0][k] = 1;
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (q[i][j]) q[j][i] = 1;
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (q[i][j]) putchar('Y'); else putchar('N');
		puts("");
	}

	return 0;
}