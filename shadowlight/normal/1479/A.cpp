#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;
int n;
vector <int> a;

int ask(int x) {
	if (x == 0 || x == n + 1) {
		return INF;
	}
	if (a[x] != -1) {
		return a[x];
	}

	cout << "? " << x << endl;
	int val;
	cin >> val;
	return a[x] = val;
}

void ask_lokal_minimum(int index) {
	int a = ask(index);
	int b = ask(index - 1);
	int c = ask(index + 1);
	if (a < min(b, c)) {
		cout << "! " << index << endl;
		exit(0);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	a.resize(n + 1, -1);

	int l = 1, r = n;
	ask_lokal_minimum(l);
	ask_lokal_minimum(r);

	while (r - l > 1) {
		int mid = (l + r) / 2;
		ask_lokal_minimum(mid);

		int vala = ask(mid - 1), valb = ask(mid), valc = ask(mid + 1);
		if (vala < valb && valb < valc) {
			r = mid;
		} else {
			l = mid;
		}
	}
	ask_lokal_minimum(l);
	ask_lokal_minimum(r);

	assert(false);
}