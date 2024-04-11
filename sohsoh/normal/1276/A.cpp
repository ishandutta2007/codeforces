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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool B[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s, s2;
		cin >> s;
		vector<int> ans, T;
		for (int i = 0; i < s.size(); i++)
			if (i + 4 < s.size() && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4])
				ans.push_back(i + 2), B[i + 2] = true;
		for (int i = 0; i < s.size(); i++)
			if (!B[i])
				s2.push_back(s[i]), T.push_back(i);

		s = s2;
		for (int i = 0; i + 2 < s.size(); i++) 
			if ((s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') || (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o'))
				ans.push_back(T[i + 1]);
		cout << ans.size() << endl;
		for (int i : ans) cout << i + 1 << sep;
		cout << endl;
		for (int i : ans) B[i] = false;	
	}	
	return 0;
}