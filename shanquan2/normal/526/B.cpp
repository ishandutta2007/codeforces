#include<cstdio>
#include<algorithm>
using namespace std;

int a[10000],s[10000]={0},ans=0,m,n;
void dfs(int x){
	if(x>=m/2)return;
	dfs(x*2);dfs(x*2+1);
	s[x]=max(s[x*2]+a[x*2],s[x*2+1]+a[x*2+1]);
	ans+=s[x]-s[x*2]-a[x*2]+s[x]-s[x*2+1]-a[x*2+1];
	return;
}
int main(){
	int n;scanf("%d",&n);
	m=(1<<(n+1));
	for(int i=2;i<m;i++)
		scanf("%d",&a[i]);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}