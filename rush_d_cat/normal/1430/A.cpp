#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n;
int main() {
	scanf("%d", &t);
	while(t--){
		scanf("%d",&n);
		bool ok=0;
		for(int z=0;z*7<=n;z++){
			int r=n-z*7;
			for(int x=0;x<=5;x++){
				if(3*x<=r && (r-3*x)%5==0){
					ok=1;
					printf("%d %d %d\n", x,(r-3*x)/5,z);
					break;
				}
			}
			if(ok)break;
		}
		if(!ok)printf("-1\n");
	}
}