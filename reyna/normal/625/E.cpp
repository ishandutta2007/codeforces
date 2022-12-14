// In the name of God

/*
	........
*/


#include <bits/stdc++.h>

using namespace std;

inline int read() { int32_t x; scanf("%d", &x); return x; }

typedef long long ll;

const int N = 1e5 + 5;
int p[N], jump[N], n, m, kill[N];
ll t[N], last[N], curp[N];
set<pair<ll, int>> events;
set<pair<int, int>> frogs;

pair<int, int> nxt(pair<int, int> cur) {
	auto it = frogs.find(cur);
	if (++it == frogs.end())
		it = frogs.begin();
	return *it;
}

pair<int, int> prv(pair<int, int> cur) {
	auto it = frogs.find(cur);
	if (it == frogs.begin())
		it = frogs.end();
	--it;
	return *it; 
}

ll when(int i, int j) {
	ll pi = ((max(0LL, last[j] - last[i]) * jump[i]) + curp[i]) , pj = ((max(0LL, last[i] - last[j] - (i < j)) * jump[j]) + curp[j]);
	if (pi >= pj + (p[j] < p[i]? m: 0))
		return max(last[i], last[j]);
	pj = ((max(0LL, last[i] - last[j]) * jump[j]) + curp[j]);
	pi %= m;
	pj %= m;
	if (i < j && (pj - pi + m) % m <= jump[i])
		return max(last[i], last[j]) + 1;
	if (jump[j] >= jump[i])
		return 1e18;
	ll res = 0;
	if (i < j) {
		res = (max(0LL, ((pj - pi + m) % m - jump[i] + jump[i] - jump[j] - 1)) / (jump[i] - jump[j])) + max(last[i], last[j]) + 1;
	} else {
//		cout << i << ' ' << j << " hi " << pi << ' ' << pj << ' ' << jump[i] << ' ' << jump[j] << endl;
		res = (max(0LL, ((pj - pi + m) % m + jump[i] - jump[j] - 1)) / (jump[i] - jump[j])) + max(last[i], last[j]);
	}
	return res;
}

int main() {
	memset(kill, -1, sizeof kill);
	n = read(), m = read();
	for (int i = 0; i < n; ++i) {
		p[i] = read() - 1;
		jump[i] = read();
		curp[i] = p[i];
		last[i] = 0;
		frogs.insert({p[i], i});
	}
	for (auto cur : frogs) {
		auto nx = nxt(cur);
		t[cur.second] = when(cur.second, nx.second);
//		cout << cur.second << ' ' << nx.second << ' ' << t[cur.second] << endl;
		events.insert({t[cur.second], cur.second});  kill[cur.second] = nx.second;
	}
	while (events.size()) {
		auto cur = *(events.begin());
		events.erase(cur);
//		cout << cur.first << ' ' << cur.second << ' ' << kill[cur.second] << endl;
		if (kill[cur.second] == cur.second)
			break;
//		for (auto f : frogs)
//			cout << f.second << ' ' ;
//		cout << endl;
		if (cur.first >= 1e18)
			break;
		ll cur_time = cur.first;
		int id = cur.second;
		pair<int, int> f = {p[id], id};
		curp[id] = (curp[id] + (cur_time - last[id]) * jump[id]);
		jump[id]--;
		last[id] = cur_time;
		auto nx = nxt(f), pr = prv(f);
		int nxid = nx.second, prid = pr.second;
		events.erase({t[nxid], nxid});
		events.erase({t[prid], prid});
		frogs.erase(nx);
		auto aft = nxt(f);
		int aftid = aft.second;
		events.insert({t[prid] = when(prid, id), prid}); kill[prid] = id;
		events.insert({t[id] = when(id, aftid), id}); kill[id] = aftid;
//		cout << id << ' ' << pr.first << ' ' << prid << ' ' << nx.first << ' ' << nxid << ' ' << aftid << '\n';
	}
	cout << (int) frogs.size() << endl;
	for (auto frog : frogs)
		cout << frog.second + 1 << ' ';
	
}