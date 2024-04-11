
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin>>T;
	while (T--) {
		int n; cin>>n;
		vector<int> a(4*n);
		for (int i=0; i<4*n; i++) cin>>a[i];
		sort(a.begin(), a.end());
		int startIndex=0, endIndex=4*n-1;
		bool works=true;
		int area=a[0]*a[endIndex];
		for (int i=0; i<n; i++) {
			if (a[startIndex]!=a[startIndex+1] || a[endIndex]!=a[endIndex-1]
					|| a[startIndex]*a[endIndex]!=area) works=false;
			startIndex+=2;
			endIndex-=2;
		}
		cout<<(works?"YES":"NO")<<'\n';

	}
	return 0;
}