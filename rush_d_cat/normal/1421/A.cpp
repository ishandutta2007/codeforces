#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
int main() {
	scanf("%d",&t);
	while(t--){
		int x,y;
		scanf("%d%d",&x,&y);
		LL ans=0;
		for(int i=30;i>=0;i--){
			int c1=(x>>i)&1;
			int c2=(y>>i)&1;
			if(c1==c2) {
				//ans += 2LL*(1<<i);
			}else{
				ans += 1LL<<i;
			}
		}
		printf("%lld\n", ans);
	}

}