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

const int maxN = 3100;
const int P = 1000000007;
const int p[2] = {1000000009, 1000000013}, q[2] = {137, 1000007};
int n, a[maxN][maxN], s[maxN];
bool u[maxN][maxN];

long long h[2][maxN], pw[2][maxN];

unordered_set < long long > used[maxN];

void precalc(long long h[], long long p, long long q, long long pw[]) {
    pw[0] = 1;
    for (int i = 1; i < maxN; ++i) {
        pw[i] = (pw[i - 1] * q) % p;
    }
    
    long long c = 0;
    for (int i = 0; i < n; ++i) {
        c = (c * q + s[i] + 1) % p;
        h[i] = c;
    }
}

pair < int, int > getHash(int l, int r) {
    long long a = h[0][r] - (l == 0 ? 0 : h[0][l - 1] * pw[0][r - l + 1]);
    a = ((a % p[0]) + p[0]) % p[0];
    
    long long b = h[1][r] - (l == 0 ? 0 : h[1][l - 1] * pw[1][r - l + 1]);
    b = ((b % p[1]) + p[1]) % p[1];
    
    return make_pair(a, b);
}

void add(int &x, int value) {
    x += value;
    if (x >= P) {
        x -= P;
    }
}

bool ok(int a, int b, int c, int d) {
    int code = a * 8 + b * 4 + c * 2 + d;
    return code != 3 && code != 5 && code != 14 && code != 15;
}

void precalc() {
    for (int i = 0; i < 2; ++i) {
        precalc(h[i], p[i], q[i], pw[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            pair < int, int > c = getHash(i, j);
            long long code = 1LL * c.first * 2000000000 + c.second;
            u[i][j] = (used[j - i + 1].count(code) == 0);
            used[j - i + 1].insert(code);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        a[i][i] = 1;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int res = 0;
            if (j >= i) {
                add(res, j - 1 >= i ? a[i][j - 1] : 1);
            }
            if (j - 1 >= i) {
                add(res, j - 2 >= i ? a[i][j - 2] : 1);
            }
            if (j - 2 >= i) {
                add(res, j - 3 >= i ? a[i][j - 3] : 1);
            }
            if (j - 3 >= i) {
                if (ok(s[j - 3], s[j - 2], s[j - 1], s[j])) {
                    add(res, j - 4 >= i ? a[i][j - 4] : 1);
                }
            }
            a[i][j] = res;
        }
    }
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
	    cin >> s[i];
	}
	precalc();
	
	int res = 0;
	for (int i = 0; i < n; ++i) {
	    for (int j = 0; j <= i; ++j) {
	        if (u[j][i]) {
	            add(res, a[j][i]);
	        }
	    }
	    printf("%d\n", res);
	}

	return 0;
}