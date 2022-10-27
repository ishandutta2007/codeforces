#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;

int t, n;
int a[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		set<int> st;
		for (int i = 0; i < n; i ++) {
			scanf("%d", &a[i]);
			st.insert(((i + a[i]) % n + n) % n);
		}
		printf("%s\n", st.size() == n ? "YES" : "NO");
	} 
}