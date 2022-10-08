#include <bits/stdc++.h>

using namespace std;
const int maxn=300001;

typedef long long ll;
int n;
int indexOf[maxn];
vector<int> a;
vector<pair<int, int> > swaps;

void dirSwap(int i, int j) {
	indexOf[a[i]]=j;
	indexOf[a[j]]=i;
	swap(a[i], a[j]);
	swaps.push_back({i, j});
}

void swapij(int i, int j) {
	if (i>j) swap(i, j);
	if (j-i>=n/2) {
		dirSwap(i, j);
		return;
	}
	if (i<n/2&&j<n/2) {
		dirSwap(i, n-1);
		dirSwap(j, n-1);
		dirSwap(i, n-1);
	}
	else if (i<n/2) {
		dirSwap(i, n-1);
		dirSwap(0, n-1);
		dirSwap(0, j);
		dirSwap(0, n-1);
		dirSwap(i, n-1);
	}
	else {
		dirSwap(i, 0);
		dirSwap(j, 0);
		dirSwap(i, 0);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n;
	for (int i=0; i<n; i++) {
		int temp; cin>>temp; a.push_back(temp-1);
		indexOf[a[i]]=i;
	}
	for (int i=0; i<n; i++) {
		if (indexOf[i]!=i) {
			swapij(indexOf[i], i);
		}
	}
	
	cout<<swaps.size()<<'\n';
	for (pair<int, int> &p:swaps) {
		cout<<p.first+1<<" "<<p.second+1<<'\n';
	}

	return 0;
}