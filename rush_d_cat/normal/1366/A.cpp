#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,a,b;
int main() {
	scanf("%d", &t);
	while (t--){
		scanf("%d%d",&a,&b);
		if(a>=2*b){
			printf("%d\n", b);
		} else if(b>=2*a) {
			printf("%d\n", a);
		} else {
			int tot=(a+b)/3;
			printf("%d\n", tot);
		}
	}
}