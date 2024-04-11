#include<bits/stdc++.h>
using namespace std;
int T,n,ans,lst[222222];
char s[222222];
int main() {
	scanf("%d",&T);
	while(T--) {
		cin>>s+1,n=strlen(s+1),ans=0;
		for(int i=1,pos=0; i<=n; i++)if(s[i]=='1')lst[i]=pos,pos=i;
		for(int i=1; i<=n; i++)if(s[i]=='1') {
				int t=i-lst[i];
				for(int j=i,k=0; j<=n; j++) {
					k=k*2+(s[j]-'0');
					if(k>t+j-i)break;
					ans++;
				}
			}
		printf("%d\n",ans);
	}
}