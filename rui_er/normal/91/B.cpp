//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int n, a[N], mi[N];

int main() {
	memset(mi, 0x3f, sizeof(mi));
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	for(int i=n;i>=1;i--) mi[i] = min(mi[i+1], i==n?0x3f3f3f3f:a[i+1]);
	for(int i=1;i<=n;i++) {
		if(mi[i] >= a[i]) printf("-1 ");
		else {
			int l = i + 1, r = n;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(mi[mid] >= a[i]) r = mid - 1;
				else l = mid + 1;
			}
			printf("%d ", l-i-1);
		}
	}
	return 0;
}