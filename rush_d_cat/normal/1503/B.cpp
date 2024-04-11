#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

set< pair<int,int> > s1, s2;

void solve(set< pair<int,int> > & st, int col) {
	assert(st.size() > 0);
	auto p = (*st.begin()); st.erase(p);
	printf("%d %d %d\n", col, p.first, p.second);
	fflush(stdout);
}

int main() {
	int n;
	scanf("%d", &n);	
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) {
		if ((i + j) % 2 == 0) 
			s2.insert(make_pair(i, j));
		else 
			s1.insert(make_pair(i, j));
	}

	int it = n * n, stage = 1;
	int run_out = 1;
	while (it --) {
		int a;
		scanf("%d", &a);

		if (stage == 1) {
			if (a == 1) {
				solve(s2, 2);
			} else {
				solve(s1, 1);
			}
			if (s1.size() == 0) {
				stage = 2; run_out = 1;
			} else if (s2.size() == 0) {
				stage = 2; run_out = 2;
			}
		} else {

			if (run_out == 1) {
				if (a == 1 || a == 3) {
					solve(s2, 2);
				} else if (a == 2) {
					solve(s2, 3);
				}
			} 

			if (run_out == 2) {
				if (a == 2 || a == 3) {
					solve(s1, 1);
				} else {
					solve(s1, 3);
				}
			}
		}

	}

}