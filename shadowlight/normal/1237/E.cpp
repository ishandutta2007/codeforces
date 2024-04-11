#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <vector <int> > gr;
int n;
int now, h;

struct Data {
	int a, b;
	int cana, canb;
};

Data dfs(int v, int hh) {
	Data up = {0, 0, 0, 0};
	if (hh == h) {
		if (v % 2) {
			auto t = dfs(2 * v, hh + 1);
			up.a = 1;
		} else {
			up.cana = 1;
		}
		return up;
	} else if (hh > h) {
		return up;
	}
	auto ta = dfs(2 * v, hh + 1);
	auto tb = dfs(2 * v + 1, hh + 1);
	if (ta.b % 2 != 0) {
		ta.canb--;
		ta.b++;
	} else {
		ta.canb = 0;
	}
	if (tb.a % 2 == 0) {
		tb.cana--;
		tb.a++;
	} else {
		tb.cana = 0;
	}
	up.a = ta.a + tb.b + 1;
	up.b = tb.a + tb.b + 1;
	up.cana = ta.cana + ta.canb;
	up.canb = tb.cana + tb.canb;
	assert(up.cana + up.canb <= 1);
	return up;
}

void build() {
	gr.resize(n);
	auto t = dfs(1, 0);
	//cout << t.a << " " << t.b << " " << t.cana << " " << t.canb << "\n";
	if (t.a + t.b + 1 <= n && n <= t.a + t.b + 1 + t.cana + t.canb) {
		cout << "1\n";
	} else {
		cout << "0\n";
	}
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	if (n < 3) {
		cout << "1\n";
		exit(0);
	}
	now = 0, h = -1;
	while (2 * now + 1 <= n) {
		now = (2 * now + 1);
		h++;
	}
	build();
}