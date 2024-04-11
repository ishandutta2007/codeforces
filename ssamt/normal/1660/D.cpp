#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<int> a(n);
		vector<int> z, neg, sum(n+1);
		sum.push_back(0);
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			if(a[i] == 0) {
				z.push_back(i);
			}
			if(a[i] < 0) {
				neg.push_back(i);
			}
			sum[i+1] = sum[i];
			if(a[i] == 2 || a[i] == -2) {
				sum[i+1]++;
			}
		}
		int m = -1;
		vector<int> answer{0, n};
		for(i=0; i<=z.size(); i++) {
			int l = (i==0)?0:z[i-1]+1;
			int r = (i==z.size())?n:z[i];
			int lfind = lower_bound(neg.begin(), neg.end(), l)-neg.begin();
			int rfind = lower_bound(neg.begin(), neg.end(), r)-neg.begin()-1;
			int count = rfind-lfind+1;
			if(count%2 == 0) {
				int two = sum[r]-sum[l];
				if(two > m) {
					m = two;
					answer = {l, r};
				}
			} else {
				int two = sum[neg[rfind]]-sum[l];
				if(two > m) {
					m = two;
					answer = {l, neg[rfind]};
				}
				two = sum[r]-sum[neg[lfind]+1];
				if(two > m) {
					m = two;
					answer = {neg[lfind]+1, r};
				}
			}
		}
		printf("%d %d\n", answer[0], n-answer[1]);
	}
}