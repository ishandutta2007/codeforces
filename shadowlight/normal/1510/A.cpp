#include <bits/stdc++.h>
#define ll long long
#define db long double
#define plus asodfiasjdoas
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

string s;

void concate(vector<string> &a, vector<string> b) {
	int n = max(a.size(), b.size());
	int m = a[0].size() + 2 + b[0].size();
	vector <string> c(n, string(m, ' '));
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < (int) a[0].size(); ++j) {
			c[i][j] = a[i][j];
		}	
	}

	for (int i = 0; i < b.size(); ++i) {
		for (int j = 0; j < b[0].size(); ++j) {
			c[i][j + a[0].size() + 2] = b[i][j];
		}
	}

	c[1][a[0].size()] = '-';
	c[1][a[0].size() + 1] = '>';
	a = c;
}

void plus(vector<string> &a) {
	int n = a.size() + 2;
	int m = a[0].size() + 6;
	vector <string> c(n, string(m, ' '));

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[0].size(); ++j) {
			c[i][j + 3] = a[i][j];
		}
	}
	c[1][0] = '+';
	c[1][1] = '-';
	c[1][2] = '>';
	c[1][a[0].size() + 3] = '-';
	c[1][a[0].size() + 1 + 3] = '>';
	c[1][a[0].size() + 2 + 3] = '+';
	
	for (int i = 2; i < n - 1; ++i) {
		c[i][0] = '|';
		c[i][m - 1] = '|';
	}
	for (int j = 2; j < m - 1; ++j) {
		c[n - 1][j] = '-';
	}
	c[n - 1][0] = '+';
	c[n - 1][1] = '<';
	c[n - 1][m - 1] = '+';
	a = c;
}

void qmark(vector<string>& a) {
	int n = a.size() + 3;
	int m = a[0].size() + 6;
	vector <string> c(n, string(m, ' '));

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[0].size(); ++j) {
			c[i + 3][j + 3] = a[i][j];
		}
	}
	c[1 + 3][0] = '+';
	c[1 + 3][1] = '-';
	c[1 + 3][2] = '>';
	c[1 + 3][a[0].size() + 3] = '-';
	c[1 + 3][a[0].size() + 1 + 3] = '>';
	c[1 + 3][a[0].size() + 2 + 3] = '+';
	
	for (int i = 2; i < 4; ++i) {
		c[i][0] = '|';
		c[i][m - 1] = '|';
	}
	for (int j = 1; j < m - 2; ++j) {
		c[1][j] = '-';
	}
	c[1][0] = '+';
	c[1][m - 2] = '>';
	c[1][m - 1] = '+';
	a = c;
}

void star(vector<string>& a) {
	int n = a.size() + 5;
	int m = a[0].size() + 6;
	vector <string> c(n, string(m, ' '));

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[0].size(); ++j) {
			c[i + 3][j + 3] = a[i][j];
		}
	}
	
	for (int i = 2; i < n - 1; ++i) {
		c[i][0] = '|';
		c[i][m - 1] = '|';
	}
	c[1 + 3][0] = '+';
	c[1 + 3][1] = '-';
	c[1 + 3][2] = '>';
	c[1 + 3][a[0].size() + 3] = '-';
	c[1 + 3][a[0].size() + 1 + 3] = '>';
	c[1 + 3][a[0].size() + 2 + 3] = '+';

	for (int j = 1; j < m - 1; ++j) {
		c[1][j] = '-';
		c[n - 1][j] = '-';
	}
	c[1][0] = '+';
	c[1][m - 2] = '>';
	c[1][m - 1] = '+';
	c[n - 1][0] = '+';
	c[n - 1][1] = '<';
	c[n - 1][m - 1] = '+';
	a = c;
}

void concate_down(vector<string>& c, vector<vector<string>> atoms) {
	if (atoms.size() == 1) {
		c = atoms[0];
		return;
	}
	int n = atoms[0].size();
	int m = atoms[0][0].size();
	for (int i = 1; i < (int) atoms.size(); ++i) {
		n += 1 + atoms[i].size();
		m = max(m, (int) atoms[i][0].size());
	}
	m += 6;

	c.clear();
	c.resize(n, string(m, ' '));

	for (int i = 1; i < n - 1 - atoms.back().size() + 2; ++i) {
		c[i][0] = '|';
		c[i][m - 1] = '|';
	}

	int now = 0;
	for (int it = 0; it < (int) atoms.size(); ++it) {
		auto a = atoms[it];
		
		for (int i = 0; i < a.size(); ++i) {
			for (int j = 0; j < a[0].size(); ++j) {
				c[i + now][j + 3] = a[i][j];
			}
		}

		c[now + 1][0] = '+';
		c[now + 1][1] = '-';
		c[now + 1][2] = '>';
		for (int j = a[0].size() + 3; j < m; ++j) {
			c[now + 1][j] = '-';
		}
		c[now + 1][m - 2] = '>';
		c[now + 1][m - 1] = '+';
		now += a.size() + 1;
	}
}

void create(vector<string>& a, string inside) {
	int n = 3;
	int m = inside.size() + 4;

	a.clear();
	a.resize(n, string(m, ' '));

	for (int i = 0; i < (int) inside.size(); ++i) {
		a[1][i + 2] = inside[i];
	}
	a[1][0] = '+';
	a[1][m - 1] = '+';
	a[0][0] = '+';
	a[0][m - 1] = '+';
	a[n - 1][0] = '+';
	a[n - 1][m - 1] = '+';
	for (int i = 1; i < m - 1; ++i) {
		a[0][i] = '-';
		a[n - 1][i] = '-';
	}
}

vector<string> parse(int l, int r, bool is_expr = true) {
	if (is_expr) {
		int bal = 0;
		int pr = l;
		vector<vector<string>> atoms;
		for (int i = l; i < r; ++i) {
			if (s[i] == '(') {
				++bal;
			} else if (s[i] == ')') {
				--bal;
			} else if (s[i] == '|' && !bal) {
				atoms.pb(parse(pr, i, false));
				pr = i + 1;
			}
		}
		//cout << "SEG: " << pr << " " << r << endl;
		atoms.pb(parse(pr, r, false));
		vector<string> res;
		concate_down(res, atoms);
		return res;
	}
	vector<vector<string>> atoms;
	string cur = "";
	for (int i = l; i < r; ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			cur += s[i];
			continue;
		}
		if (s[i] == '(') {
			if (cur.size()) {
				vector<string> a;
				create(a, cur);
				atoms.pb(a);
				cur = "";
			}
			int bal = 0;
			int was = i;
			for (; i < r; ++i) {
				if (s[i] == '(') {
					++bal;
				} else if (s[i] == ')') {
					--bal;
				}
				if (bal == 0) {
					atoms.pb(parse(was + 1, i, true));
					break;
				}
			}
			continue;
		}
		if (cur.size()) {
			vector<string> a, b;
			if (cur.size() > 1) {
				create(a, cur.substr(0, cur.size() - 1));
				atoms.pb(a);
			}
			create(b, cur.substr(cur.size() - 1, 1));
			atoms.pb(b);
			cur = "";
		}
		if (s[i] == '+') {
			plus(atoms.back());
			continue;
		}
		if (s[i] == '?') {
			qmark(atoms.back());
			continue;
		}
		if (s[i] == '*') {
			star(atoms.back());
			continue;
		}
		cout << "PARASHA: " << i << " " << s[i] << endl;
		assert(false);
	}
	if (cur.size()) {
		vector<string> a;
		create(a, cur);
		atoms.pb(a);
		cur = "";
	}
	auto now = atoms[0];
	for (int i = 1; i < (int) atoms.size(); ++i) {
		concate(now, atoms[i]);
	}
	return now;
}

void add_final(vector<string>& a) {
	int n = a.size();
	int m = a[0].size() + 6;
	vector<string> c(n, string(m, ' '));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int) a[0].size(); ++j) {
			c[i][j + 3] = a[i][j];
		}
	}
	c[1][0] = 'S';
	c[1][1] = '-';
	c[1][2] = '>';

	c[1][m - 3] = '-';
	c[1][m - 2] = '>';
	c[1][m - 1] = 'F';
	a = c;
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	int n = s.size();

	auto res = parse(0, n);
	add_final(res);

	cout << res.size() << " " << res[0].size() << endl;

	for (int i = 0; i < (int) res.size(); ++i) {
		cout << res[i] << "\n";
	}
}