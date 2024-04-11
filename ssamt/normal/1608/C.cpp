#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n], b[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		for(i=0; i<n; i++) {
			scanf("%d", &b[i]);
		}
		vector<vector<int>> as, bs;
		for(i=0; i<n; i++) {
			as.push_back({a[i], i});
			bs.push_back({b[i], i});
		}
		sort(as.begin(), as.end());
		sort(bs.begin(), bs.end());
		int aend = n, bend = n;
		int anew = n-1, bnew = n-1;
		while(true) {
			int mina = INT_MAX, minb = INT_MAX;
			if(anew == aend) {
				break;
			}
			for(i=anew; i<aend; i++) {
				minb = min(minb, b[as[i][1]]);
			}
			while(b[bs[bnew][1]] > minb) {
				bnew--;
			}
			aend = anew;
			if(bnew == bend) {
				break;
			}
			for(i=bnew; i<bend; i++) {
				mina = min(mina, a[bs[i][1]]);
			}
			while(a[as[anew][1]] > mina) {
				anew--;
			}
			bend = bnew;
		}
		int answer[n] = {};
		for(i=anew; i<n; i++) {
			answer[as[i][1]] = 1;
		}
		for(i=bnew; i<n; i++) {
			answer[bs[i][1]] = 1;
		}
		for(i=0; i<n; i++) {
			printf("%d", answer[i]);
		}
		printf("\n");
	}
}