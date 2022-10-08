#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin>>a[i];
	vector<int> csE(n+1, 0), csO(n+1, 0);
	for (int i=1; i<=n; i++) {
		csE[i]+=csE[i-1];
		csO[i]+=csO[i-1];
		if (i%2==1) csE[i]+=a[i-1];
		else csO[i]+=a[i-1];
	}
	int legal=0;

	for (int i=0; i<n; i++) {
		int totalOne=csE[i] + (csO[n]-csO[i+1]);
		int totalTwo=csO[i] + (csE[n]-csE[i+1]);
		if (totalOne==totalTwo) legal++;
	}
	cout<<legal<<endl;
	return 0;
}