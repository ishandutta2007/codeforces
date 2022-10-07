#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 110;
const int MAXM = 10100;
int ar[MAXN][MAXM];

char buf[12345678];
int inf = 1 << 30;
int main() {
	int N,M;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			ar[i][j] = inf;
		}
	}
	for(int i = 0; i < N; ++i) {
		scanf("%s", buf);
		string s = string(buf);
		int pr = inf;
		for(int y = 0; y < 2; ++y) 
		for(int x = 0; x < M; ++x) {
			if (s[x] == '1') pr = 0;
			ar[i][x] = min(ar[i][x],pr);
			pr++;
		}
		pr = inf;
		for(int y = 0; y < 2; ++y)
		for(int x = M - 1; x >= 0; --x) {
			if (s[x] == '1') pr = 0;
			ar[i][x] = min(ar[i][x], pr);
			pr++;
		}
	}
	long long m = inf;
	for(int j = 0; j < M; ++j) {
		long long s = 0;
		for(int i = 0; i < N; ++i) {
			s += ar[i][j];
		}
		m = min(m,s);
	}
	int ans;
	if (m > N * M) {
		ans = -1;
	} else {
		ans = int(m);
	}
	printf("%d\n",ans);
	return 0;
}