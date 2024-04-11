#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int T, n;
char s[N], t[N];
char F(char c) {
	return (char)((int)'1' + (int)'0' - c);
}
int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		scanf("%s%s", s+1, t+1);
		bool flag = 0;
		vector<int> ans;
		int l = 1, r = n;
		for (int i = n; i >= 1; i --) {
			if (flag == 0) {
				if (s[r] != t[i]) {
					if (s[l] == t[i]) {
						ans.push_back(1);
						s[l] = F(s[l]);
					}
					flag = 1;
					l ++;
					ans.push_back(i);
				} else {
					r --;
				}
			} else {
				if (F(s[l]) != t[i]) {
					if (F(s[r]) == t[i]) {
						ans.push_back(1);
						s[r] = F(s[r]); 
					}
					flag = 0;
					r --;
					ans.push_back(i);
				} else {
					l ++;
				}
			}
		}
		printf("%d ", ans.size());
		for (auto x: ans) printf("%d ", x);
		printf("\n");
	}

}