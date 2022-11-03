/*
ID: Sfiction
OJ: CF
PROB: 449D
*/
#include <cstdio>
#include <iostream>

using namespace std;

const int MAXD=20,MAXN=1<<MAXD;
long long MOD=1E9+7;

long long f[MAXD+1][MAXN];
int cnt[MAXN];

long long bexp(long long n){
	long long ret=1,e=2;
	for (;n;n>>=1){
		if (n&1)
			ret=(ret*e)%MOD;
		e=(e*e)%MOD;
	}
	return ret;
}

int main(){
	int n;

	scanf("%d",&n);
	for (int t,i=0;i<n;++i){
		scanf("%d",&t);
		++f[0][t];
	}

	for (int k=1;k<=MAXD;++k){
		long long d=1<<(k-1);
		for (int i=0;i<MAXN;++i)
			if (i&d){
				cnt[i]^=1;
				f[k][i]=f[k-1][i];
			}
			else
				f[k][i]=(f[k-1][i]+f[k-1][i|d])%MOD;
	}
	
	long long sum=0;
	for (int i=0;i<MAXN;++i)
		if (cnt[i])
			sum=(sum-bexp(f[MAXD][i])+MOD)%MOD;
		else
			sum=(sum+bexp(f[MAXD][i]))%MOD;
	cout << sum << endl;
	return 0;
}