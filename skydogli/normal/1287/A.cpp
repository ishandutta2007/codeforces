#include<bits/stdc++.h>
using namespace std;
int T,n;
char ch[10005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,ch+1);
		int ans=0,now=0;
		for(int i=1;i<=n;++i){
			if(now&&ch[i]=='P')ans=max(ans,i-now);
			if(ch[i]=='A')now=i;
		}
		printf("%d\n",ans);
	}
}