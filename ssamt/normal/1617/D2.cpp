#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int group[n/3];
		for(i=0; i<n/3; i++) {
			printf("? %d %d %d\n", 3*i+1, 3*i+2, 3*i+3);
			fflush(stdout);
			scanf("%d", &group[i]);
		}
		int zerog, oneg;
		for(zerog=0; group[zerog]==1; zerog++);
		for(oneg=0; group[oneg]==0; oneg++);
		vector<int> ring;
		for(i=0; i<3; i++) {
			ring.push_back(3*zerog+i);
		}
		for(i=0; i<3; i++) {
			ring.push_back(3*oneg+i);
		}
		int val[4];
		for(i=0; i<4; i++) {
			printf("? %d %d %d\n", ring[i]+1, ring[i+1]+1, ring[i+2]+1);
			fflush(stdout);
			scanf("%d", &val[i]);
		}
		int pos;
		for(pos=0; !(val[pos]==0 && val[pos+1]==1); pos++);
		int zero = ring[pos], one = ring[pos+3];
		int answer[n];
		answer[zero] = 0;
		answer[one] = 1;
		for(i=0; i<6; i++) {
			if(ring[i]!=zero && ring[i]!=one) {
				printf("? %d %d %d\n", zero+1, one+1, ring[i]+1);
				fflush(stdout);
				scanf("%d", &answer[ring[i]]);
			}
		}
		for(i=0; i<n/3; i++) {
			if(i!=zerog && i!=oneg) {
				int r1, r2;
				if(group[i] == 0) {
					printf("? %d %d %d\n", 3*i+1, 3*i+2, one+1);
					fflush(stdout);
					scanf("%d", &r1);
					printf("? %d %d %d\n", 3*i+2, 3*i+3, one+1);
					fflush(stdout);
					scanf("%d", &r2);
					if(r1 == 0) {
						if(r2 == 0) {
							answer[3*i] = 0;
							answer[3*i+1] = 0;
							answer[3*i+2] = 0;
						} else {
							answer[3*i] = 0;
							answer[3*i+1] = 0;
							answer[3*i+2] = 1;
						}
					} else {
						if(r2 == 0) {
							answer[3*i] = 1;
							answer[3*i+1] = 0;
							answer[3*i+2] = 0;
						} else {
							answer[3*i] = 0;
							answer[3*i+1] = 1;
							answer[3*i+2] = 0;
						}
					}
				} else {
					printf("? %d %d %d\n", 3*i+1, 3*i+2, zero+1);
					fflush(stdout);
					scanf("%d", &r1);
					printf("? %d %d %d\n", 3*i+2, 3*i+3, zero+1);
					fflush(stdout);
					scanf("%d", &r2);
					if(r1 == 0) {
						if(r2 == 0) {
							answer[3*i] = 1;
							answer[3*i+1] = 0;
							answer[3*i+2] = 1;
						} else {
							answer[3*i] = 0;
							answer[3*i+1] = 1;
							answer[3*i+2] = 1;
						}
					} else {
						if(r2 == 0) {
							answer[3*i] = 1;
							answer[3*i+1] = 1;
							answer[3*i+2] = 0;
						} else {
							answer[3*i] = 1;
							answer[3*i+1] = 1;
							answer[3*i+2] = 1;
						}
					}
				}
			}
		}
		int count = 0;
		for(i=0; i<n; i++) {
			if(answer[i] == 0) {
				count++;
			}
		}
		printf("! %d ", count);
		for(i=0; i<n; i++) {
			if(answer[i] == 0) {
				printf("%d ", i+1);
			}
		}
		printf("\n");
		fflush(stdout);
	}
}