#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	for(int i=0; i<a.first.size(); i++) {
		if(a.first[i] != b.first[i]) {
			if(i%2 == 0) {
				return (a.first[i]<b.first[i]);
			} else {
				return (a.first[i]>b.first[i]);
			}
		}
	}
	return false;
}

int main() {
	int h, i, j, l;
	int t, n, m, k;
	scanf("%d %d", &n, &m);
	vector<pair<string, int> > s;
	char in[m+1];
	for(i=0; i<n; i++) {
		scanf("%s", in);
		pair<string, int> e{in, i};
		s.push_back(e);
	}
	sort(s.begin(), s.end(), cmp);
	for(i=0; i<n; i++) {
		printf("%d ", s[i].second+1);
	}
	printf("\n");
}