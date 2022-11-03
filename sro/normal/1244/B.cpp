#include <bits/stdc++.h>
using namespace std;

int n;
char s[1005];

void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int bg=-1,en;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			bg=i;
			break;
		}
	}
	for(int i=n;i>=1;i--){
		if(s[i]=='1'){
			en=i;
			break;
		}
	}
	if(!~bg){
		printf("%d\n",n);
		return;
	}
	printf("%d\n",max(en*2,(n-bg+1)*2));
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}