/*
ID: Sfiction
OJ: CF
PROB: 451D
*/
#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN=30;
const long long MOD=1E9+7;

int n;
long long s, ans;
long long f[MAXN], inv[MAXN];

long long quickexp(long long x,long long n){
	long long ret=1;
	for (;n;n>>=1){
		if (n&1)
			ret=(ret*x)%MOD;
		x=(x*x)%MOD;
	}
	return ret;
}

long long comb(long long n,long long r){
	long long ret=1;
	n%=MOD;
	if (n<r)
		return 0;
	for (;r;--n,--r){
		ret=(ret*n)%MOD;
		ret=(ret*inv[r])%MOD;
	}
	return ret;
}

void DFS(bool flag,int depth,long long s){
	if (depth==n){
		if (flag)
			ans=(ans+comb(s,n-1))%MOD;
		else
			ans=(ans-comb(s,n-1)+MOD)%MOD;
		return;
	}
	DFS(flag,depth+1,s);
	if ((s-=f[depth]+1)>=n-1)
		DFS(!flag,depth+1,s);
}

int main(){
	cin >> n >> s;
	for (int i=0;i<n;++i){
		cin >> f[i];
		inv[i]=quickexp(i,MOD-2);
	}
	DFS(1,0,s+n-1);
	cout << ans << endl;
	return 0;
}