//In the name of God
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > pos,neg;
const int N = 10000;
int arr[N],x[N];
int main() {
	int n; cin >> n;
	for(int i = 0; i < n;++i) {
		cin >> x[i] >> arr[i];
		if(x[i] < 0) neg.push_back({x[i],arr[i]});
		else pos.push_back({x[i],arr[i]});
	}
	sort(neg.begin(),neg.end());
	reverse(neg.begin(),neg.end());
	sort(pos.begin(),pos.end());
	int ans = 0;
	for(int i = 0; i < min(neg.size(),pos.size());++i) ans += neg[i].second,ans += pos[i].second;
	if(neg.size() > pos.size()) ans += neg[pos.size()].second;
	if(pos.size() > neg.size()) ans += pos[neg.size()].second;
	cout << ans << '\n';
	return 0;
}