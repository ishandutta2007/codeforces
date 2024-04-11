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

inline bool check2(vector<ll>& vec) {
	for (int i = 0; i < int(vec.size()); i++)
		for (int j = 0; j < i; j++)
			if (find(all(vec), vec[i] + vec[j]) == vec.end())
				return false;
	return true;
}

inline bool check3(vector<ll>& vec) {
	for (int i = 0; i < int(vec.size()); i++)
		for (int j = 0; j < i; j++)
			for (int k = 0; k < j; k++)
				if (find(all(vec), vec[i] + vec[j] + vec[k]) == vec.end())
					return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int cnt0 = 0, cntp = 0, cntn = 0, n;
		vector<ll> vec;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (x == 0) cnt0++;
			else if (x < 0) cntn++, vec.push_back(x);
			else cntp++, vec.push_back(x);
		}

		if (cnt0) vec.push_back(0);

		if (max(cntn, cntp) > 2) cout << "NO" << endl;
		else if (cnt0) cout << (check3(vec) && check2(vec) ? "YES" : "NO") << endl;
		else cout << (check3(vec) ? "YES" : "NO") << endl;
	}
	return 0;
}