#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define set sett

typedef vector< int > vi;
typedef vector< vi > vvi;

int sum[2 * 131072 + 10][4][11][10];
string s; 
int sz, q; 

int getnum(char c) {
	if (c == 'A') return 0; 
	if (c == 'T') return 1; 
	if (c == 'G') return 2; 
	if (c == 'C') return 3; 
	assert(false); 
	return -1; 
}

int add(int l0, int v, const string & s) {
	// int shft = (szl[v] - l0) % s.length(); 
	int shft = l0 % s.length();
	int res = 0; 
	for (int i = 0; i < s.length(); i++) {
		int ns = shft + i;
		if (ns >= s.length()) ns -= s.length(); 

		res += sum[v][getnum(s[i])][s.length()][ns];
	}
	return res; 
}

int get(int l, int r, const string & s) {
	int l0 = l, r0 = r; 
	l += sz; 
	r += sz; 
	int res = 0; 

	while (l <= r) {

		if (l % 2) {
			res += add(l0, l, s);
		}

		if (r % 2 == 0) {
			res += add(l0, r, s);
		}

		l = (l + 1) / 2; 
		r = (r - 1) / 2; 
	}

	return res; 
}

void upd(int p, int old, int c) {
	assert(old < 4); 
	assert(c < 4);

	int p0 = p;
	p += sz; 

	while (p >= 1) {
		for (int l = 1; l <= 10; l++) {
			if (old != -1)
				sum[p][old][l][p0 % l]--;
			sum[p][c][l][p0 % l]++;	
		}

		p /= 2;
	}
}

void set(int p, char c) {
	char old = s[p]; 
	s[p] = c; 

	upd(p, getnum(old), getnum(c));
}

int
main()
{
	ios_base::sync_with_stdio(false);

	// cerr << sizeof(sum) / 1024 / 1024 << endl;

	cin >> s; 

	sz = 1; 
	while (sz < s.length()) {
		sz *= 2; 
	}

	for (int i = 0; i < s.length(); i++) {
		upd(i, -1, getnum(s[i]));
	}

	cin >> q; 

	for (int i = 0; i < q; i++) {
		int t; 
		cin >> t; 
		if (t == 1) {
			int p; 
			char c; 
			cin >> p >> c; 

			set(p - 1, c);
		} else {
			int l, r; 
			string t; 
			cin >> l >> r; 
			cin >> t; 
			cout << get(l - 1, r - 1, t) << "\n";
		}
	}

	return 0;
}