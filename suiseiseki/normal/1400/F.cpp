#include <cstdio>
#include <unordered_map>
using namespace std;
const int Maxn=1000;
int n,x;
char s[Maxn+5];
int a[Maxn+5];
unordered_map<int,int> f[Maxn+5];
int dmask;
bool check(int mask){
	if(((mask>>x)&1)==0){
		return 1;
	}
	if(mask&dmask){
		return 1;
	}
	return 0;
}
void calc(int& mask){
	mask&=((1<<x)-1);
	int tmp=mask&dmask;
	if(tmp==0){
		return;
	}
	tmp&=-tmp;
	mask&=(tmp-1);
}
int dfs(int u,int mask){
	if(u>n){
		return 0;
	}
	calc(mask);
	if(f[u].count(mask)>0){
		return f[u][mask];
	}
	int nmask=mask;
	int ans=dfs(u+1,mask)+1;
	mask=(mask<<a[u])|1;
	if(check(mask)){
		ans=min(ans,dfs(u+1,mask));
	}
	return f[u][nmask]=ans;
}
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'0';
	}
	scanf("%d",&x);
	for(int i=1;i<x;i++){
		if(x%i==0){
			dmask|=(1<<i);
		}
	}
	printf("%d\n",dfs(1,1));
	return 0;
}