#include <bits/stdc++.h>
using namespace std;
int n, m, a;
int main() {
	scanf("%d %d", &n, &m);
	vector<int> p, c;
	for(int i = 2; m >= 2; i++) {
		if(m % i == 0) {
			p.push_back(i);
			c.push_back(0);
			while(m % i == 0) m /= i, c.back()++;
		}
	}
	int ret = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		for(int j = 0; j < p.size(); j++) {
			int cp = 0;
			while(a % p[j] == 0) a /= p[j], cp++;
			if(cp >= c[j]) ret |= 1 << j;
		}
	}
	cout << (ret + 1 == (1 << p.size()) ? "Yes" : "No") << endl;
	return 0;
}