#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
typedef vector<int> vi;

int h, a[N];

int main() {
	scanf("%d", &h);
	for (int i = 0; i <= h; i ++) scanf("%d", a + i);
	bool ans = 0;
	int i;
	for (i = 1; i < h; i ++) {
		if (a[i] > 1 && a[i+1] > 1) {
			ans = 1;
			break;
		}
	}
	if (!ans) puts("perfect");
	else {
		puts("ambiguous");
		for (int j = 0, tot = 0; j <= h; j ++) {
			for (int k = tot + 1; k <= tot + a[j]; k ++) {
				printf("%d ", tot);
			}
			tot += a[j];
		}
		puts("");
		int tot = 0;
		for (int j = 0, tot = 0; j <= h; j ++) {
			for (int k = tot + 1; k <= tot + a[j]; k ++) {
				if (j == i + 1&& k == tot + 1) printf("%d ", tot - 1);
				else printf("%d ", tot);
			}
			tot += a[j];
		}
		puts("");
	}
    return 0;
}