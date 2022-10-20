#include <bits/stdc++.h>
#define endl '\n'

#define SZ(x) ((int)x.size())
#define ALL(V) V.begin(), V.end()
#define L_B lower_bound
#define U_B upper_bound
#define pb push_back

using namespace std;
template<class T, class T1> int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
template<class T, class T1> int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }
const int MAXN = (1 << 20);

int n;
int a[MAXN];
int answer[MAXN];
vector<pair<int64_t, int> > que[MAXN];

void read() {
	cin >> n;
	for(int i = 1; i <= n; i++) { 
		cin >> a[i];
	}
}

int vis[MAXN], used[MAXN];
vector<vector<int> > c;

struct mydeque {
	vector<int> vec;
	int& operator[](const unsigned &pos) { return vec[vec.size() - pos - 1]; } 
	unsigned size() { return vec.size(); }
	void push_front(int x) { vec.pb(x); }
};

int q;
int d[MAXN], deg[MAXN];
mydeque dp[MAXN];

void merge(mydeque &a, mydeque &b) {
	if(SZ(a) < SZ(b)) swap(a, b);
	for(int i = 0; i < SZ(b); i++) {
		a[i] += b[i];
	}
}

int idx(int len, int64_t m, int s) {
	int rem = m % s;
	int ans = (len / s) * s + rem;
	if(ans >= len) ans -= s;
	return ans;
}

void solve() {
	cin >> q;
	for(int i = 0; i < q; i++) {
		int64_t m;
		int u;
		cin >> m >> u;
		que[u].pb({m, i});
	}

	int TM = 42;
	for(int i = 1; i <= n; i++) {
		if(!used[i]) {
			int x = i;
			TM++;
			while(!used[x]) {
				used[x] = TM;
				x = a[x];
			}

			if(!vis[x] && used[x] == TM) {
				vector<int> vec;
				while(!vis[x]) {
					vis[x] = 1;
					vec.pb(x);
					x = a[x];
				}
				c.pb(vec);
			}
		}
	}

	queue<int> q;
	for(int i = 1; i <= n; i++) {
		dp[i].vec = {1};
		deg[a[i]]++;
	}

	for(int i = 1; i <= n; i++) {
		if(deg[i] == 0) q.push(i);
	}

	while(!q.empty()) {
		int i = q.front();
		q.pop();

		for(auto it: que[i]) {
			if(SZ(dp[i]) <= it.first) answer[it.second] = 0;
			else answer[it.second] = dp[i][it.first];
		}

		dp[i].push_front(0);
		merge(dp[a[i]], dp[i]);

		deg[a[i]]--;
		if(deg[a[i]] == 0) {
			q.push(a[i]);
		}
	}
	
	for(auto cyc: c) {
		//cout << "here: ";
		//for(int x: cyc) cout << x << " ";
		//cout << endl;

		mydeque tmp;

		int m = SZ(cyc);
		for(int i: cyc) {
			auto cp = dp[i];
			tmp.push_front(0);
			merge(tmp, cp);
		}

		for(int j = 0; j < SZ(tmp); j++) {
			if(j + m < SZ(tmp)) tmp[j + m] += tmp[j];
		}

		for(int i: cyc) {
			tmp.push_front(0);
			merge(tmp, dp[i]);

			for(auto it: que[i]) {
				if(SZ(tmp) <= it.first) answer[it.second] = tmp[idx(SZ(tmp), it.first, m)];
				else answer[it.second] = tmp[it.first];
			}
		}
	}

	for(int i = 0; i < ::q; i++) {
		cout << answer[i] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	solve();
	return 0;
}