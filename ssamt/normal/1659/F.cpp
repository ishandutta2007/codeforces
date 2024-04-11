#include <bits/stdc++.h>

using namespace std;

long long count_inv(vector<int>& input) {
	int i;
	int n = input.size();
	int a[n];
	for(i=0; i<n; i++) {
		a[i] = input[i];
	}
	function<long long(int, int)> merge_count = [&](int l, int r) {
		int i, j;
		if(l+1 < r) {
			long long answer = 0;
			int mid = (l+r)/2;
			int s[r-l];
			answer += merge_count(l, mid);
			answer += merge_count(mid, r);
			for(i=l, j=mid; i<mid || j<r;) {
				if(j == r || (i != mid && a[i] <= a[j])) {
					s[(i-l)+(j-mid)] = a[i];
					answer += j-mid;
					i++;
				} else {
					s[(i-l)+(j-mid)] = a[j];
					j++;
				}
			}
			for(i=0; i<r-l; i++) {
				a[i+l] = s[i];
			}
			return answer;
		} else {
			return (long long)0;
		}
	};
	return merge_count(0, n);
}

int main() {
	int i, j, k, l;
	int t, n, m, q;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		int x;
		scanf("%d %d", &n, &x);
		x--;
		vector<int> count(n, 0);
		for(i=0; i<n-1; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			u--, v--;
			count[u]++;
			count[v]++;
		}
		vector<int> p(n);
		for(i=0; i<n; i++) {
			int in;
			scanf("%d", &in);
			in--;
			p[in] = i;
		}
		auto mp = max_element(count.begin(), count.end());
		if(*mp == n-1) {
			int idx = mp-count.begin();
			if(n == 3) {
				if(x == idx) {
					if(p[x] == x) {
						printf("Alice\n");
					} else {
						printf("Bob\n");
					}
				} else {
					if(p[x] == x || (p[x] == 3-x-idx && p[3-x-idx] == idx)) {
						printf("Alice\n");
					} else {
						printf("Bob\n");
					}
				}
			} else {
				if((x == idx && p[x] != idx) || (x != idx && p[x] == idx)) {
					printf("Bob\n");
				} else {
					int diff = 0;
					long long inv = 0;
					for(i=0; i<n; i++) {
						if(p[i] != i) {
							diff++;
						}
					}
					inv = count_inv(p);
					if(x == idx && p[x] == idx) {
						if(diff == 0 || inv%2 == 1) {
							printf("Alice\n");
						} else {
							printf("Bob\n");
						}
					} else if(x != idx && p[idx] == idx) {
						if(diff == 0 || (diff == 2 && p[x] == x) || inv%2 == 0) {
							printf("Alice\n");
						} else {
							printf("Bob\n");
						}
					} else {
						for(i=0; p[i]!=idx; i++);
						swap(p[idx], p[i]);
						x = idx;
						if(diff <= 2 || inv%2 == 0) {
							printf("Alice\n");
						} else {
							printf("Bob\n");
						}
					}
				}
			}
		} else {
			printf("Alice\n");
		}
	}
}