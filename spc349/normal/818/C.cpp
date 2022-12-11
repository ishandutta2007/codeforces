#include <bits/stdc++.h>
using namespace std;

vector <int> L, R, U, D;
int A[100010], B[100010], C[100010], DD[100010];

int main() {
	int k; scanf("%d", &k);
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < k; i++) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		A[i] = a, B[i] = b, C[i] = c, DD[i] = d;
		L.push_back(min(a, c));
		R.push_back(max(a, c));
		U.push_back(min(b, d));
		D.push_back(max(b, d));
	}
	sort(L.begin(), L.end()), sort(R.begin(), R.end()), sort(D.begin(), D.end()), sort(U.begin(), U.end());
	int cl, cr, cu, cd; scanf("%d%d%d%d", &cl, &cr, &cu, &cd);
	for (int i = 0; i < k; i++) {
		int rl = lower_bound(L.begin(), L.end(), max(A[i], C[i])) - L.begin();
		int rr = R.end() - upper_bound(R.begin(), R.end(), min(A[i], C[i]));
		int ru = lower_bound(U.begin(), U.end(), max(B[i], DD[i])) - U.begin();
		int rd = D.end() - upper_bound(D.begin(), D.end(), min(B[i], DD[i]));
		if (A[i] != C[i]) rl--, rr--;
		else rd--, ru--;
		if (rl == cl && cr == rr && cu == ru && cd == rd) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}