#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, q;
string s;
set<int> st;

inline void F(int ind) {
	if (ind < n - 2 && s[ind] == 'a' && s[ind + 1] == 'b' && s[ind + 2] == 'c')
		st.insert(ind);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q >> s;

	for (int i = 0; i < n; i++)
		F(i);

	while (q--) {
		int i;
		char c;
		cin >> i >> c;

		i--;
		st.erase(i);
		st.erase(i - 1);
		st.erase(i - 2);
		s[i] = c;
		F(i);
		F(i - 1);
		F(i - 2);

		cout << st.size() << endl;
	}
	return 0;
}