#include <bits/stdc++.h>
using namespace std;
int t, n0, n1, n2;
bool chk(vector<int> v) {
	//for (auto x :v) printf("%d", x); printf("\n");
	int c0 = 0, c1 = 0, c2 = 0;
	for (int i = 0; i + 1 < v.size(); i ++) {
		if (v[i] == 0 && v[i+1] == 0) c0 ++;
		if (v[i] != v[i+1]) c1 ++;
		if (v[i] == 1 && v[i+1] == 1) c2 ++;
	}
	return c0 == n0 && c1 == n1 && c2 == n2; 
}
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d%d", &n0, &n1, &n2);

		{
			int seg0 = (n1 + 1) / 2;
			int seg1 = n1 + 1 - seg0;
			int cnt0 = seg0 + n0;
			int cnt1 = seg1 + n2;
			vector<int> v;
			while (seg0>0 || seg1>0) {
				if (seg1) {
					if (seg1 == 1) {
						for(int i=1;i<=cnt1;i++) v.push_back(1);
						cnt1=0;
					} else {
						v.push_back(1); cnt1--;
					}
					seg1--;
				}
				if (seg0) {
					if (seg0 == 1) {
						for(int i=1;i<=cnt0;i++) v.push_back(0);
						cnt0=0;
					} else {
						v.push_back(0); cnt0--;
					}
					seg0--;
				}
			}
			if (chk(v)) {
				for (auto x: v) printf("%d", x); printf("\n");
				continue;
			}
		}

		{
			int seg0 = (n1 + 2) / 2;
			int seg1 = n1 + 1 - seg0;
			int cnt0 = seg0 + n0;
			int cnt1 = seg1 + n2;
			vector<int> v;
			while (seg0>0 || seg1>0) {
				if (seg1) {
					if (seg1 == 1) {
						for(int i=1;i<=cnt1;i++) v.push_back(1);
						cnt1=0;
					} else {
						v.push_back(1); cnt1--;
					}
					seg1--;
				}
				if (seg0) {
					if (seg0 == 1) {
						for(int i=1;i<=cnt0;i++) v.push_back(0);
						cnt0=0;
					} else {
						v.push_back(0); cnt0--;
					}
					seg0--;
				}
			}
			if (chk(v)) {
				for (auto x: v) printf("%d", x); printf("\n");
				continue;
			}
		}
	}
}

// 00001010111111
// cnt0 - seg0 = n0
// cnt1 - seg1 = n2
// seg0 + seg1 - 1 = n1
// 01010