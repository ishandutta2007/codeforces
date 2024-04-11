#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct movement {
	int a, b, d;
};

const int MAXN = 3e5 + 5;
int filled[MAXN];
vector<movement> ans;
vector<int> ov, und;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ii> s(n), t(n);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s[i] = {x, i};
	}
	for(int i = 0; i < n; i++) {
	    int x;
	    cin >> x;
	    t[i] = {x, i};
	}
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	for(int i = 0; i < n; i++) {
		if(s[i].first > t[i].first)
			ov.push_back(i);
		if(s[i].first < t[i].first)
			und.push_back(i);
	}
	while(ov.size()) {
		if(und.empty()) {
			cout << "NO\n";
			return 0;
		}
		int i = und.back(), j = ov.back();
		if(s[i].first >= s[j].first) {
		    cout << "NO\n";
		    return 0;
		}
		int d = min(t[i].first - s[i].first, s[j].first - t[j].first);
		s[i].first += d;
		s[j].first -= d;
		ans.push_back({s[i].second + 1, s[j].second + 1, d});
		if(s[i].first == t[i].first)
			und.pop_back();
		if(s[j].first == t[j].first)
			ov.pop_back();
	}
	if(und.size()) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	cout << ans.size() << '\n';
	for(auto m : ans)
		cout << m.a << " " << m.b << " " << m.d << '\n';
}