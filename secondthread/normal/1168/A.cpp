#include <bits/stdc++.h>

using namespace std;
int n, mod;

bool possible(vector<int> a, int timesToInc) {
	int last=0;
	for (int i=0; i<a.size(); i++) {
		int val=a[i];
		int maxVal=val+timesToInc;
		if (maxVal<last)
			return false;
		int toChoose;
		if (maxVal<mod) {
			toChoose=max(last, val);
		}
		else {
			int r1Start=val, r1End=mod-1;
			int r2Start=0, r2End=maxVal%mod;
			toChoose=max(r1Start, last);
			if (r2End>=last)
				toChoose=last;
		}
		last=toChoose;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>mod;
	vector<int> a;
	for (int i=0; i<n; i++)  {
		int temp; cin>>temp;
		a.push_back(temp);
	}
	int lo=0, hi=mod-1;
	while (lo!=hi) {
		int mid=(lo+hi)/2;
		if (possible(a, mid)) {
			hi=mid;
		}
		else {
			lo=mid+1;
		}
	}
	cout<<lo<<endl;
	return 0;

}