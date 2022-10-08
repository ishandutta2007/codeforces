#include <bits/stdc++.h>

using namespace std;

int main() {
	string line; cin>>line;
	int n=line.size();
	int prevCount=0, maxAns=0;
	for (int i=0; i<2*n; i++) {
		if (i==0||line[i%n]==line[(i-1)%n]) prevCount=1;
		else prevCount++;
		maxAns=max(maxAns, prevCount);
	}
	cout<<min(maxAns, n)<<endl;

	return 0;
}