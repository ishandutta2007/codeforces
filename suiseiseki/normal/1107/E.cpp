#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define Maxn 100
#define ll long long
int n;
ll a[Maxn+5];
char s[Maxn+5];
ll f[Maxn+5][Maxn+5][Maxn+5];
int cnt[Maxn+5];
ll mx(ll a,ll b){
	return a>b?a:b;
}
int len;
ll dfs(int left,int right,int num){
	if(f[left][right][num]!=-1){
		return f[left][right][num];
	}
	if(left==right){
		return f[left][right][num]=a[cnt[right]+num];
	}
	f[left][right][num]=a[cnt[right]+num]+dfs(left,right-1,0);
	for(int i=right-2;i>=left;i-=2){
		f[left][right][num]=mx(f[left][right][num],dfs(left,i,cnt[right]+num)+dfs(i+1,right-1,0));
	}
	return f[left][right][num];
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[i]=x;
	}
	memset(f,-1,sizeof f);
	for(int i=2;i<=n;i++){
		for(int j=1;(j<<1)<=i;j++){
			a[i]=mx(a[i],a[j]+a[i-j]);
		}
	}
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(s[j]==s[i]){
			j++;
		}
		j--;
		cnt[++len]=j-i+1;
	}
	cout<<dfs(1,len,0)<<endl;
	return 0;
}