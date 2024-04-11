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
				if((i != mid && a[i] <= a[j]) || j == r) {
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
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		vector<int> a, b;
		for(i=0; i<n; i++) {
			scanf("%d", &in);
			a.push_back(in);
		}
		for(i=0; i<m; i++) {
			scanf("%d", &in);
			b.push_back(in);
		}
		sort(b.begin(), b.end());
		int pos[m];
		function<int(int, int, int, int)> find_pos = [&](int bl, int br, int al, int ar) {
			if(bl == br) {
				return 0;
			}
			int i;
			int mid = (bl+br)/2;
			int min_idx = al-1;
			int min_val;
			int val = 0;
			for(i=al; i<ar; i++) {
				if(a[i] < b[mid]) {
					val++;
				}
			}
			min_val = val;
			for(i=al; i<ar; i++) {
				if(a[i] < b[mid]) {
					val--;
				} else if(a[i] > b[mid]) {
					val++;
				}
				if(val < min_val) {
					min_idx = i;
					min_val = val;
				}
			}
			pos[mid] = min_idx+1;
			//printf("%d %d %d %d %d %d\n", bl, br, al, ar, mid, min_val);
			if(bl+1 < br) {
				find_pos(bl, mid, al, min_idx+1);
				find_pos(mid+1, br, min_idx+1, ar);
			}
			return 0;
		};
		find_pos(0, m, 0, n);
		vector<int> c;
		for(i=0, j=0; i<n; i++) {
			for(; j<m && pos[j] == i; j++) {
				c.push_back(b[j]);
			}
			c.push_back(a[i]);
		}
		for(; j<m; j++) {
			c.push_back(b[j]);
		}
		long long answer = count_inv(c);
		printf("%lld\n", answer);
	}
}