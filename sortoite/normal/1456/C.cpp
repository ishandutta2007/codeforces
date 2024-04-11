#include<bits/stdc++.h>
using namespace std;
using INT = long long;

const int N = 5e5 + 10;
vector<int> vec[N];

INT calc(vector<int>& v) {
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	INT ans = 0;
	for(int i = 0; i < v.size(); i ++) {
		ans += 1ll * v[i] * (v.size() - 1 - i);
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n, k; cin>>n>>k; k = min(k, n - 1);
	vector<int> a(n);
	for(auto&r:a) scanf("%d", &r);
	sort(a.begin(), a.end());
	INT sum = 0;
	for(int i = n - 1; i >= 0; i --) {
		if(sum >= 0) {
			vec[0].push_back(a[i]);
			sum += a[i];
		}else break;
	}
	a.resize(n - vec[0].size());
	reverse(a.begin(), a.end());
	while(a.size() >= (k + 1)) {
		for(int i = 0; i < k + 1; i ++) {
			vec[i].push_back(a.back());
			a.pop_back();
		}
	}
	for(int i = 0; i < a.size(); i ++) vec[i+1].push_back(a[i]);
	INT ans = 0;
	for(int i = 0; i < k + 1; i ++) ans += calc(vec[i]);
	cout<<ans<<endl;
	return 0;
}