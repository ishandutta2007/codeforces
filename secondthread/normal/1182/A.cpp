#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int n; cin>>n;
	ll ways[100]={0};
	ways[0]=1;
	for (int i=0; i<n;i++) {
		ways[i+2]+=2*ways[i];
	}
	cout<<ways[n];

	return 0;
}