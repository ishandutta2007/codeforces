#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e5 + 7;

map<int, long long> mpp[kMaxN], *mp[kMaxN];
int n, m, k, p[kMaxN], d[kMaxN], w[kMaxN], v;
long long ans; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for(int i = 2; i <= n; ++i)
		cin >> p[i];
	for(int i = 1; i <= n; ++i)
		mp[i] = mpp + i;
	while(m--){
		cin >> v;
		cin >> d[v] >> w[v];
	}

	for(int i = n; i > 1; --i){
		if(d[i]){
			auto it = mp[i]->insert(make_pair(d[i], 0)).first;
			it->second += (v = w[i]);
			for(++it; it != mp[i]->end() && v >= it->second; v -= it->second, mp[i]->erase(it++));
			if(it != mp[i]->end())
				it->second -= v;
		}
		if(mp[i]->size() > mp[p[i]]->size())
			swap(mp[i], mp[p[i]]);
		for(auto u: *mp[i]){
			auto it = mp[p[i]]->insert(make_pair(u.first, 0)).first;
			it->second += u.second;
		}
	}

	for(auto u: *mp[1])
		ans += u.second;

	cout << ans << "\n";
}