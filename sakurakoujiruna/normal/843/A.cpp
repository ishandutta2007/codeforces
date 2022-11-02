#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int N = 1e5L + 11;
int a[N];

bool vis[N];

int main() {
	ios :: sync_with_stdio(0);
	int n; cin >> n;
	map <int, int> mp;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		mp[a[i]] = 0;
	}
	int cnt = 0;
	for(auto &p : mp)
		p.second = ++ cnt;
	
	for(int i = 1; i <= n; i ++)
		a[i] = mp[a[i]];
	
	vector <vi> v;
	for(int i = 1; i <= n; i ++) if(!vis[i]) {
		vi u = {i}; vis[i] = 1;
		for(int j = a[i]; !vis[j]; j = a[j]) {
			vis[j] = 1;
			u.pb(j);
		}
		v.pb(u);
	}
	
	cout << v.size() << '\n';
	for(auto u : v) {
		cout << u.size();
		for(int x : u) cout << ' ' << x;
		cout << '\n';
	}
	
	return 0;
}