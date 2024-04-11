#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, m;
vector <vector <int> > g;
void read() {
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (a > b)
			swap(a, b);
		g[b].push_back(n - (b - a));
		g[a].push_back(b - a);
	}

	for (int i = 0; i < n; i++) {
		sort(g[i].begin(), g[i].end());
	}
}

vector<int> z_function (vector <int> s) {
	int n = (int) s.size();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

string ans = "No";

void run() {
	vector <int> good;
	for (int i = 0; i < n; i++) {
		good.push_back((int) g[i].size());
		for (auto j : g[i])
			good.push_back(j);
		good.push_back(-1);
	}

/*	cout << "good = " << endl;
	for (auto i : good) {
		cout << i << " ";
	}
*/
	vector <int> fhelp = good;
	fhelp.push_back(-10);
	for (auto i : good)
		fhelp.push_back(i);
	for (auto i : good)
		fhelp.push_back(i);

/*	cout << "fhelp = " << endl;
	for (auto i : fhelp) {
		cout << i << " ";
	}
	cout << endl;*/
	fhelp = z_function(fhelp);

	/*cout << "z = " << endl;
	for (auto i : fhelp) 
		cout << i << " ";
	cout << endl;
	cout << good.size() << endl;*/
	for (int i = good.size() + 2; i < fhelp.size(); i++) {
		if (i == (int) good.size() * 2 + 1)
			continue;
		if (fhelp[i] == (int) good.size()) {
			//cout << i << endl;
			ans = "Yes";
			break;
		}
	}

}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}