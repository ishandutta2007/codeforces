#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

int N;
char tmp[100005];

void solve() {
	scanf("%d", &N);
	if (N <= 26) {
		rep(i, N) tmp[i] = 'a' + i;
		tmp[N] = 0; printf("%s\n", tmp);
		return;
	}
	int ts = (N - 11) / 2;
	int ptr = 0;
	rep(i, ts + 1) tmp[ptr++] = 'a';
	rep(i, 3) tmp[ptr++] = 'b';
	rep(i, ts) tmp[ptr++] = 'a';
	rep(i, 3) tmp[ptr++] = 'c';
	rep(i, 2) tmp[ptr++] = 'b';
	rep(i, 2) tmp[ptr++] = 'c';
	if (ptr != N) tmp[ptr++] = 'd';
	tmp[N] = 0;
	printf("%s\n", tmp);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}