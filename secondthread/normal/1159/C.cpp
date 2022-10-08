#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin>>n>>m;
	vector<int> a, b;
	int aMax=-1, bMin=1e9;
	for (int i=0; i<n; i++) {
		int temp; cin>>temp;
		aMax=max(aMax, temp);
		a.push_back(temp);
	}
	for (int i=0; i<m; i++) {
		int temp; cin>>temp;
		bMin=min(bMin, temp);
		b.push_back(temp);
	}
	if (aMax>bMin) {
		cout<<-1<<endl;
		return 0;
	}
	ll total=0;
	if (aMax==bMin) {
		for (int &i:a) {
			total+=i*(ll)m;
		}
		for (int &i:b) {
			total+=i;
		}
		total-=m*(ll)aMax; 
	}
	else {
		sort(a.begin(), a.end());
		for (int i=0; i<n-2; i++) {
			total+=a[i]*(ll)m;
		}
		total+=a[n-2]*(ll)(m-1)+b[0];
		total+=a[n-1];
		for (int i=1; i<m; i++)
			total+=b[i];
	}
	cout<<total<<endl;

	return 0;
}