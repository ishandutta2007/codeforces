#include <bits/stdc++.h>

using namespace std;
const int maxn=300001;
const int nBits=20;
int minReachable[maxn][nBits];
int nextIndexWithBit[nBits];
int a[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q; cin>>n>>q;
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	for (int i=0; i<nBits; i++)
		minReachable[n][i]=n;
	for (int i=0; i<nBits; i++)
		nextIndexWithBit[i]=n;
	for (int i=n-1; i>=0; i--) {
		for (int bit=0; bit<nBits; bit++)
			minReachable[i][bit]=n;

		for (int bit=0; bit<nBits; bit++) {
			if (a[i]&(1<<bit)) {
				minReachable[i][bit]=i;
			}
			else {
				for (int j=0; j<nBits; j++) {
					if (a[i]&(1<<j))
						minReachable[i][bit]=min(minReachable[i][bit], minReachable[nextIndexWithBit[j]][bit]);
				}
			}

			//cout<<"minReachable bit: "<<bit<<" index: "<<i<<" = "<<minReachable[bit][i]<<endl;
		}
		for (int bit=0; bit<nBits; bit++)
			if (a[i]&(1<<bit))
				nextIndexWithBit[bit]=i;
	}

	for (int qq=0; qq<q; qq++) {
		int from, to; cin>>from>>to;
		from--; to--;
		bool possible=false;
		for (int i=0; i<nBits; i++) {
			if (a[to]&(1<<i)) {
				if (minReachable[from][i]<=to) possible=true;
			}
		}
		cout<<(possible?"Shi\n":"Fou\n");
	}

	return 0;
}