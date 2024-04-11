#include<iostream>
#include<cstdio>
using namespace std;
const int o=3e5,MOD=998244353;
int n,f[o];char s[o];string p[o];
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1<<(n-1);i<(1<<n);f[i++]=1) p[i]+=s[i];
	for(int i=(1<<(n-1))-1;i;--i){
		p[i]+=s[i];
		if(p[i*2]<p[i*2+1]) p[i]+=p[i*2],p[i]+=p[i*2+1];
		else p[i]+=p[i*2+1],p[i]+=p[i*2];
		if(p[i*2]==p[i*2+1]) f[i]=(f[i]+f[i*2]*1ll*f[i*2+1])%MOD;
		else f[i]=(f[i]+f[i*2]*2ll*f[i*2+1])%MOD;
	}
	printf("%d",f[1]);
	return 0;
}