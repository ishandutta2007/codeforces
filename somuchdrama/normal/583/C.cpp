#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<int, int, greater<int> > kek;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int n;
    cin >> n;
	int sz = n * n;
    for (int i = 0; i < sz; ++i) {
    	int x;
    	cin >>x;
    	++kek[x];
	}

	int cnt = 0;
	for (map <int, int> :: iterator i = kek.begin(); i != kek.end(); ++i) {
		int cur = i->ff;
		while (i->ss) {
			ans.pb(cur);
			--(i->ss);
			for (int j = 0; j < cnt; ++j) 
				kek[__gcd(ans[cnt], ans[j])] -= 2;

			++cnt;
		}
	}

	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';

    return 0;
}