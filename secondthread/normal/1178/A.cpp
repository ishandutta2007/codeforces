#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n; cin>>n;
	int alice; cin>>alice;
	int total=0;
	int party=0;
	vector<int> inParty;

	party+=alice;
	inParty.push_back(1);
	total+=alice;
	for (int i=1; i<n; i++) {
		int next; cin>>next;
		total+=next;
		if (next*2<=alice) {
			inParty.push_back(i+1);
			party+=next;
		}
	}
	if (party*2<=total) {
		cout<<0<<endl;
	}
	else {
		cout<<inParty.size()<<endl;
		for (int &i:inParty)
			cout<<i<<" ";
		cout<<endl;
	}

	return 0;
}