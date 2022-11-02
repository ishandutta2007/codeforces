#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << H << ' ';
	debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif

#define N 505

int n, m;
char s[N][N], t[N][N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i ++) scanf("%s", s[i]);
		for (int i = 0; i < n; i ++) for (int j = 0; j < m; j ++) t[i][j] = '.';
		for (int i = 0; i < n; i ++) t[i][0] = 'X', t[i][m] = 0;
		for (int i = 0; i < n; i += 3) for (int j = 0; j < m; j ++) t[i][j] = 'X';
		for (int i = 0; i < n; i += 3) for (int j = 0; j < m; j ++) {
			if (!(i + 1 < n && s[i+1][j] == 'X') && !(i + 2 < n && s[i+2][j] == 'X')) continue;
			if (i + 3 >= n) {
				for (int k = i; k < n; k ++) t[k][j] = 'X';
				if (j == 1) {
					for (int k = i + 1; k < n; k ++) t[k][0] = '.';
				}
				continue;
			}
			if (j == 1) swap(t[i+1][1], t[i+1][0]), swap(t[i+2][1], t[i+2][0]);
			else if (s[i+1][j] == 'X') t[i+1][j] = 'X';
			else t[i+2][j] = 'X';
		}
		for (int i = 0; i < n; i ++) puts(t[i]);
    }

    return 0;
}