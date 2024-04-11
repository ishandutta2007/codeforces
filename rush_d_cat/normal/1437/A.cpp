#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t;
int main() {
	scanf("%d",&t);
	while(t--){
		int l,r;scanf("%d%d",&l,&r);
		printf("%s\n", (r+1)<=2*l?"YES":"NO");
	}
}