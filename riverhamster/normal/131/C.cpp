#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[205][205];
ll com(int n,int m){
	if(f[n][m]!=0) return f[n][m];
	if(n==0 or m==0 or n==m) return 1;
	else return f[n][m]=com(n-1,m-1)+com(n-1,m);
}
int main(){
	ll n,m,t,ans=0;
	scanf("%I64d%I64d%I64d",&n,&m,&t);
	for(int i=4;i<=n;i++){
		if(m>=t-i and t-i>0) ans+=com(n,i)*com(m,t-i);
	}
	printf("%I64d\n",ans);
	return 0; 
}