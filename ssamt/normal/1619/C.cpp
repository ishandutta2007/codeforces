#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		char as[20], bs[20];
		scanf("%s %s", as, bs);
		vector<int> a, b;
		for(i=0; as[i]; i++) {
			a.push_back(as[i]-'0');
		}
		for(i=0; bs[i]; i++) {
			b.push_back(bs[i]-'0');
		}
		vector<int> ans;
		int check = 1;
		while(!a.empty()) {
			if(b.empty()) {
				check = 0;
				break;
			}
			if(a.back() <= b.back()) {
				ans.push_back(b.back()-a.back());
				a.erase(a.end()-1);
				b.erase(b.end()-1);
			} else {
				if(b.size() >= 2 && b[b.size()-2] == 1) {
					ans.push_back(10+b.back()-a.back());
					a.erase(a.end()-1);
					b.erase(b.end()-1);
					b.erase(b.end()-1);
				} else {
					check = 0;
					break;
				}
			}
		}
		while(!b.empty()) {
			ans.push_back(b.back());
			b.erase(b.end()-1);
		}
		while(ans.back() == 0) {
			ans.erase(ans.end()-1);
		}
		if(check) {
			for(i=ans.size()-1; i>=0; i--) {
				printf("%d", ans[i]);
			}
			printf("\n");
		} else {
			printf("-1\n");
		}
	}
}