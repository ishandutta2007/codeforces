#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 200010;
const int Inf = 1e9 + 7;

char S[N];
int n, A[N];

int main() {
	scanf("%d", &n);
	scanf("%s", S + 1);
	for (int i = 1; i <= n; i ++) scanf("%d", &A[i]);
	int top = -1;
	int Ans = Inf;
	for (int i = 1; i <= n; i ++) {
		if (S[i] == 'R') top = A[i];
		if (S[i] == 'L' && top != -1) Ans = min(Ans, (A[i] - top) / 2), top = -1;
	}
	if (Ans == Inf) printf("%d\n", -1); else printf("%d\n", Ans);
}