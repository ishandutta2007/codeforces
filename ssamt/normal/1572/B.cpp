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

vector<int> solve(vector<int>& a) {
	int i, j;
	int n = a.size();
	vector<int> b;
	int ones = 0;
	for(i=0; i<n; i++) {
		if(a[i] == 1) {
			ones++;
		}
	}
	if(ones%2 == 1) {
		b.push_back(-1);
		return b;
	}
	if(n < 3) {
		return b;
	}
	if(a[0] == 0) {
		for(i=0; i<n-3; i+=2) {
			b.push_back(i+1);
			b.push_back(i);
		}
		if(n%2 == 1) {
			b.push_back(n-3);
		}
		return b;
	}
	ones = 0;
	for(i=0; i<n; i++) {
		if(a[i] == 1) {
			ones++;
		} else {
			if(ones%2 == 0) {
				for(j=i; j>=3; j-=2) {
					b.push_back(j-3);
					b.push_back(j-2);
				}
				if(i >= 2 && (i+1)%2 == 1) {
					b.push_back(0);
				}
				for(j=i; j<n-3; j+=2) {
					b.push_back(j+1);
					b.push_back(j);
				}
				if(i <= n-3 && (n-i)%2 == 1) {
					b.push_back(n-3);
				}
				return b;
			} else {
				if(a[i-1] == 1) {
					for(j=i; a[j]==0; j++);
					int end = j;
					if((end-i)%2 == 1) {
						for(j=i-1; j<end-3; j+=2) {
							b.push_back(j);
						}
						b.push_back(end-2);
						for(j=end-4; j>=i-1; j-=2) {
							b.push_back(j);
						}
						i--;
						for(j=i; j>=3; j-=2) {
							b.push_back(j-3);
							b.push_back(j-2);
						}
						if(i >= 2 && (i+1)%2 == 1) {
							b.push_back(0);
						}
						for(j=end; j<n-3; j+=2) {
							b.push_back(j+1);
							b.push_back(j);
						}
						if(end <= n-3 && (n-end)%2 == 1) {
							b.push_back(n-3);
						}
						return b;
					}
				}
			}
		}
	}
	b.push_back(-1);
	return b;
}

int main() {
	int h, i, j;
	int t, n;
	int in;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		vector<int> a;
		for(i=0; i<n; i++) {
			scanf("%d", &in);
			a.push_back(in);
		}
		vector<int> b = solve(a);
		if(b[0] == -1) {
			printf("NO\n");
		} else {
			printf("YES\n");
			printf("%d\n", b.size());
			for(i=0; i<b.size(); i++) {
				printf("%d ", b[i]+1);
			}
			printf("\n");
		}
	}
}