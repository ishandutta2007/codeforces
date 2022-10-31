#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#include <array>
#include <string>
#include <set>
#include <map>
#include <cassert>


using namespace std;


#define ll long long
#define ld long double
#define flt double
#define bp push_back
#define emb empalce_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define prcs cout << fixed << setprecision(10)
#define nlpt nullptr


mt19937_64 rnd(132123);

ll inf = 1e18;



struct DSU {
	int n;

	vector<int> t;


	void build(int _n) {
		n = _n;
		t.resize(n);
		for (int i = 0; i < n; i += 1) {
			t[i] = i;
		}
	}

	int get(int v) {
		if (t[v] == v) {
			return v;
		}
		return (t[v] = get(t[v]));
	}


	void mrg(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return;
		}
		t[a] = b;
	}
};


int n;
vector<int> p;
DSU dsu;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		p.resize(n);
		for (int i = 0; i < n; i += 1) {
			cin >> p[i];
			p[i] -= 1;
		}
		vector<int> go(n);
		dsu.build(n);
		for (int i = 0; i < n; i += 1) {
			go[p[i]] = i;
			dsu.mrg(p[i], i);
		}
		for (int i = 0; i < n - 1; i += 1) {
			if (dsu.get(i) != dsu.get(i + 1)) {
				swap(go[i], go[i + 1]);
				dsu.mrg(i, i + 1);
			}
		}
		vector<int> q;
		q.reserve(n);
		int i = 0;
		while (1) {
			q.push_back(i);
			i = go[i];
			if (i == 0) {
				break;
			}
		}
		for (int i = 0; i < n; i += 1) {
			cout << q[i] + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}

/*
1
2 3 5 4
AABAABBABAAABABBABBBABB
*/