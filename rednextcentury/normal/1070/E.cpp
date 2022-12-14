#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200100

ll n, m, t;
ll BIT[N], BIT2[N]; 
ll a[N];
map<ll, ll> hs;
vector<int> idx[N];
set<pair<ll, ll> > have;
ll mxTasks, bestD, cnt;

void update(int i, ll val) {
	while (i <= n) {
		if (val > 0) BIT2[i] += 1; 
		else if (val < 0) BIT2[i] += -1;
		BIT[i] += val, i += (i & (-i)); 
	}
}

ll query(int i) {
	ll ret = 0; 
	while (i) ret += BIT[i], i -= (i & (-i)); 
	return ret; 
}

ll query1(int i) {
	int tot = have.size();
	tot = tot - i;
	int idx = 0; 
	for (int j = 20; j >= 0; j--) {
		if (idx + (1 << j) > n) continue; 
		int now = idx + (1 << j);
		if (BIT2[now] <= tot) {
			tot -= BIT2[now];
			idx += (1 << j);
		}
	}
	return query(n) - query(idx); 
}

void init() {
	for (int i = 1; i <= n; i++) BIT[i] = BIT2[i] = 0;
}

ll calcTime(){
	int tot = have.size();
	if (tot == 0) return 0;
	ll extra = tot % m;
	if (extra == 0) extra = m;
	ll ans = cnt - query1(extra);
	return ans;
}

void solve(ll p){
	ll h = hs[p];
	for (int j = 0; j < idx[h].size(); j++){
		int i = idx[h][j];
		have.insert(make_pair(i, p));
		update(i, p);
		cnt += 2 * p;
	}
	while (calcTime() > t){
		assert(have.size() > 0);
		ll i = have.rbegin()->first, p = have.rbegin()->second;
		have.erase(make_pair(i, p));
		update(i, -p);
		cnt -= 2 * p;
	}
	
	ll tasks = have.size();
	if (mxTasks < tasks) mxTasks = tasks, bestD = p;
}

int main(){
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	
	int ts; cin >> ts;
	while (ts--){
		cin >> n >> m >> t;
		init(); hs.clear(); have.clear();
		for (int i = 1; i <= n; i++) cin >> a[i], hs[a[i]];
		ll hsCnt = 0;
		for (map<ll, ll>::iterator it = hs.begin(); it != hs.end(); it++) it->second = hsCnt++;
		for (int i = 0; i <= hsCnt; i++) idx[i].clear();
		for (int i = 1; i <= n; i++){
			ll h = hs[a[i]];
			idx[h].push_back(i);
		}

		mxTasks = 0, bestD = 1, cnt = 0;
		for (map<ll, ll>::iterator it = hs.begin(); it != hs.end(); it++){
			if (it->first > t) break;
			solve(it->first);
		}
		cout << mxTasks << " " << bestD << endl;
	}

	return 0;
}