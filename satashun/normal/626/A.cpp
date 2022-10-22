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

int ret;
int n;
string s;

int main() {
	cin >> n >> s;

	rep(i, n) {
		int x = 0, y = 0;
		for (int j = i; j < n; ++j) {
			if (s[j] == 'U') ++y;
			else if (s[j] == 'D') --y;
			else if (s[j] == 'R') ++x;
			else --x;
			if (x == 0 && y == 0) ++ret;
		}
	}
	cout << ret << endl;

	return 0;
}