#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define em emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N, K, a[500005], c[1000005], ansl, ansr, k;

int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	int r = 0;
	for (int l = 0; l < N; l++) {
		while (r < N && (c[a[r]] > 0 || k < K)) {
			if (c[a[r]] == 0) k++;
			c[a[r]]++;
			r++;
		}
		if (r-l > ansr-ansl) {
			ansr = r;
			ansl = l;
		}
		c[a[l]]--;
		if (c[a[l]] == 0) k--;
	}
	printf("%d %d\n", ansl+1, ansr);
}