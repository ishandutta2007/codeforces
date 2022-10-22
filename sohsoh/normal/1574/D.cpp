// orz ?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, C[MAXN], P[MAXN], m;
vector<int> V[MAXN];
vector<pair<vector<int>, int>> ans, t_ans;

inline void add(int ind) {
	t_ans.clear();
	priority_queue<pll> pq;
	for (int i = 0; i < C[ind]; i++) {
		P[i] = 0;
		pq.push({V[ind][i] + ans[0].Y, i});
	}

	while ((int) t_ans.size() < m + 10 && !pq.empty()) {
		int i = pq.top().Y;
		int s = pq.top().X;
		pq.top();
		pq.pop();
		vector<int> t = ans[P[i]].X;
		t.push_back(i);
		
		t_ans.push_back({t, s});	
		P[i]++;
		if (P[i] < ans.size())
			pq.push({V[ind][i] + ans[P[i]].Y, i});
	}

	swap(ans, t_ans);
}

int sum(vector<int>& v) {
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += V[i + 1][v[i]];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> C[i];
		for (int j = 1; j <= C[i]; j++) {
			int x;
			cin >> x;
			V[i].push_back(x);
		}
	}

	cin >> m;
	ans = {{{}, 0}};

	for (int i = 1; i <= n; i++) 
		add(i);

	set<vector<int>> st;
	for (auto e : ans) st.insert(e.X);

	for (int i = 1; i <= m; i++) {
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			v.push_back(x - 1);
		}

		st.erase(v);
	}

	vector<int> ans = *st.begin();
	for (auto e : st) {
		if (sum(e) > sum(ans))
			ans = e;
	}
	for (int e : ans) cout << e + 1 << sep;
	cout << endl;
	return 0;
}