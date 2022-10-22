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

const ll MAXN = 19;
const ll INF = 1e8;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool dp[1 << MAXN];
int mask;
vector<vector<int>> lines = {
	{0, 1, 2}, 
	{3, 4, 5, 6}, 
	{7, 8, 9, 10, 11},
	{12, 13, 14, 15}, 
	{16, 17, 18},
	{0, 3, 7}, 
	{1, 4, 8, 12}, 
	{2, 5, 9, 13, 16},
	{6, 10, 14, 17}, 
	{11, 15, 18},
	{2, 6, 11}, 
	{1, 5, 10, 15},
	{0, 4, 9, 14, 18},
	{3, 8, 13, 17},
	{7, 12, 16}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 19; i++) {
		char c;
		cin >> c;
		if (c == 'O') mask ^= (1 << i);
	}

	dp[0] = 0;
	for (int msk = 1; msk < (1 << 19); msk++) {
		for (vector<int> l : lines) {
			for (int L = 0; L < l.size(); L++) {	
				int tmsk = msk;
				for (int R = L; R < l.size(); R++) {
					if (!(msk & (1 << l[R]))) break;
					tmsk ^= (1 << l[R]);
					dp[msk] |= !dp[tmsk];
				}
			}
		}
	}
	
	cout << (dp[mask] ? "Karlsson" : "Lillebror") << endl;
	return 0;
}