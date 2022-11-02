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
	int h, i, j;
	int t, n, m, k;
	int in;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int a[n];
		vector<pair<int, int> > s;
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		vector<vector<int> > answer;
		for(i=0; i<n; i++) {
			s.clear();
			for(j=0; j<n; j++) {
				pair<int, int> e{a[j], j};
				s.push_back(e);
			}
			sort(s.begin(), s.end());
			if(i != s[i].second) {
				vector<int> e{i+1, s[i].second+1, s[i].second-i};
				answer.push_back(e);
			}
			int temp = a[s[i].second];
			for(j=s[i].second; j>i; j--) {
				a[j] = a[j-1];
			}
			a[i] = temp;
		}
		printf("%d\n", answer.size());
		for(i=0; i<answer.size(); i++) {
			for(j=0; j<3; j++) {
				printf("%d ", answer[i][j]);
			}
			printf("\n");
		}
	}
}