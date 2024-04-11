#include <bits/stdc++.h>
using namespace std;

int a,b,c,d,k;

void solve(){
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
	int usea=(a+c-1)/c,useb=(b+d-1)/d;
	if(usea+useb>k){
		puts("-1");
		return;
	}
	printf("%d %d\n",usea,useb);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}