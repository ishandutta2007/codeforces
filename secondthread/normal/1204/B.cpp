#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, l, r; cin>>n>>l>>r;
	ll minAns=0, maxAns=0;
	for (int i=0; i<l; i++) {
		minAns+=1<<i;
	}
	for (int i=l; i<n; i++)
		minAns++;

	for (int i=0; i<n; i++)
		maxAns+=1<<(min(i, r-1));
	cout<<minAns<<" "<<maxAns<<'\n';

	return 0;
}