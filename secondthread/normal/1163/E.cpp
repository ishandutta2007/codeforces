#include <bits/stdc++.h>

using namespace std;

bool solve(int nBits, vector<int> usable) {
	vector<int> rows;
	vector<int> unedited;
	for (int r=0; r<usable.size(); r++) {
		int orig=usable[r], toAdd=usable[r];
		for (int other=0; other<rows.size(); other++) {	
			if (toAdd>(toAdd^rows[other]))
				toAdd^=rows[other];
		}
		
		//not linearly independent
		if (toAdd==0) continue;

		for (int i=0; i<rows.size(); i++) {
			if (rows[i]>(rows[i]^toAdd))
				rows[i]^=toAdd;
		}
		rows.push_back(toAdd);
		sort(rows.begin(), rows.end(), greater<int>());
		unedited.push_back(orig);
	}
	if (rows.size()!=nBits)
		return false;

	//cout<<"Works for nBits="<<nBits<<endl;
	//for (int &i:rows)
		//cout<<i<<" ";
	//cout<<endl;
	//for (int &i:unedited)
	//	cout<<i<<" ";
	//cout<<endl;
	
	cout<<nBits<<endl;
	int cur=0;
	cout<<cur<<" ";
	for (int i=1; i<1<<nBits; i++) {
		cur^=unedited[__builtin_ctz(i)];
		cout<<cur<<" ";
	}
	cout<<endl;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin>>n;
	vector<int> all;
	for (int i=0; i<n; i++) {
		int temp;
		cin>>temp;
		all.push_back(temp);
	}
	for (int nBits=20; nBits>=0; nBits--) {
		vector<int> usable;
		for (int &i:all)
			if (i<1<<nBits)
				usable.push_back(i);
		if (solve(nBits, usable))
			return 0;
	}
	assert(false);

	return 0;
}