// Sohsoh84 O_o //
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;


int n;

vector<int> Ask(int v) {
	cout << "? " << v << endl;
	vector<int> ans = {0};
	for (int i = 1; i <= n; i++) {
		int d;
		cin >> d;
		ans.push_back(d);
	}

	return ans;
}

vector<pll> ans;

int main() {
	cin >> n;
	vector<int> T, O, E;
	T = Ask(1);

	for (int i = 2; i <= n; i++) {
		if (T[i] & 1) O.push_back(i);
		else E.push_back(i);
	}
	
	if (E.size() <= O.size()) {
		for (int v = 1; v <= n; v++)
		       if (T[v] == 1)
		       	     ans.push_back({1, v});
		for (int e : E) {
			vector<int> D = Ask(e);
			for (int v = 1; v <= n; v++) 
				if (D[v] == 1)
					ans.push_back({e, v});
		} 
	} else {
		for (int e : O) {
			vector<int> D = Ask(e);
			for (int v = 1; v <= n; v++) {
				if (D[v] == 1) ans.push_back({e, v});
			}
		}
	}

	cout << "!" << endl;
	for (pll e : ans) cout << e.X << sep << e.Y << endl;

	return 0;
}