#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl

int main() {
	string s; cin >> s;
	bool ok = false;
	rep(i, 5) {
		string t; cin >> t;
		if (s[0] == t[0] || s[1] == t[1]) {
			ok = true;
		}
	}
	puts(ok ? "YES" : "NO");
	return 0;
}