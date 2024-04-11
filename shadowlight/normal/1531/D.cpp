#include <bits/stdc++.h>
#define ll long long
#define db long double
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

set <int> unlocks;
set <int> locks;

map <string, int> color_num;
vector<string> colors = {"orange", "yellow", "red", "green", "blue", "indigo", "violet"};

struct Tree {
	int n;
	vector <int> t;
	vector <int> tcol;
	vector <bool> locked;
	vector <int> val;

	void relax(int v) {
		if (t[2 * v + 1] != -1) {
			t[v] = t[2 * v + 1];
		} else {
			t[v] = t[2 * v];
		}
		if (tcol[2 * v + 1] != -1) {
			tcol[v] = tcol[2 * v + 1];
		} else {
			tcol[v] = tcol[2 * v];
		}
	}

	void add_val(int v, int valt) {
		//cout << "ADD_VAL: " << v << " " << valt << endl;
		if (valt == 0) {
			t[v] = tcol[v];
			locked[v] = false;
			val[v] = 0;
		} else if (valt == 1) {
			t[v] = -1;
			locked[v] = true;
			val[v] = 1;
		}
	}

	void push(int v) {
		add_val(2 * v, val[v]);
		add_val(2 * v + 1, val[v]);
		val[v] = -1;
	}

	void build(int v, int l, int r, vector<int>& colors, vector<bool>& locks) {
		if (r - l == 1) {
			t[v] = (locks[l] ? -1 : colors[l]);
			locked[v] = locks[l];
			tcol[v] = colors[l];
			return;
		}
		int m = (l + r) / 2;
		build(2 * v, l, m, colors, locks);
		build(2 * v + 1, m, r, colors, locks);
		relax(v);
	}

	Tree(int n, vector<int> &colors, vector<bool>& locks) : n(n),
									   t(4 * n, -1), 
									   tcol(4 * n, -1),
									   locked(4 * n, -1),
									   val(4 * n, -1) 
	{
		build(1, 0, n, colors, locks);
	} 

	Tree() {}

	void add_seg(int l, int r, int x, int vt, int lt, int rt) {
		if (l >= rt || lt >= r) {
			return;
		}
		if (l <= lt && rt <= r) {
			add_val(vt, x);
			return;
		}
		int mt = (lt + rt) / 2;
		push(vt);
		add_seg(l, r, x, 2 * vt, lt, mt);
		add_seg(l, r, x, 2 * vt + 1, mt, rt);
		relax(vt);
	}

	void add_seg(int l, int r, int x) {
		add_seg(l, r, x, 1, 0, n);
	}

	void change(int p, int x, bool state, int vt, int lt, int rt) {
		if (lt > p || rt <= p) {
			return;
		}
		if (rt - lt == 1) {
			t[vt] = (state ? -1 : x);
			locked[vt] = state;
			tcol[vt] = x;
			return;
		}
		int mt = (lt + rt) / 2;
		push(vt);
		change(p, x, state, 2 * vt, lt, mt);
		change(p, x, state, 2 * vt + 1, mt, rt);
		relax(vt);
	}

	void change(int p, int x, int state) {
		change(p, x, state, 1, 0, n);
	}

	bool get_lock(int pos, int vt, int lt, int rt) {
		if (pos == -1) {
			return false;
		}
		if (rt - lt == 1) {
			//cout << "GET: " << vt << " " << locked[vt] << endl;
			return locked[vt];
		}
		int mt = (lt + rt) / 2;
		
		push(vt);
		bool lck;
		if (pos < mt) {
			lck = get_lock(pos, 2 * vt, lt, mt);
		} else {
			lck = get_lock(pos, 2 * vt + 1, mt, rt);
		}
		relax(vt);
		return lck;
	}

	bool get_lock(int pos) {
		return get_lock(pos, 1, 0, n);
	}
};

Tree tree;

string get_res() {
	if (tree.t[1] == -1) {
		return "blue";
	}
	return colors[tree.t[1]];
}


int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector <bool> locked;
	vector <int> cs;

	for (int i = 0; i < (int) colors.size(); ++i) {
		color_num[colors[i]] = i;
	}

	int n;
	cin >> n;

	vector <string> messages(n);

	bool locked_now = false;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		messages[i] = s;
		int col = -1;
		if (s == "lock") {
			locked_now = true;
			locks.insert(i);
		} else if (s == "unlock") {
			locked_now = false;
			unlocks.insert(i);
		} else {
			col = color_num[s];
		}
		cs.pb(col);
		locked.pb(locked_now);
	}

	tree = Tree(n, cs, locked);

	cout << get_res() << "\n";

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int pos;
		string s;
		cin >> pos >> s;
		--pos;
		if (messages[pos] == "lock") {
			locks.erase(pos);
		} else if (messages[pos] == "unlock") {
			unlocks.erase(pos);
		}
		messages[pos] = s;
		int col = -1;
		bool lck = tree.get_lock(pos - 1);
		//cout << "LOCK? " << pos - 1 << " " << lck << endl;
		if (messages[pos] == "lock") {
			locks.insert(pos);
			lck = true;
		} else if (messages[pos] == "unlock") {
			unlocks.insert(pos);
			lck = false;
		} else {
			col = color_num[messages[pos]];
		}

		int lt = pos;
		int rt = -1;
		if (lck) {
			if (unlocks.lower_bound(pos) == unlocks.end()) {
				rt = n;
			} else {
				rt = *unlocks.lower_bound(pos);
			}
		} else {
			if (locks.lower_bound(pos) == locks.end()) {
				rt = n;
			} else {
				rt = *locks.lower_bound(pos);
			}
		}
		tree.change(pos, col, lck);
		tree.add_seg(lt, rt, lck);

		cout << get_res() << "\n";
	}
}