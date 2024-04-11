#include <bits/stdc++.h>
using namespace std;
#define N 	1010
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
ll y[N];

int main() {
	scanf("%d", &n);
	scanf("%I64d", &y[0]);
	for (int i = 1; i < n; i ++) scanf("%I64d", &y[i]), y[i] -= y[0];
	y[0] = 0;
	bool ans = 1;
	if (y[2] == 2 * y[1]) {
		ll a = 0;
		for (int i = 3; i < n; i ++) {
			if (y[i] != i * y[1]) {
				if (!a) a = y[i] - i * y[1];
				else if (a != y[i] - i * y[1]) {ans = 0; break;}
			}
		}
		if (!a) ans = 0;
		if (ans) puts("YES");
		else puts("NO");
	}
	else {
		ll a = y[1];
		ans = 1;
		ll t;
		for (int i = 3; i < n; i ++) {
			t = y[i] - a * i;
			if (t != 0 && t != y[2] - 2 * a) {ans = 0; break;}
		}
		if (ans) {puts("YES"); return 0;}
		a = y[2] - y[1];
		ans = 1;
		for (int i = 3; i < n; i ++) {
			t = y[i] - a * i;
			if (t != 0 && t != y[1] - a) {ans = 0; break;}
		}
		if (ans) {puts("YES"); return 0;}
		a = y[2];
		ans = 1;
		for (int i = 3; i < n; i ++) {
			t = 2 * y[i] - a * i;
			if (t != 2 * y[1] - a && t != 0) {ans = 0;break;}
		}
		if (ans) {puts("YES"); return 0;}
		puts("NO");
	}
    return 0;
}