#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	vector<vector<int>> a1(101, vector<int>(101));
	vector<vector<int>> b1(101, vector<int>(101));
	for(i=0; i<=100; i++) {
		if(i%4 == 1 || i%4 == 2) {
			a1[0][i] = 0;
			b1[0][i] = 1;
		} else {
			a1[0][i] = 1;
			b1[0][i] = 0;
		}
		a1[i][0] = 1;
		b1[i][0] = 0;
	}
	for(i=1; i<=100; i++) {
		for(j=1; j<=100; j++) {
			a1[i][j] = 0;
			b1[i][j] = 0;
			if(j%2 == 0) {
				a1[i][j] = max(a1[i][j], 1-b1[i-1][j]);
			} else {
				a1[i][j] = max(a1[i][j], 1-a1[i-1][j]);
			}
			if(j%2 == 0) {
				a1[i][j] = max(a1[i][j], 1-b1[i][j-1]);
			} else {
				a1[i][j] = max(a1[i][j], 1-a1[i][j-1]);
			}
			if(j%2 == 0) {
				b1[i][j] = max(b1[i][j], 1-a1[i-1][j]);
			} else {
				b1[i][j] = max(b1[i][j], 1-b1[i-1][j]);
			}
			if(j%2 == 0) {
				b1[i][j] = max(b1[i][j], 1-a1[i][j-1]);
			} else {
				b1[i][j] = max(b1[i][j], 1-b1[i][j-1]);
			}
			//printf("%d %d %d %d\n", i, j, a1[i][j], b1[i][j]);
		}
	}
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<int> a(n);
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		vector<int> count(2, 0);
		for(i=0; i<n; i++) {
			if(a[i]%2) {
				count[1]++;
			} else {
				count[0]++;
			}
		}
		//printf("%d %d\n", count[0], count[1]);
		if(a1[count[0]][count[1]]) {
			printf("Alice\n");
		} else {
			printf("Bob\n");
		}
	}
}