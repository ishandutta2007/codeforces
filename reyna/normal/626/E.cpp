//In the name of God

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 2e5 + 5;

int read() { int x; cin >> x; return x; }

double res = -1, mx = -2;
int a[N];
int n;
vector<int> outp;

void solve(bool flag) {
	int l = 0, r = n - 1;
	//one
	int cnt = 1;
	long long sum = a[0];
	for (int i = 1; i < n; ++i) {
		sum += a[i];
		sum -= a[l++];
		if (l > 0 && r > i && ((double) sum + a[l - 1] + a[r]) / (cnt + 2) >= (double) sum / cnt)
			sum += a[--l], sum += a[r--], cnt += 2;
		while (l < i && r < n - 1 && ((double) sum - a[l] - a[r + 1]) / (cnt - 2) > (double) sum / cnt)
			sum -= a[l++], sum -= a[++r], cnt -= 2;
		res = max(res, (double) sum / cnt - a[i]);
		if (flag && res >= mx - 1e-15) {
			cout << i - l + 1 + n - r - 1 << endl;
			for (int k = l; k <= i; ++k)
				cout << a[k] << ' ';
			for (int k = r + 1; k < n; ++k)
				cout << a[k] << ' ';
			exit(0);
		}
	}
//	l = 0, r = n - 1;
//	cnt = 2;
//	sum = a[0] + a[1];
//	for (int i = 1; i < n - 1; ++i) {
//		sum += a[i + 1];
//		sum -= a[l++];
//		while (l < i && r < n - 1 && ((double) sum - a[l] - a[r + 1]) / (cnt - 2) >= (double) sum / cnt)
//			sum -= a[l++], sum -= a[++r], cnt -= 2;
//		while (l > 0 && r > i + 1 && ((double) sum + a[l - 1] + a[r]) / (cnt + 2) >= (double) sum / cnt)
//			sum += a[--l], sum += a[r--], cnt += 2;
//		res = max(res, (double) sum / cnt - ((double) a[i] + a[i + 1]) / 2);
//		if (flag && res == mx) {
//			cout << i - l + 2 + n - r - 1 << endl;
//			for (int k = l; k <= i + 1; ++k)
//				cout << a[k] << ' ';
//			for (int k = r + 1; k < n; ++k)
//				cout << a[k] << ' ';
//			exit(0);
//		}
//	}
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read();
	for (int i = 0; i < n; ++i) {
		a[i] = read();
	}
	sort(a, a + n);
	solve(0);
	mx = res;
	res = 0;
	solve(1);
	if (res == 0) {
		cout << 1 << endl << a[0];
	}
//	cout << outp.size() << endl;
//	for (int x : outp)
//		cout << x << ' ';
}