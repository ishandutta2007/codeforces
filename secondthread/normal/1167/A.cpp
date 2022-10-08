#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin>>T;
	for (int tt=0; tt<T; tt++) {
		int n; cin>>n;
		string st; cin>>st;
		int firstInd=-1;
		for (int i=0; i<n; i++) if (st[i]=='8') {
			firstInd=i;
			break;
		}
		if (firstInd==-1||n-firstInd<11) {
			cout<<"NO\n";
		}
		else {
			cout<<"YES\n";
		}
	}
	
	return 0;
}