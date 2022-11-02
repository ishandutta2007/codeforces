#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	int lend, rend;
	for(lend=0; lend<n-1 && a[lend]<a[lend+1]; lend++);
	for(rend=n-1; rend>0 && a[rend]<a[rend-1]; rend--);
	int l=0, r=n-1;
	int turn = 0;
	int winner = -1;
	while(winner == -1) {
		if(a[l] < a[r]) {
			if((r-rend)%2 == 0) {
				winner = turn;
			} else {
				l++;
			}
		} else {
			if((lend-l)%2 == 0) {
				winner = turn;
			} else {
				r--;
			}
		}
		if(l > lend) {
			winner = (turn+r-rend+1)%2;
		} else if(r < rend) {
			winner = (turn+lend-l+1)%2;
		}
		turn = (turn+1)%2;
	}
	if(winner == 0) {
		printf("Alice\n");
	} else {
		printf("Bob\n");
	}
}