#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
	scanf("%d", &t);
	while (t --) {
		int x; scanf("%d", &x);
		vector<int> v;
		while (x) {
			v.push_back(x % 10); x /= 10;
		}
		int c = 0;
		for (auto x: v) if (x) c ++;
		printf("%d\n", c);
		int p = 1;
		for (int i = 0; i < v.size(); i ++) {
			if (v[i]) printf("%d ", v[i] * p);
			p *= 10;
		}	
		printf("\n");
	}
}