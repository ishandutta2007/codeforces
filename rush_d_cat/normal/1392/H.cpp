#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000000 + 10;
const LL MOD = 998244353;
LL mpow(LL a,LL x){
	if(x==0)return 1;
	LL t=mpow(a,x>>1);
	if(x%2==0)return t*t%MOD;
	return t*t%MOD*a%MOD;
}
LL inv(int x){
	return mpow(x,MOD-2);
}
LL sum[N];
int main() {
	for(int i=1;i<N;i++) sum[i]=(sum[i-1]+inv(i))%MOD;
	LL n,m; cin>>n>>m;
	LL A = (n*inv(m+1)+1)%MOD;
	LL B = (m*sum[n]+1)%MOD;
	cout<<A*B%MOD<<endl;
}