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
	int nos = 0;
	rep(i,0,10) {
		cout << i << endl;
		string str;
		getline(cin, str);
		string str2;
		trav(x, str) {
			char y = (char)tolower(x);
			if (y == '!' || y == '?' || y == '\'' || y == ' ') continue;
			str2 += y;
		}
		str = str2;
		if (str == "great" || str == "cool" || str == "notbad" || str == "donttouchme" || str == "dontthinkso") {
			cout << "normal" << endl;
			return 0;
		} else if (str == "noway" || str == "areyouserious" || str == "worse" || str == "terrible" || str == "godieinahole" || str == "donteven") {
			cout << "grumpy" << endl;
			return 0;
		}
		if (str != "no") for (;;);
		nos++;
		if (nos > 3) {
			cout << "normal" << endl;
			return 0;
		}
	}
	exit(0);
}