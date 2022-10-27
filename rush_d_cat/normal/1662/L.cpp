#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
typedef long long ll;
int n;
ll k, t[N], a[N];
ll bit[N], dp[N];
void add(int pos,ll x){
	while(pos<N){
		bit[pos]=max(bit[pos],x);
		pos+=pos&(-pos);
	}
}
ll query(int pos){
	ll ans=-1e18;
	while(pos>0){
		ans=max(ans,bit[pos]);
		pos-=pos&(-pos);
	}
	return ans;
}
int main() {
	scanf("%d%lld",&n,&k);
	for (int i = 1; i <= n; i ++) scanf("%lld", &t[i]);
	for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	for (int i = 0; i < N; i ++) bit[i] = -1e18;
	vector<pair<ll,ll> > v;

	for (int i = 0; i <= n; i ++) {
		v.push_back({a[i] - t[i] * k, a[i] + t[i] * k});
	}


	vector<ll> vec;
	for (auto p: v) vec.push_back(p.second);
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());

	auto id = [&](ll x) {
		return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
	};
	sort(v.begin(),v.end(),[](pair<ll,ll> p1, pair<ll,ll> p2){
		if (p1.first != p2.first) return p1.first > p2.first;
		return p1.second < p2.second;
	});
	for (auto p: v) {
		//cout << "!" << p.first <<" " <<p.second<<"\n";
	}

	ll ans = 0;
	for (int i = 0; i < v.size(); i ++) {
		if (v[i].first == 0ll && v[i].second == 0ll) {
			add(id(v[i].second), 0);
			continue;
		}
		ll tmp = query(id(v[i].second)) + 1;
		add(id(v[i].second), tmp);
		ans = max(ans, tmp);
	}
	printf("%lld\n", ans);
}