#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int a, b;
		scanf("%d %d %d", &n, &a, &b);
		if(a+b < n-1 && abs(a-b) <= 1) {
			deque<int> p;
			for(i=0; i<n; i++) {
				p.push_back(i+1);
			}
			if(a > b) {
				for(i=0; i<a; i++) {
					printf("%d ", p.front());
					p.pop_front();
					printf("%d ", p.back());
					p.pop_back();
				}
				for(i=2*a; i<n; i++) {
					printf("%d ", p.back());
					p.pop_back();
				}
			} else if(a < b) {
				for(i=0; i<b; i++) {
					printf("%d ", p.back());
					p.pop_back();
					printf("%d ", p.front());
					p.pop_front();
				}
				for(i=2*b; i<n; i++) {
					printf("%d ", p.front());
					p.pop_front();
				}
			} else {
				for(i=0; i<a; i++) {
					printf("%d ", p.back());
					p.pop_back();
					printf("%d ", p.front());
					p.pop_front();
				}
				for(i=2*a; i<n; i++) {
					printf("%d ", p.back());
					p.pop_back();
				}
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	}
}