#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 200500;

int n, k, a[N];

set<int> S;

int main() {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
		scanf("%d%d", &n, &k);
		S.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			S.insert(a[i]);
		}
		bool flg = 0;
		for (int i = 0; i < n; i++) {
			if (S.count(a[i] + k)) {
				flg = 1; break;
			}
		}
		flg ? puts("YES") : puts("NO");
    }

    return 0;
}