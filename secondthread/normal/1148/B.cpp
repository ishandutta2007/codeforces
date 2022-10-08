#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<int> a, b;
	int aLen, bLen, ta, tb, k; cin>>aLen>>bLen>>ta>>tb>>k;
	for (int i=0; i<aLen; i++) {
		int temp; cin>>temp;
		a.push_back(temp+ta);
	}
	for (int i=0; i<bLen; i++) {
		int temp; cin>>temp;
		b.push_back(temp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (aLen<=k||bLen<=k) {
		cout<<-1<<endl;
		return 0;
	}
	int validB=0;
	ll bestTime=0;
	for (int aIndex=0; aIndex<=k; aIndex++) {
		while (validB<bLen && a[aIndex]>b[validB]) validB++;
		int bToSkip=k-aIndex;
		if (validB+bToSkip>=bLen) {
			cout<<-1<<endl;
			return 0;
		}
		bestTime=max(bestTime, (ll)b[validB+bToSkip]);
	}
	cout<<bestTime+tb<<endl;

	return 0;
}