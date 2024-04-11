#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define Mod 1000000007
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
inline int ksm(int a,int x){
	LL ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		x>>=1;
		w=w*w%Mod;
	}
	return ans;
}
#define MN 100005
int n,f[MN],ans;
vector<int>D[MN],F[MN];
void init(){
	for(register int i=1;i<=n;++i){
		for(int j=i;j<=n;j+=i)
			D[j].push_back(i);
		reverse(D[i].begin(),D[i].end());
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<D[i].size();++j){
			F[i].push_back(n/D[i][j]);
			for(int k=0;k<j;++k)
				if(D[i][k]%D[i][j]==0)F[i][j]-=F[i][k];
		}
	}
}
int main(){
	scanf("%d",&n);
	init();
	int invn=ksm(n,Mod-2);
	f[1]=0;ans=1;
	for(register int i=2;i<=n;++i){
		int res=0;
		f[i]=1;
		for(int j=1;j<D[i].size();++j){
			f[i]+=((LL)F[i][j]*f[D[i][j]]%Mod*invn)%Mod;
			f[i]%=Mod;
		}
		f[i]=(LL)f[i]*ksm((1ll-(LL)F[i][0]*invn%Mod+Mod)%Mod,Mod-2)%Mod;
		ans=(ans+(LL)f[i]*invn)%Mod;
	}
	printf("%d",ans%Mod);
	return 0;
}