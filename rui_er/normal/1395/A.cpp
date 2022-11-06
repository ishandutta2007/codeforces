//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T, a, b, c, d; 

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if((a&1)+(b&1)+(c&1)+(d&1) <= 1) {
			puts("YES");
			continue;
		}
		if(!a || !b || !c) {
			puts("NO");
			continue;
		}
		bool _ = false;
		int __ = 0;
		while(a && b && c) {
			--a;
			--b;
			--c;
			d += 3;
			++__;
			if((a&1)+(b&1)+(c&1)+(d&1) <= 1) {
				puts("YES");
				_ = true;
				break;
			}
			if(__ > 6) break;
		}
		if(!_) puts("NO");
	}
	return 0;
}