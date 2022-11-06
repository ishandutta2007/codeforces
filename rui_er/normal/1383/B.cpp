//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int T, n, x;
int a[N], bit[2]; 

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		x = bit[0] = bit[1] = 0;
		for(int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
			x ^= a[i];
		}
		if(!x) {
			puts("DRAW");
			continue;
		}
		for(int i=30;i>=0;i--) {
			int uBit = x >> i;
			if(uBit&1) {
				for(int j=1;j<=n;j++) {
					int vBit = a[j] >> i;
					++bit[vBit&1];
				}
				if(!(bit[0]&1) && ((bit[1]&3) == 3)) puts("LOSE");
				else puts("WIN");
				break;
			}
		}
	}
	return 0;
}