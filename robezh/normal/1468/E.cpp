#include<bits/stdc++.h>
using namespace std;

void solve() {
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int ans = 0;
	ans = max(ans, min(a,c) * min(b,d));
	ans = max(ans, min(a,b) * min(c,d));
	ans = max(ans, min(a,d) * min(b,c));
	printf("%d\n",ans);
}

int main() {
	int tnum; scanf("%d",&tnum);
	for(int i=1;i<=tnum;i++) solve();
}