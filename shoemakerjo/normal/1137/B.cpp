#include <bits/stdc++.h>

using namespace std;

const int maxn = 500010;
string s, t;

int res[maxn];

int sl, tl;

int z[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> t;
	sl = s.length();
	tl = t.length();
	// s = " " + s;
	// t = " " + t;

	for (int i = 1, l = 0, r = 0; i < tl; ++i) {
		if (i <= r) {
			z[i] = min(r-i+1, z[i-l]);
		}
		while (i+z[i] < tl && t[z[i]] == t[i+z[i]]) 
			++z[i];
		if (i + z[i] -1 > r) 
			l = i, r = i + z[i]-1;
	}
	//find longest suffix of t that is also a prefix of t

	int ls = 0;
	for (int i = 1; i < tl; i++) {
		if (z[i] == tl - i) {
			ls = max(ls, tl-i);
		}
	}


	vector<int> v;
	for (int i = ls; i < tl; i++) {
		v.push_back(i);
	}

	int cind = -1;

	for (int i = 0; i < sl && i < tl; i++) {
		res[i] = t[i] - '0';
	}

	for (int i = ls; i < sl; i++) {
		++cind;
		cind %= v.size();

		res[i] = t[v[cind]] - '0';
	}

	int zgoal = 0, ogoal = 0;
	int zcur = 0, ocur = 0;

	for (int i = 0; i < sl; i++) {
		if (res[i] == 0) zcur++;
		else ocur++;

		if (s[i] == '0') zgoal++;
		else ogoal++;
	}

	for (int i = sl-1; i >= 0; i--) {
		if (res[i] == 0) {
			if (zcur > zgoal) {
				zcur--;
				ocur++;
				res[i] = 1;
			}
		}
		else {
			if (ocur > ogoal) {
				ocur--;
				zcur++;
				res[i] = 0;
			}
		}
	}

	for (int i = 0; i < sl; i++) {
		cout << res[i];
	}
	cout << endl;

}