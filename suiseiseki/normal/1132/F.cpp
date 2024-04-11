#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Maxn 500
char seg[Maxn+5];
int f[Maxn+5][Maxn+5];
char s[Maxn+5];
int dfs(int left,int right){
	if(f[left][right]!=-1){
		return f[left][right];
	}
	if(left>right){
		return 0;
	}
	int ans=(1<<30);
	ans=min(dfs(left+1,right)+1,dfs(left,right-1)+1);
	for(int i=left+1;i<right;i++){
		if(seg[i-1]==seg[i+1]){
			ans=min(ans,dfs(left,i-1)+dfs(i+1,right));
		}
		else{
			ans=min(ans,dfs(left,i-1)+dfs(i+1,right)+1);
		}
		if(seg[i]==seg[left]&&seg[i]==seg[right]){
			ans=min(ans,dfs(left+1,i-1)+dfs(i+1,right-1)+1);
			ans=min(ans,dfs(left,i)+dfs(i,right)-1);
		}
		if(seg[i]==seg[left]){
			ans=min(ans,dfs(left+1,i-1)+dfs(i+1,right)+1);
		}
		if(seg[i]==seg[right]){
			ans=min(ans,dfs(left,i-1)+dfs(i+1,right-1)+1);
		}
	}
	if(seg[left]==seg[right]){
		ans=min(ans,dfs(left+1,right-1)+1);
	}
	return f[left][right]=ans;
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int len=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<=n&&s[j]==s[i]){
			j++;
		}
		j--;
		seg[++len]=s[i];
	}
	memset(f,-1,sizeof f);
	printf("%d\n",dfs(1,len));
	return 0;
}