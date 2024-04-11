#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin>>n;
	n*=2;
	vector<int> a;
	for (int i=0; i<n; i++) {
		int temp; cin>>temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	if (a[0]==a[n-1]) {
		cout<<-1<<endl;
		return 0;
	}
	for (int i=0; i<n; i++)
		cout<<a[i]<<" \n"[i==n-1];
	return 0;
}