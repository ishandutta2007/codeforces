#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,x1,y_1,x2,y2;
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&x1,&y_1,&x2,&y2);
		if(x1==x2) {
			printf("%d\n", abs(y_1-y2));
		}else if(y_1==y2){
			printf("%d\n", abs(x1-x2));
		}else{
			printf("%lld\n", 2LL + (abs(x1-x2) + abs(y_1-y2)));
		}
	}
}