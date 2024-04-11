#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	scanf("%d",&t);
	while(t--){
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		printf("%lld\n", 1LL*x+y+z-1);
	}
}