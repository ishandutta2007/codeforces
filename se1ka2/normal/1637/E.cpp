#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> v[300005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		ll a[300005];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int c = 0;
		bool b[300005];
		for(int i = 0; i <= n; i++) b[i] = false;
		vector<ll> w;
		for(int i = n - 1; i >= 0; i--){
			c++;
			if(i == 0 || a[i] != a[i - 1]){
				w.push_back(a[i]);
				v[c].push_back(a[i]);
				b[c] = true;
				c = 0;
			}
		}
		vector<int> r;
		for(int c = 0; c <= n; c++){
			if(b[c]) r.push_back(c);
		}
		unordered_set<ll> st;
		for(int i = 0; i < m; i++){
			ll x, y;
			cin >> x >> y;
			st.insert(x * 1000000000 + y);
			st.insert(x + y * 1000000000);
		}
		ll ans = 0;
		c = 0;
		for(int i = n - 1; i >= 0; i--){
			c++;
			if(i == 0 || a[i] != a[i - 1]){
				ll x = a[i];
				for(int e : r){
					for(ll y : v[e]){
						if(x != y && st.find(x * 1000000000 + y) == st.end()){
							ans = max(ans, (c + e) * (x + y));
							break;
						}
					}
				}
				c = 0;
			}
		}
		for(int c : r) v[c].clear();
		cout << ans << "\n";
	}
}