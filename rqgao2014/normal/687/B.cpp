#include<bits/stdc++.h>
using namespace std;

int n,k,m,a[20],s[20],vis[20];

int main(){
	scanf("%d%d",&n,&k);
	for(int i=2;i*i<=k;i++)
		if(k%i==0){
			a[++m]=i,s[m]=0;
			while(k%i==0) k/=i,s[m]++;
		}
	if(k>1) a[++m]=k,s[m]=1;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		for(int j=1;j<=m;j++){
			if(vis[j]) continue;
			int cnt=0;
			while(x%a[j]==0) x/=a[j],cnt++;
			if(cnt>=s[j]) vis[j]=1;
		}
	}
	bool isok=1;
	for(int i=1;i<=m;i++)
		if(!vis[i]){isok=0;break;}
	if(isok) puts("Yes"); else puts("No");
}
/*
3 12
2 3 5 
*/