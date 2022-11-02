#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int cmp_first(const void* num1, const void* num2) {
	int* a = *(int**)num1;
	int* b = *(int**)num2;
	if(a[0] > b[0]) {
		return 1;
	} else if(a[0] < b[0]) {
		return -1;
	} else {
		if(a[1] > b[1]) {
			return 1;
		} else if(a[1] < b[1]) {
			return -1;
		} else {
			return 0;
		}
	}
}

int cmp_second(const void* num1, const void* num2) {
	int* a = *(int**)num1;
	int* b = *(int**)num2;
	if(a[1] > b[1]) {
		return 1;
	} else if(a[1] < b[1]) {
		return -1;
	} else {
		if(a[0] > b[0]) {
			return 1;
		} else if(a[0] < b[0]) {
			return -1;
		} else {
			return 0;
		}
	}
}

int main() {
	long long h, i, j, l;
	long long t, n, m, k;
	long long in;
	cin >> t;
	for(h=0; h<t; h++) {
		long long answer = 0;
		cin >> n >> m >> k;
		vector<int> x;
		vector<int> y;
		for(i=0; i<n; i++) {
			cin >> in;
			x.push_back(in);
		}
		for(i=0; i<m; i++) {
			cin >> in;
			y.push_back(in);
		}
		int* pos[k];
		for(i=0; i<k; i++) {
			pos[i] = (int*)malloc(sizeof(int)*2);
			scanf("%d %d", &pos[i][0], &pos[i][1]);
		}
		qsort(pos, k, sizeof(int*), cmp_first);
		int last = 0;
		for(i=0; i<n-1; i++) {
			for(; last<k && pos[last][0]<=x[i]; last++);
			for(j=last; j<k && pos[j][0]<x[i+1]; j++);
			answer += (j-last)*(j-last-1)/2;
			last = j;
		}
		last = 0;
		for(i=0; i<n; i++) {
			for(j=0; j<m-1; j++) {
				for(; last<k && pos[last][0]<x[i]; last++);
				if(last == k) {
					goto OUT1;
				}
				if(pos[last][0] == x[i]) {
					for(; last<k && pos[last][0]==x[i] && pos[last][1]<=y[j]; last++);
					for(l=last; l<k && pos[l][0]<=x[i] && pos[l][1]<y[j+1]; l++);
					answer -= (l-last)*(l-last-1)/2;
					last = l;
					if(last == k) {
						goto OUT1;
					}
				} else {
					break;
				}
				if(l < k && j < m-1) {
					if(pos[l][0] != x[i]) {
						break;
					}
					if(pos[l][0] == x[i] && pos[l][1] > y[j+1]) {
						int idx = lower_bound(y.begin(), y.end(), pos[l][1])-y.begin();
						j = idx-2;
					}
				}
			}
		}
OUT1:
		qsort(pos, k, sizeof(int*), cmp_second);
		last = 0;
		for(i=0; i<m-1; i++) {
			for(; last<k && pos[last][1]<=y[i]; last++);
			for(j=last; j<k && pos[j][1]<y[i+1]; j++);
			answer += (j-last)*(j-last-1)/2;
			last = j;
		}
		last = 0;
		for(i=0; i<m; i++) {
			for(j=0; j<n-1; j++) {
				for(; last<k && pos[last][1]<y[i]; last++);
				if(last == k) {
					goto OUT2;
				}
				if(pos[last][1] == y[i]) {
					for(; last<k && pos[last][1]==y[i] && pos[last][0]<=x[j]; last++);
					for(l=last; l<k && pos[l][1]<=y[i] && pos[l][0]<x[j+1]; l++);
					answer -= (l-last)*(l-last-1)/2;
					last = l;
					if(last == k) {
						goto OUT2;
					}
				} else {
					break;
				}
				if(l < k && j < n-1) {
					if(pos[l][1] != y[i]) {
						break;
					}
					if(pos[l][1] == y[i] && pos[l][0] > x[j+1]) {
						int idx = lower_bound(x.begin(), x.end(), pos[l][0])-x.begin();
						j = idx-2;
					}
				}
			}
		}
OUT2:
		printf("%lld\n", answer);
	}
}