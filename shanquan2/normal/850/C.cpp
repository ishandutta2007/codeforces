#include<bits/stdc++.h>
using namespace std;

map<int,int> ma,f;
int a[1000005],n,cnt;
int dfs(int x){
	if(f.find(x)!=f.end())return f[x];
	int b[40],l=0,k;
	for(;(1ll<<k)<=x;k++);
	for(int i=1;i<k;i++){
		int y=0;
		for(int j=0;j<k;j++)if(x>>j&1)if(j>=i)y|=1<<j-i;else y|=1<<j;
		b[l++]=dfs(y);
	}
	sort(b,b+l);l=unique(b,b+l)-b;
	for(int i=0;i<l;i++)if(b[i]!=i)return f[x]=i;
	return f[x]=l;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		for(int j=2;1ll*j*j<=x;j++)if(x%j==0){
			if(ma.find(j)==ma.end())ma[j]=cnt++;
			int k=0,l=ma[j];for(;x%j==0;x/=j)k++;
			a[l]|=1<<k;
		}
		if(x>1){
			if(ma.find(x)==ma.end())ma[x]=cnt++;
			a[ma[x]]|=2;
		}
	}
	int t=0;
	for(int i=0;i<cnt;i++)t^=dfs(a[i]);
	if(t)printf("Mojtaba\n");else printf("Arpa\n");
	return 0;
}