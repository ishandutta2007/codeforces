
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
int main() {
	scanf("%d",&t);
	while(t--){
		int x,y; scanf("%d%d",&x,&y);
		int c=min(x,y);
		x-=c,y-=c;
		c*=2;
		int need = max(x,y);

		//printf("need = %d, c = %d\n", need, c);
		if(need > 0) {
			if(need % 2 == 1) {
				c += 2 * need - 1;
			} else {
				c += 2 * need - 1;
			}
		}
		printf("%d\n", c);
	}
}
/*
1
3
5
*/