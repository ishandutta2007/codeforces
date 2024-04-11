#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool cmp_vector(const vector<int>& a, const vector<int>& b) {
	int i;
	for(i=0; i<a.size(); i++) {
		if(a[i] > b[i]) {
			return false;
		} else if(a[i] < b[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	int h, i, j, k;
	int t, n, m;
	int in;
	scanf("%d", &n);
	int c[n];
	vector<vector<int> > a;
	for(i=0; i<n; i++) {
		scanf("%d", &c[i]);
		vector<int> e;
		for(j=0; j<c[i]; j++) {
			scanf("%d", &in);
			e.push_back(in);
		}
		a.push_back(e);
	}
	scanf("%d", &m);
	vector<vector<int> > b;
	for(i=0; i<m; i++) {
		vector<int> e;
		for(j=0; j<n; j++) {
			scanf("%d", &in);
			e.push_back(in-1);
		}
		b.push_back(e);
	}
	sort(b.begin(), b.end(), cmp_vector);
	vector<int> test(n);
	int maxpower = 0;
	vector<int> answer(n);
	for(i=0; i<n; i++) {
		test[i] = c[i]-1;
	}
	if(!binary_search(b.begin(), b.end(), test)) {
		int power = 0;
		for(i=0; i<n; i++) {
			power += a[i][test[i]];
		}
		if(power > maxpower) {
			maxpower = power;
			for(i=0; i<n; i++) {
				answer[i] = test[i];
			}
		}
	}
	for(i=0; i<b.size(); i++) {
		for(j=0; j<n; j++) {
			test[j] = b[i][j];
		}
		for(j=0; j<n; j++) {
			if(b[i][j] != 0) {
				test[j]--;
				if(!binary_search(b.begin(), b.end(), test)) {
					int power = 0;
					for(k=0; k<n; k++) {
						power += a[k][test[k]];
					}
					if(power > maxpower) {
						maxpower = power;
						for(k=0; k<n; k++) {
							answer[k] = test[k];
						}
					}
				}
				test[j]++;
			}
		}
	}
	for(i=0; i<n; i++) {
		printf("%d ", answer[i]+1);
	}
	printf("\n");
}