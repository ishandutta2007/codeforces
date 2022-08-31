#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e5+5;
int n,k,cur,is,x;
int main(){
	scanf("%d%d",&n,&k);
	rep(i,n){
		scanf("%d",&x);
		x%=k;
		if(x==0)continue;
		x=__gcd(x,k);
		if(is==0)cur=x,is=1;
		else cur=__gcd(cur,x);
	}
	if(is==0){
		puts("1");
		puts("0");
	}else{
		printf("%d\n",k/cur);
		rep(i,k/cur)printf("%d%c",(i-1)*cur," \n"[i==k/cur]);
	}
	//system("pause");
	return 0;
}