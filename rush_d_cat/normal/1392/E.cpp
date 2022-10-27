#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n; 
LL a[30][30];
int main() {
	scanf("%d", &n);

	bool flag = 0; LL x = 0;
	for(int i=2;i<=n*2;i++){
		int cnt=0;
		for(int j=i-1;j>=1;j--){
			int r=j,c=i-j;
			if(r<=n&&r>=1 && c<=n&&c>=1){
				cnt++;
				if(cnt%2==0 && flag==0)
					a[j][i-j]=x;
				if(cnt%2==1 && flag==1)
					a[j][i-j]=x;
			}
		}
		flag ^= 1;
		if(x==0) x=1;
		else x<<=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%lld ", a[i][j]);
		}
		printf("\n"); fflush(stdout);
	}

	int q; scanf("%d",&q);
	while(q--){
		LL k; scanf("%lld",&k);
		int x=1,y=1;
		int cur = 0;
		while(1){
			printf("%d %d\n", x,y); fflush(stdout);
			if(x==n && y==n) break;
			if(x==n) {
				y++;
			} else if (y==n) {
				x++;
			} else {
				if(k>>cur&1) {
					if(a[x+1][y]>>cur&1) x++;
					else if(a[x][y+1]>>cur&1) y++;
				}else{
					if(a[x+1][y]>>cur&1) y++;
					else if(a[x][y+1]>>cur&1) x++;					
				}
				++cur;
			}
		}
	}
}