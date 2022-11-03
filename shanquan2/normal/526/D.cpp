#include<cstdio>
#include<vector>
using namespace std;

char s[1001000];
int f[1001000],fa[1001000],dep[1001000],up[1001000][21];
vector<int> v[1001000];
bool ans[1001000]={0};
int main(){
	int n,k;scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	f[0]=f[1]=0;
	for(int i=2;i<=n;i++){
		int h=f[i-1];
		while(h && s[h+1]!=s[i])h=f[h];
		if(s[h+1]!=s[i])f[i]=0;else f[i]=h+1;
	}
	fa[0]=0;
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			fa[i]=0;dep[i]=1;
			v[0].push_back(i);
			continue;
		}
		fa[i]=f[i];dep[i]=dep[f[i]]+1;
	}
	for(int i=1;i<=n;i++){
		up[i][0]=fa[i];
		for(int j=1;j<=20;j++)
			up[i][j]=up[up[i][j-1]][j-1];
	}
	for(int i=1;i<=n;i++){
		int now=i;
		for(int j=20;j>=0;j--){
			int x=up[now][j],d=i-x;
			if((long long)d*(long long)(k+1)<(long long)i)now=x;
		}now=fa[now];
		if((long long)(i-now)*(long long)k<=(long long)i)ans[i]=1;
	}
	for(int i=1;i<=n;i++)printf("%d",ans[i]);printf("\n");
	return 0;
}