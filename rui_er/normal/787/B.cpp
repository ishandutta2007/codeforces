//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, int> mp;

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) {
		int _;
		scanf("%d", &_);
		mp.clear();
		bool ok = false;
		while(_--) {
			int x;
			scanf("%d", &x);
			if(mp[-x]) ok = true;
			mp[x] = 1;
		}
		if(!ok) return puts("YES"), 0;
	}
	puts("NO");
	return 0;
}