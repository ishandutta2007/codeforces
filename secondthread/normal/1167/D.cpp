#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	string st; cin>>st;
	int count=0;
	for (int i=0; i<n; i++) {
		if (st[i]=='(') {
			count++;
			cout<<(count&1);
		}
		else {
			cout<<(count&1);
			count--;
		}
	}
	
	cout<<endl;
	
	return 0;
}