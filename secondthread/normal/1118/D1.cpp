#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxProfit(int originalN, int groupsAllowed, vector<int> toBuy) {
	ll total=0;
	vector<ll> groupCost(groupsAllowed, 0);
	for (int i=0; i<originalN; i++) {
		if (toBuy[i]>groupCost[i%groupsAllowed]) {
			total+=toBuy[i]-groupCost[i%groupsAllowed];
			groupCost[i%groupsAllowed]++;
		}
	}
	return total;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	ll totalNeeded; cin>>totalNeeded;
	ll total=0;
	vector<int> a(n, 0);
	for (int i=0; i<n; i++) {
		cin>>a[i]; total+=a[i];
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	if (totalNeeded>total) {
		cout<<-1<<endl;
		return 0;
	}

	int minGroups=1, maxGroups=n;
	while (minGroups!=maxGroups) {
		int mid=(minGroups+maxGroups)/2;
		ll canGet=maxProfit(n, mid, a);
		if (canGet>=totalNeeded) {
			maxGroups=mid;
		}
		else {
			minGroups=mid+1;
		}
	}

	cout<<minGroups<<endl;
	return 0;
}