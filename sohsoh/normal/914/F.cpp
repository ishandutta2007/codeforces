// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;
const ll N = 26;

bitset<MAXN> C[N], ans;
string A;
int n, q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> A >> q;
	n = A.size();
	for (int i = 0; i < n; i++) {
		char c = A[i];
		C[c - 'a'].set(i);
	}

	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int ind;
			char c;
			cin >> ind >> c;
			ind--;
			
			C[A[ind] - 'a'].reset(ind);
			C[c - 'a'].set(ind);	
			A[ind] = c;
		} else {
			ans.set();
			int l, r;
			string s;
			cin >> l >> r >> s;
			l--, r--;

			for (int i = 0; i < (int) s.size(); i++)
				ans &= (C[s[i] - 'a'] >> i);
			
			ans >>= l;
			int cnt = ans.count();
			ans >>= max(0, r - l - (int) s.size() + 2);
			cnt -= ans.count();
			cout << cnt << endl;
		}
	}
	return 0;
}