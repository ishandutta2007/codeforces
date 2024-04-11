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
	int N;
	cin >> N;
	rep(i,0,N) {
		int x;
		cin >> x;
		string s;
		cin >> s;
		string t = s;
		sort(all(t));
		int co = 0;
		rep(j,0,x) if (s[j] != t[j]) co++;
		cout << co << endl;
	}
	exit(0);
}