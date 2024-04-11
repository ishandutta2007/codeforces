
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin>>n; assert(n%4==0);
	vector<vector<int>> a(n, vector<int>(n));
	for (int i=0; i<n/4; i++) {
		for (int j=0; j<n/4; j++) {
			int base=i*n/4+j;
			for (int l=0; l<4; l++) 
				for (int ll=0; ll<4; ll++)
					a[i*4+l][j*4+ll]=base*16+l*4+ll;
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			cout<<a[i][j]<<" ";
		cout<<'\n';
	}
	return 0;
}