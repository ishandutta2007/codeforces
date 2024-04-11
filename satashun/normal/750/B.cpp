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

int n;
int c = 0;
bool ok = 1;

int main() {
	cin >> n;
	rep(i, n) {
		int t;
		string dir;
		cin >> t >> dir;
		if (c == 0 && dir != "South") ok = 0;
		if (c == 20000 && dir != "North") ok = 0;
		if (dir == "South") {
			if (c + t > 20000) {
				ok = 0;
			}
			c += t;
		} else if (dir == "North") {
			if (c - t < 0) {
				ok = 0;
			}
			c -= t;
		}
	}
	if (c != 0) ok = 0;
	puts(ok ? "YES" : "NO");
	return 0;
}