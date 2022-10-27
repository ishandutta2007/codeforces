#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100 + 10;
int t,n,m,a[N][N];
int main() {
	scanf("%d", &t);
	while(t--){
    	scanf("%d%d",&n,&m);
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			int x; scanf("%d",&x);
    			if(x%2 != (i+j)%2) x++;
    			printf("%d ", x);
    		}
    		printf("\n");
    	}
    }
}