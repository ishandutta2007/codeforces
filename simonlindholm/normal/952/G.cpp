#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	string str;
	getline(cin, str);
	int cur = 0;
	trav(c, str) {
		string line(300 * 2, '.');
		cout << line << endl;
		int dif = (int)(unsigned char)(cur - c);
		if (dif == 0) dif = 256;
		cur = (int)c;
		rep(i,0,dif) line[i*2] = 'X';
		cout << line << endl;
		line.assign(300 * 2, '.');
		line[0] = 'X';
		cout << line << endl;
	}
}