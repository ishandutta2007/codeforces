#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 240;

int cnt[N];
int add[10];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		bool on = (s[i] == '1');
		int nxt = b;
		for (int d = 0; d < N + 10; d++) {
			if (d == nxt) {
				nxt += a;
				on ^= 1;
			}
			if (d < 10) {
				add[d] += on;
			} else {
				cnt[d % N] += on;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < 120; i++) {
		res = max(res, cnt[i]);
	}
	for (int i = 0; i < 10; i++) {
		res = max(res, add[i]);
	}
	cout << res << "\n";
}