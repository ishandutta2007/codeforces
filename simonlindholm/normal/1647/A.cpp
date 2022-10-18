#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	rep(i,0,N) {
		int a;
		cin >> a;
		int len = a / 3;
		string s;
		if (a % 3 == 0) {
			rep(j,0,len) {
				s += "21";
			}
		} else if (a % 3 == 1) {
			s += "1";
			rep(j,0,len) {
				s += "21";
			}
		} else {
			s += "2";
			rep(j,0,len) {
				s += "12";
			}
		}
		cout << s << endl;
	}
}