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

bool cmp_first(const vector<int>& a, const vector<int>& b) {
	if(a[0] < b[0]) {
		return true;
	} else {
		return false;
	}
}

int d1(vector<int> a) {
	int i, j;
	int answer = 0;
	for(i=0; i<a.size(); i++) {
		for(j=i+1; j<a.size(); j++) {
			if(a[i] < a[j]) {
				answer++;
			}
		}
	}
	return answer;
}

int main() {
	int h, i, j, k;
	int t, n, m;
	int in;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		int answer = 0;
		scanf("%d %d", &n, &m);
		vector< vector<int> > a;
		vector< vector<int> > b;
		int idx[n*m];
		for(i=0; i<n*m; i++) {
			scanf("%d", &in);
			vector<int> add;
			add.push_back(in);
			add.push_back(i);
			a.push_back(add);
			b.push_back(add);
		}
		stable_sort(a.begin(), a.end(), cmp_first);
		for(i=0; i<n; i++) {
			vector<int> l;
			for(j=0; j<m; j++) {
				l.push_back(a[m*i+j][1]);
			}
			/*for(j=0; j<l.size(); j++) {
				printf("%d ", l[j]);
			}
			printf("\n");*/
			for(k=0; k<l.size(); k++) {
				for(j=k+1; j<l.size(); j++) {
					if(l[k] < l[j] && b[l[k]][0] != b[l[j]][0]) {
						answer++;
					}
				}
			}
		}
		printf("%d\n", answer);
	}
}