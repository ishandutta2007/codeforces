#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
 
string a, b;

int cnt = 0;
int n;

void op(int len) {
	if (len != 1) {
		int need;
		if (cnt % 2 == 0) {
			need = (a[n - 1 - cnt / 2] - '0') ^ 1;
		} else {
			need = (a[cnt / 2 + 1] - '0');
		}
		a[0] = (char) (need + '0'); 
	} else {
		a[0] = (a[0] == '1' ? '0' : '1');
	}
}
 
void solve() {
	cin >> n;
	cin >> a >> b;
	vector <int> res;
	cnt = 0;
	for (int i = n - 1; i >= 0; --i) {
		//cout << a[0] << " ";
		if (a[0] == b[i]) {
			op(1);
			res.pb(1);
		}
		op(i + 1);
		res.pb(i + 1);
		++cnt;
	}
	//cout << endl;
	//assert(a == b);
	cout << res.size() << " ";
	for (int x : res) {
		cout << x << " ";
	}
	cout << "\n";
}
 
int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
 
}