#include <cstdio>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<ll, char> PLC;

const int MAXN = 2E5 + 10;

PLC a[MAXN], b[MAXN];
int fail[MAXN];

int input(PLC a[], int tn){
	int n = 1;
	scanf("%d-%c", &a[0].st, &a[0].nd);
	for (int i = 1; i < tn; ++i){
		scanf("%d-%c", &a[n].st, &a[n].nd);
		if (a[n - 1].nd == a[n].nd)
			a[n - 1].st += a[n].st;
		else
			++n;
	}
	return n;
}

int kmp(PLC s[], int n, PLC p[], int m){
	int i, j;
	int ret = 0;
	fail[1] = 0;
	for (j = 1, i = 2; i < m; ++i){
		for (j = fail[i - 1]; 1 <= j && p[i] != p[j + 1]; j = fail[j]);
		fail[i] = p[i] == p[j + 1] ? j + 1 : 0;
	}

	for (j = 1, i = 0; i < n; ++i)
		if (s[i] == p[j]){
			++j;
//			printf("%d %d %d\n", i, j, m);
			if (j == m){// s[i] == p[m - 1]
				ret += 0 <= i - (m - 1) && s[i - (m - 1)].nd == p[0].nd && s[i - (m - 1)].st >= p[0].st
						&& i + 1 < n && s[i + 1].nd == p[m].nd && s[i + 1].st >= p[m].st;
				j = fail[j - 1] + 1;
			}
		}
		else if (1 < j)
			j = fail[j - 1] + 1, --i;
	return ret;
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	n = input(a, n);
	m = input(b, m);
	if (m == 1){
		ll ans = 0;
		for (int i = 0; i < n; ++i)
			if (a[i].nd == b[0].nd && a[i].st >= b[0].st)
				ans += a[i].st - b[0].st + 1;
		printf("%I64d\n", ans);
	}
	else if (m == 2){
		int ans = 0;
		for (int i = 1; i < n; ++i)
			ans += a[i - 1].nd == b[0].nd && a[i - 1].st >= b[0].st && a[i].nd == b[1].nd && a[i].st >= b[1].st;
		printf("%d\n", ans);
	}
	else
		printf("%d\n", kmp(a, n, b, m - 1));
	return 0;
}