#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 502;
int t, n;
pair<int,int> p[N];

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &p[i].first);
		}
		set<int> st;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &p[i].second);
			st.insert(p[i].second);
		}

		if (st.size() == 1) {
			bool flag = 1;
			for (int i  =1; i < n; i ++) if (p[i].first > p[i+1].first) flag = 0;
			printf("%s\n", flag ? "Yes" : "No");
		} else {
			printf("Yes\n");
		}
	}
}