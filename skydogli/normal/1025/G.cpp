#include<bits/stdc++.h>
using namespace std;
#define Mod 1000000007
#define MN 505
int supd(int a){return a>=0?a:a+Mod;}
int n,pw[MN],siz[MN];
int main(){
	scanf("%d",&n);
	pw[0]=1;for(int i=1;i<=n;++i)pw[i]=pw[i-1]*2%Mod;
	for(int i=1;i<=n;++i){
		int fa;
		scanf("%d",&fa);
		if(fa!=-1)siz[fa]++;
	}
	int ans=pw[n-1]-1;
	for(int i=1;i<=n;++i){
		ans=supd(ans-pw[siz[i]]+1);
	}
	printf("%d\n",ans);
	return 0;
}
//??