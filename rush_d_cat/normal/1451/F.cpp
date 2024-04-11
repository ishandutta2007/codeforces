#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100 + 10;
int t,n,m,a[N][N];
int main() {
	scanf("%d", &t);
	while(t--){
		scanf("%d%d",&n,&m);
		int res[222] = {0};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				res[i+j] ^= a[i][j];
			}
		}
		bool ok = 0;
		for(int i=0;i<222;i++)
			if(res[i]) ok=1;
		printf("%s\n", ok?"Ashish":"Jeel");
    }
}