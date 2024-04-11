#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n, k, cur;
int a[N];
stack<int> st;

int main() {
	scanf("%d%d", &n, &k);
	cur = 1;
	st.push(N); st.push(n + 1);
	for(int i = 0; i < n; i++) {
		if(i < k) scanf("%d", a + i);
		else a[i] = st.top() - 1;
		st.push(a[i]);
		while(st.top() == cur) st.pop(), cur++;
	}
	if(st.size() > 1) {
		printf("-1"); return 0;
	}
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}