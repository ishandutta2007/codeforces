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
#include <queue>

using namespace std;

int main() {
	int h, i, j, l;
	int t, n, m, k;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		vector<pair<int, int> > answer;
		priority_queue<pair<int, int> > q;
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
			pair<int, int> e{a[i], i};
			if(e.first > 0) {
				q.push(e);
			}
		}
		while(q.size() > 1) {
			pair<int, int> n1 = q.top();
			q.pop();
			pair<int, int> n2 = q.top();
			q.pop();
			pair<int, int> e{n1.second, n2.second};
			answer.push_back(e);
			n1.first--;
			if(n1.first > 0) {
				q.push(n1);
			}
			n2.first--;
			if(n2.first > 0) {
				q.push(n2);
			}
		}
		printf("%d\n", answer.size());
		for(i=0; i<answer.size(); i++) {
			printf("%d %d\n", answer[i].first+1, answer[i].second+1);
		}
	}
}