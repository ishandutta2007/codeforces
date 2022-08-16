#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SZ = 200005;
vector<int> A(SZ, 0);

int main() {
	int n, k, q;
	cin>>n>>k>>q;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin>>l>>r;
		A[l]++;
		A[r+1]--;
	}
	for (int i = 1; i < SZ; i++) {
		A[i] += A[i-1];
	}
	for (int i = 1; i < SZ; i++) {
		A[i] = A[i-1] + (A[i] >= k ? 1 : 0);
	}
	
	for (int i = 0; i < q; i++) {
		int a, b;
		cin>>a>>b;
		cout<<A[b]-A[a-1]<<endl;
	}
	return 0;
}