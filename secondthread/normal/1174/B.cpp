#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin>>n;
	vector<int> a;
	bool hasOdd=false, hasEven=false;
	for (int i=0; i<n; i++) {
		int temp; cin>>temp;
		if (temp%2==0) hasEven=true;
		else hasOdd=true;
		a.push_back(temp);
	}
	if (hasOdd&&hasEven) {
		sort(a.begin(), a.end());
	}
	
	for (int i=0; i<n; i++)
		cout<<a[i]<<" \n"[i==n-1];

	return 0;
}