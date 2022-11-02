#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main() {
	int h, i, j, k, l;
	int t, n, m;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &m);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		pair<int, int> s[m];
		for(i=0; i<m; i++) {
			scanf("%d %d", &s[i].first, &s[i].second);
		}
		vector<pair<long long, long long> > b[n+1];
		for(i=0; i<m; i++) {
			if(!binary_search(a, a+n, s[i].first) && !binary_search(a, a+n, s[i].second)) {
				int l, r;
				if(s[i].first > a[n-1]) {
					l = n;
				} else {
					l = lower_bound(a, a+n, s[i].first)-a;
				}
				if(s[i].second > a[n-1]) {
					r = n;
				} else {
					r = lower_bound(a, a+n, s[i].second)-a;
				}
				if(l == r) {
					b[l].push_back(s[i]);
				}
			}
		}
		for(i=0; i<=n; i++) {
			sort(b[i].begin(), b[i].end());
		}
		for(i=0; i<=n; i++) {
			if(i != 0) {
				for(j=0; j<b[i].size(); j++) {
					b[i][j].first = b[i][j].first-a[i-1];
				}
			}
			if(i != n) {
				if(!b[i].empty()) {
					b[i].back().second = a[i]-b[i].back().second;
				}
				for(j=b[i].size()-2; j>=0; j--) {
					b[i][j].second = max(b[i][j+1].second, a[i]-b[i][j].second);
				}
			}
		}
		long long d[n][2];
		if(b[0].empty()) {
			d[0][0] = 0;
			d[0][1] = 0;
		} else {
			d[0][0] = b[0][0].second;
			d[0][1] = 2*b[0][0].second;
		}
		for(i=1; i<n; i++) {
			for(j=0; j<2; j++) {
				d[i][j] = LLONG_MAX;
				for(k=0; k<2; k++) {
					for(l=0; l<=b[i].size(); l++) {
						long long add = 0;
						if(l != 0) {
							if(k == 0) {
								add += 2*b[i][l-1].first;
							} else {
								add += b[i][l-1].first;
							}
						}
						if(l != b[i].size()) {
							if(j == 0) {
								add += b[i][l].second;
							} else {
								add += 2*b[i][l].second;
							}
						}
						d[i][j] = min(d[i][j], d[i-1][k]+add);
					}
				}
			}
		}
		/*printf("dddd\n");
		for(i=0; i<n; i++) {
			printf("%d %d\n", d[i][0], d[i][1]);
		}*/
		long long answer;
		if(b[n].empty()) {
			answer = min(d[n-1][0], d[n-1][1]);
		} else {
			answer = min(d[n-1][0]+2*b[n].back().first, d[n-1][1]+b[n].back().first);
		}
		printf("%lld\n", answer);
	}
}