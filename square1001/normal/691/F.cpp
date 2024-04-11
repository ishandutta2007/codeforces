#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int readint() {
	char c = getchar();
	int ans = 0;
	while('0' <= c && c <= '9') {
		ans = ans * 10 + int(c - '0');
		c = getchar();
	}
	return ans;
}
char buf[19];
void writelong(long long x) {
	int ptr = 0;
	if(x == 0) buf[ptr++] = '0';
	while(x > 0) buf[ptr++] = x % 10 + '0', x /= 10;
	while(ptr--) putchar(buf[ptr]);
	putchar('\n');
}
int A[1000009], V[1000009], C[3000009]; long long ans[3000009];
int main() {
	int N = readint();
	for(int i = 0; i < N; ++i) A[i] = readint();
	int Q = readint();
	for(int i = 0; i < Q; ++i) V[i] = readint();
	int lim = *max_element(V, V + Q);
	for(int i = 0; i < N; ++i) {
		if(A[i] <= lim) ++C[A[i]];
	}
	for(int i = 1; i <= lim; ++i) {
		for(int j = 1; i * j <= lim; ++j) {
			ans[i * j] += 1LL * C[i] * C[j];
		}
		if(1LL * i * i <= lim) ans[i * i] -= C[i];
	}
	for(int i = 1; i <= lim; ++i) {
		ans[i] += ans[i - 1];
	}
	for(int i = 0; i < Q; ++i) {
		writelong(1LL * N * (N - 1) - ans[V[i] - 1]);
	}
	return 0;
}