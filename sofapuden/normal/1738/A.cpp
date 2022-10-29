#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int> v(n);for(auto &x : v)cin >> x;
	vector<int> a, b;
	ll su = 0;
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		if(v[i])a.push_back(x);
		else b.push_back(x);
		su+=x;
	}
	sort(a.rbegin(),a.rend());
	sort(b.rbegin(),b.rend());
	for(int i = 0; i < min(b.size(),a.size()); ++i){
		su+=(a[i] + b[i]);
	}
	if(a.size() == b.size())su-=min(a.back(),b.back());
	cout << su << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}