#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

inline void Init() {
	scanf("%d",&n);
}

inline void Solve() {
	int ans=0,tmp=0,last=0,x;
	while (n--) {
		scanf("%d",&x);
		if (x>=last) tmp++;
		else {
			ans=max(ans,tmp); tmp=1;
		}
		last=x;
	}
	ans=max(ans,tmp);
	printf("%d\n",ans);
}

int main() {
	Init(); Solve();
	
	return 0;
}

//	freopen(".in","r",stdin); freopen(".out","w",stdout);