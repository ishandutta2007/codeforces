#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int toRemoveIndex;

int countIllegal(vector<ii> a, int first, int c) {
	int n=a.size();
	vector<int> target;
	for (int i=0; i<n-1; i++)
		target.push_back(first+c*i);
	int targetIndex=0;
	int illegalCount=0;
	for (int i=0; i<n; i++) {
		if (a[i].first==target[targetIndex]) {
			targetIndex++;
		}
		else {
			illegalCount++;
			toRemoveIndex=a[i].second+1;
		}
	}
	return illegalCount;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	vector<ii> a;
	for (int i=0; i<n; i++) {
		int temp; cin>>temp;
		a.push_back({temp, i});
	}
	sort(a.begin(), a.end());
	if (n==2) {
		cout<<1<<endl;
		return 0;
	}
	if (countIllegal(a, a[0].first, a[1].first-a[0].first) == 1
			||countIllegal(a, a[0].first, a[2].first-a[0].first) == 1
			||countIllegal(a, a[1].first, a[2].first-a[1].first) == 1) {
		cout<<toRemoveIndex<<endl;
	}
	else {
		cout<<-1<<endl;
	}

	return 0;
}