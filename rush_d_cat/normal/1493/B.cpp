#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,h,m;
bool ok(int x) {
	return x==0||x==1||x==2||x==5||x==8;
}
int change(int x){
	if(x==0||x==1||x==8)return x;
	if(x==2)return 5;
	return 2;
}
int f(int x){
	return 10*change(x%10) + change(x/10);
}
bool chk(int x,int y){
	return ok(x%10)&&ok(x/10)&&ok(y%10)&&ok(y/10)&&f(x)<m&&f(y)<h;
}
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d",&h,&m);
		int H,M; scanf("%d:%d",&H,&M);
		bool ok=false;
		for (int i=H;;i++) {
			int cnt = 0;
			for(int j=(i==H?M:0);;j++){
				if(j==m)break;
				cnt ++;
				int ii=i%h,jj=j%m;
				if(chk(ii,jj)){
					printf("%d%d:%d%d\n", ii/10,ii%10,jj/10,jj%10);
					ok=true;
					break;
				}
				if (cnt == m) break;
			}
			if(ok)break;
		}

	}
}