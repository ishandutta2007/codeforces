#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// departure, arrival, add
struct event {
	ll t;
	int type, pass;

	bool operator< (const event& oth) const {
		return make_tuple(t, type, pass) > make_tuple(oth.t, oth.type, oth.pass);
	}
};

const int MAXN = 1e5 + 5;
priority_queue<event> proc;
priority_queue<int, vector<int>, greater<int>> waitlist;
set<int> went;
queue<int> Q;
int n;
bool freee;
ll p, ans[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> p;
	for(int i = 1; i <= n; i++) {
		ll t;
		cin >> t;
		proc.push({t, 0, i});
	}
	freee = true;
	while(proc.size()) {
		auto e = proc.top(); proc.pop();
		//cout << e.t << " " << e.type << " " << e.pass << endl;
		if(e.type == 2) {
			freee = true;
			ans[e.pass] = e.t;
			went.erase(e.pass);
		}
		if(e.type == 1)
			Q.push(e.pass);
		if(e.type == 0)
			waitlist.push(e.pass);
		if(freee && Q.size()) {
			int i = Q.front(); Q.pop();
			proc.push({e.t + p, 2, i});
			freee = false;
		}
		if(waitlist.size() && went.empty() || *went.begin() > waitlist.top()) {
			int i = waitlist.top(); waitlist.pop();
			went.insert(i);
			proc.push({e.t, 1, i});
		}
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
}