#include <bits/stdc++.h>
using namespace std;

int n,m;
const int jt=1000000007;

int ksmii(int a,int b){
	if(!b){
		return 1;
	}
	int x=ksmii(a,b/2);
	x=1ll*x*x%jt;
	if(b%2){
		x=1ll*x*a%jt;
	}
	return x;
}

int main(){
	scanf("%d%d",&n,&m);
	int ans=(ksmii(2,m)+jt-1)%jt;
	ans=ksmii(ans,n);
	printf("%d\n",ans);
	return 0;
}