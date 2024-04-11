#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
int t,n,k;
char s[N];
int par[N];
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}
void unite(int x,int y){
	par[find(x)]=find(y);
}
vector<char> vec[N];
void cac(){
	int ans=0;
	for(int i=1;i<=n;i++){
		int c[27]={0};
		for(auto x: vec[i])c[x-'a']++;
		int mx=0;
		for(int j=0;j<26;j++)mx=max(mx,c[j]);
		ans+=((int)vec[i].size()-mx);
	}
	printf("%d\n", ans);
}
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++){
			par[i]=i;
		}
		for(int i=1;i<=n;i++){
			unite(i,n+1-i);
			if(i+k<=n) unite(i,i+k);
		}
		for(int i=1;i<=n;i++) vec[i].clear();
		for(int i=1;i<=n;i++) vec[find(i)].push_back(s[i]);
		cac();
	}
}