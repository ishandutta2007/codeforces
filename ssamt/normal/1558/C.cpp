#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void flip(vector<int> &a, int n) {
	int i;
	vector<int> b;
	for(i=0; i<n; i++) {
		b.push_back(a[n-1-i]);
	}
	for(i=0; i<n; i++) {
		a[i] = b[i];
	}
}

int main() {
	int h, i, j;
	int t, n;
	int in;
	int l, r;
	vector<int> answer;
	cin >> t;
	for(h=0; h<t; h++) {
		cin >> n;
		vector<int> a;
		for(i=0; i<n; i++) {
			cin >> in;
			a.push_back(in);
		}
		int par = 1;
		for(i=0; i<n; i++) {
			if(i%2 == a[i]%2) {
				par = 0;
				break;
			}
		}
		if(par) {
			answer.clear();
			for(i=n-1; i>=2; i-=2) {
				r = find(a.begin(), a.end(), i+1)-a.begin();
				flip(a, r+1);
				answer.push_back(r+1);
				l = find(a.begin(), a.end(), i)-a.begin();
				flip(a, l);
				answer.push_back(l);
				flip(a, l+2);
				answer.push_back(l+2);
				flip(a, 3);
				answer.push_back(3);
				flip(a, i+1);
				answer.push_back(i+1);
			}
			printf("%d\n", answer.size());
			for(i=0; i<answer.size(); i++) {
				printf("%d ", answer[i]);
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	}
}