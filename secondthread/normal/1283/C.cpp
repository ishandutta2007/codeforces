#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin>>a[i];
	vector<int> gaveTo(n, -1);
	for (int i=0; i<n; i++)
		if (a[i]) gaveTo[a[i]-1]=i;
	vector<int> tails, heads;
	for (int i=0; i<n; i++) {
		if (a[i]) continue;
		int index=i;
		while (gaveTo[index]!=-1)
			index=gaveTo[index];
		heads.push_back(i);
		tails.push_back(index);
	}
	for (int i=0; i<heads.size(); i++) {
		a[heads[i]]=tails[(i+1)%heads.size()]+1;
	}
	for (int i=0; i<n; i++) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}