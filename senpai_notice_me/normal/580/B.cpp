#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 100005

struct Friend {
	long long cost,fri;
	inline bool operator < (const Friend& rhs) const {
		return cost<rhs.cost;
	}
	inline void input() {
		scanf("%I64d%I64d",&cost,&fri);
	}
}fr[MAX_N];

int n,d;

inline void Init() {
	scanf("%d%d",&n,&d);
	for (int i=1;i<=n;i++) fr[i].input();
}

inline void Solve() {
	sort(fr+1,fr+n+1);
	long long ans=0,tmp=0; int head=1;
	for (int i=1;i<=n;i++) {
		tmp+=fr[i].fri;
		while (fr[i].cost-fr[head].cost>=d) tmp-=fr[head++].fri;
		ans=max(ans,tmp);
	}
	printf("%I64d\n",ans);
}

int main() {
	Init(); Solve();
	
	return 0;
}

//	freopen(".in","r",stdin); freopen(".out","w",stdout);