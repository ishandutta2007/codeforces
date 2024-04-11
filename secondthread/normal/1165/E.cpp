#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=998244353;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	vector<int> a, b;
	for (int i=0; i<n; i++) {
		int v; cin>>v;
		a.push_back(v);
	}
	for (int i=0; i<n; i++) {
		int v; cin>>v;
		b.push_back(v);
	}
	priority_queue<ll> q;
	for (int i=0; i<n; i++) {
		q.push(a[i]*(ll)(i+1)*(n-i));
	}
	sort(b.begin(), b.end());
	ll ans=0;
	for (int i=0; i<n; i++) {
		ans+=((q.top()%mod)*b[i])%mod;
		ans%=mod;
		q.pop();
	}
	cout<<ans<<endl;

	return 0;
}