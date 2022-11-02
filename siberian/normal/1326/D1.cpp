#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

string s;
int n;

void read() {
	cin >> s;
	n = s.size();
}

int ans_pref;
int ansL, ansR;

string fans;

void make_ans() {
	fans = "";
	for (int i = 0; i < ans_pref; i++)
		fans += s[i];
	for (int i = 0; i < ansL; i++)
		fans += s[i + ans_pref];
	int n = s.size();
	for (int i = 0; i < ansR; i++)
		fans += s[n - ans_pref - ansR + i];
	for (int i = 0; i < ans_pref; i++)
		fans += s[n - ans_pref + i];
}

struct hasher{
	vector<int> p;
	vector<int> hash;
	int MOD;
	int base;
	int n;

	int mul(int a, int b) {
		return (ll) a * b % MOD;
	}

	int add(int a, int b) {
		a += b;
		if (a >= MOD) a -= MOD;
		return a;
	}

	int sub(int a, int b) {
		a -= b;
		if (a < 0)
			a += MOD;
		return a;
	}

	hasher() {}
	hasher(string s, int _MOD, int _base) {
		n = s.size();
		p.assign(n + 1, 1);
		MOD = _MOD;
		base = _base;
		hash.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			p[i] = mul(p[i - 1], base);
			hash[i] = add(mul(hash[i - 1], base), s[i - 1]);
		}
	}

	int get(int l, int r) {
		return sub(hash[r], mul(hash[l - 1], p[r - l + 1]));
	}
};

hasher h1, h2, r1, r2;

bool check(int l, int r) {
	l++;
	r++;
	return h1.get(l, r) == r1.get(n - r + 1, n - l + 1) && h2.get(l, r) == r2.get(n - r + 1, n - l + 1);
}

vector<int> make_d1() {
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		int l = 1, r = min(n - i + 1, i + 2);
		while (l < r - 1) {
			int mid = (l + r) / 2;
			if (check(i - mid + 1, i + mid - 1)) 
				l = mid;
			else
				r = mid;
		}
		ans[i] = l;
	}
  	return ans;
}

vector<int> make_d2() {
	vector<int> ans(n);
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) continue;
		int l = 1, r = min(n - i + 1, i + 1);
		while (l < r - 1) {
			int mid = (l + r) / 2;
			if (check(i - mid, i + mid - 1)) 
				l = mid;
			else
				r = mid;
		}
		ans[i] = l;
	}
	return ans;
}

vector<int> d1, d2;

mt19937 rnd(time(0));

const int MOD1 = 998244353, MOD2 = 1e9 + 7;
const int base1 = rnd() % 1000 + 228 + 1337, base2 = rnd() % 1000 + 228 + 1337;

void build() {
	h1 = hasher(s, MOD1, base1);
	h2 = hasher(s, MOD2, base2);
	reverse(all(s));
	r1 = hasher(s, MOD1, base1);
	r2 = hasher(s, MOD2, base2);
	reverse(all(s));
	d1 = make_d1();
	d2 = make_d2();
}

void relax(int fans_pref, int fansL, int fansR) {
	if (fans_pref * 2 + fansL + fansR <= ans_pref * 2 + ansL + ansR) return;
	ans_pref = fans_pref;
	ansL = fansL;
	ansR = fansR;
}

void run() {
	ans_pref = 0;
	ansL = 0;
	ansR = 0;
	build();
	int mx_pref = 0;

	for (int i = 0; i < n && n - 1 - i > i; i++) {
		if (s[i] != s[n - 1 - i]) break;
		mx_pref++;
	}

	/*cout << mx_pref << endl;

	cout << "d1 = " << endl;
	for (auto i : d1)
		cout << i << " ";
	cout << endl;

	cout << "d2 = " << endl;
	for (auto i : d2)
		cout << i << " ";
	cout << endl;*/

	for (int i = 0; i < n; i++) {
		int posL = i - d1[i] + 1;
		int posR = i + d1[i] - 1;
		int len1 = posL;
		int len2 = n - posR - 1;
		//if (i == 2)
		//cout << posL << " " << posR << " " << len1 << " " << len2 << endl; 
		if (len1 <= len2) {
			if (mx_pref < len1) continue;
			relax(len1, d1[i] * 2 - 1, 0);
		} else {
			if (mx_pref < len2) continue;
			relax(len2, 0, d1[i] * 2 - 1);
		}
	}

	for (int i = 0; i < n; i++) {
		int posL = i - d2[i];
		int posR = i + d2[i] - 1;
		int len1 = posL;
		int len2 = n - posR - 1;
		if (len1 <= len2) {
			if (mx_pref < len1) continue;
			relax(len1, d2[i] * 2, 0);
		} else {
			if (mx_pref < len2) continue;
			relax(len2, 0, d2[i] * 2);
		}
	}
	//cout << ans_pref << " " << ansL << " " << ansR << endl;
	make_ans();
}

void write() {
	cout << fans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {	
		read();
		run();
		write();
	}
	return 0;
}