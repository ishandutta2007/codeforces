#include <bits/stdc++.h>
using namespace std;

const int N = 200011;
int a[N];

int main() {
	int n, s; scanf("%d%d", &n, &s);
	int ans = 0, sp = 0;
	deque <int> v;
	for(int i = 0; i < n; i ++) {
		scanf("%d", a + i);
		if(i + 1 == s) {
			if(a[i] != 0) {
				ans ++;
			}
		} else {
			if(a[i] == 0) { sp ++; ans ++; }
			else v.push_back(a[i]);
		}
	}
	sort(v.begin(), v.end());
	int now = 1;
	while(!v.empty()) {
		if(now < *v.begin()) {
			if(sp) { now ++; sp --; }
			else { now ++; v.pop_back(); ans ++; }
		} else {
			if(now == *v.begin())
				now ++;
			v.pop_front();
		}
	}
	cout << ans << '\n';
	return 0;
}