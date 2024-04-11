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

int n;
bitset<MAXN> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	string ans = s.to_string();
	for (int i = 0; i < 30; i++)
		ans = max(ans, (s | (s >> i)).to_string());
	
	reverse(all(ans));
	while (ans.back() == '0' && int(ans.size()) > 1) ans.pop_back();
	reverse(all(ans));
	cout << ans << endl;
	return 0;
}