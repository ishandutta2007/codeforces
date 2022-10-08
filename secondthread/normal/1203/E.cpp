
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin>>a[i];
	sort(a.begin(), a.end());
	int minWeight=1;
	int count=0;
	for (int i:a) {
		i--;
		if (i>=minWeight) {
			minWeight=i+1;
			count++;
		}
		else if (i==minWeight-1||i==minWeight-2) {
			minWeight++;
			count++;
		}
	}
	cout<<count<<'\n';
	return 0;
}