#include <bits/stdc++.h>

const int max_N = 1e3 + 21;

const int mod = 1e9 + 7;

char s[max_N];

int sum[max_N];

int n,k,C[max_N][max_N];

int f[max_N],cnt[max_N];

inline int calc(int k){
	int res=0;
	for(int i=0;i<n;++i){
		if(i&&sum[i-1]>k)continue;
		if(s[i]!='1')continue;
		if(n-i-1<k-(i?sum[i-1]:0))continue;
		res=(res+C[n-i-1][k-(i?sum[i-1]:0)])%mod;
	}
	if(k==sum[n-1])(++res)%=mod;
	return res;
}

int main(){
	C[0][0]=1;
	for(int i=1;i<=1000;++i){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	for(int i=1;i<=1000;++i){
		cnt[i]=cnt[i-(i&-i)]+1;
	}
	for(int i=2;i<=1000;++i){
		f[i]=f[cnt[i]]+1;
	}
	scanf("%s%d",s,&k);
	n=strlen(s);
	if(n==1&&s[0]=='1'&&k==1){
		puts("0");
		return 0;
	}
	for(int i=0;i<n;++i){
		sum[i]=(s[i]=='1');
		if(i)sum[i]+=sum[i-1];
	}
	int ans=0;
	for(int i=1;i<=1000;++i)
		if(f[i]==k-1){
			ans=(ans+calc(i))%mod;
		}
	if(!k)ans=1;
	else if(k==1)ans=(ans-1+mod)%mod;
	printf("%d\n",ans);
	return 0;
}