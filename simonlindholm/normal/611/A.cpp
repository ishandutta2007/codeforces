#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	string str;
	cin >> str >> str;
	int count = 0;
	if (str == "week") {
		rep(i,0,366) {
			if ((4+i) % 7 == N-1)
				count++;
		}
	}
	else {
		int days[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
		assert(str == "month");
		int s = 0;
		rep(i,0,12) {
			if (N <= days[i]) count++;
			s += days[i];
		}
		assert(s == 366);
	}
	cout << count << endl;
}