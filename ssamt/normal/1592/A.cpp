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
#include <map>

using namespace std;

int main() {
	int h, i, j, l;
	int t, n, m, k;
	int health;
	int in;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		priority_queue<int> a;
		scanf("%d %d", &n, &health);
		for(i=0; i<n; i++) {
			scanf("%d", &in);
			a.push(in);
		}
		int m1 = a.top();
		a.pop();
		int m2 = a.top();
		if(health%(m1+m2) == 0) {
			printf("%d\n", 2*(health/(m1+m2)));
		} else if(health%(m1+m2) <= m1) {
			printf("%d\n", 2*(health/(m1+m2))+1);
		} else {
			printf("%d\n", 2*(health/(m1+m2))+2);
		}
	}
}