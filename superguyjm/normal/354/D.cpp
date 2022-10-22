#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 100001;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

vector<int> q[N];
int f[2][1001];
int hh[N];

int gets(int x) {return x * (x + 1) / 2 + 2;}

int main() {
	int n = read(), k = read();
	for(int i = 1; i <= k; i++) {
		int r = read(), c = read();
		q[c].push_back(n - r + c), hh[n - r + c]++;
	} int ans = 3 * k, tp = 1;
	while(tp * (tp + 1) / 2 + 2 < ans) tp++;
	int now = 0; tp--;
	for(int i = 1; i <= n; i++) {
		now ^= 1; f[now][0] = 0;
		for(int j = 1; j <= tp; j++) f[now][j] = 0;
		int cc = 0;
		for(int j = 0; j <= _min(tp, n - i); j++) {
			cc = _max(cc, f[now ^ 1][j]) + 3 * hh[j + i];
			f[now][j] = _max(f[now ^ 1][j + 1], cc - gets(j + 1));
			if(j == 0) f[now][j] = _max(f[now][j], f[now ^ 1][j]);
		} for(int j = 0; j < q[i].size(); j++) hh[q[i][j]]--;
	} put(ans - f[now][0]), puts("");
	return 0;
}