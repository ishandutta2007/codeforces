#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 2e5 + 7;
const ll INF = 1e12 + 7;

pair <ll, int> t[4 * N];
ll val[4 * N];

int n;

void add_val(int v, ll x) {
	t[v].first += x;
	val[v] += x;
}

void push(int v) {
	add_val(2 * v, val[v]);
	add_val(2 * v + 1, val[v]);
	val[v] = 0;
}

void relax(int v) {
	t[v] = min(t[2 * v], t[2 * v + 1]);
}

void add_seg(int l, int r, ll x, int lt = 0, int rt = n, int vt = 1) {
	if (lt >= r || l >= rt) {
		return;
	}
	if (l <= lt && rt <= r) {
		add_val(vt, x);
		return;
	}
	push(vt);
	int mt = (lt + rt) / 2;
	add_seg(l, r, x, lt, mt, 2 * vt);
	add_seg(l, r, x, mt, rt, 2 * vt + 1);
	relax(vt);
}

void change(int pos, ll x, int lt = 0, int rt = n, int vt = 1) {
	if (pos >= rt || pos < lt) {
		return;
	}
	if (rt - lt == 1) {
		t[vt].first = x;
		return;
	}
	push(vt);
	int mt = (lt + rt) / 2;
	change(pos, x, lt, mt, 2 * vt);
	change(pos, x, mt, rt, 2 * vt + 1);
	relax(vt);
}

vector <ll> s;

void build(int lt = 0, int rt = n, int vt = 1) {
	if (rt - lt == 1) {
		//cout << vt << " " << s[lt] << " " << lt << " " << rt << "\n";
		t[vt] = {s[lt], -lt};
		return;
	}
	int mt = (lt + rt) / 2;
	build(lt, mt, 2 * vt);
	build(mt, rt, 2 * vt + 1);
	relax(vt);
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector <int> res(n);
	s.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	build();
	for (int i = 0; i < n; i++) {
		int pos = -t[1].second;
		//cout << pos << "\n";
		res[pos] = i + 1;
		add_seg(pos + 1, n, -i - 1);
		change(pos, INF);
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << "\n";
}