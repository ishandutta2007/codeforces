#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin>>n>>k;
	vector<int> a;
	for (int i=0; i<n; i++) {
		int temp; cin>>temp; a.push_back(temp);
	}
	vector<ll> post;
	post.push_back(a[n-1]);
	for (int i=1; i+1<n; i++) {
		post.push_back(post[i-1]+a[n-1-i]);
	}
	sort(post.begin(), post.end());
	ll total=0;
	for (int i=0; i<n; i++) {
		total+=a[i];
	}
	for (int i=1; i<k; i++)
		total+=post[n-i-1];
	cout<<total<<endl;
	

	return 0;
}