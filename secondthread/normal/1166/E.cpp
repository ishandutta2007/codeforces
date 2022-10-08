#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int nDays, nStores; cin>>nDays>>nStores;
	vector<vector<bool>> boughtOnDay;
	for (int i=0; i<nDays; i++) {
		vector<bool> toAdd;
		for (int i=0; i<nStores; i++) toAdd.push_back(false);
		int n; cin>>n;
		for (int i=0; i<n; i++) {
			int temp; cin>>temp;
			toAdd[temp]=true;
		}
		boughtOnDay.push_back(toAdd);
	}
	bool possible=true;
	for (int i=0; i<nDays; i++) {
		for (int j=0; j<nDays; j++) {
			bool foundIntersect=false;
			for (int k=0; k<nStores; k++)
				if (boughtOnDay[i][k]&&boughtOnDay[j][k])
					foundIntersect=true;
			if (!foundIntersect)
				possible=false;
		}
	}
	cout<<(possible?"possible":"impossible")<<endl;

	
	
	return 0;
}