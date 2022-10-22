#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
char s[10010],t[10010];
int tmp[20010],pre[10010];
int f[10010][10010];
int main(){
	scanf("%s",s+1);scanf("%s",t+1);
	int n=strlen(s+1),m=strlen(t+1);
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=n;++i){
		int sum=0;
		for(int j=i;j>0;--j){
			sum+=(s[j]=='.'?1:-1);
			if(sum==0){
				pre[i]=j-1;break ;
			}
			if(sum<0) break ;
		}
	}
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j){
			f[i][j]=min(f[i][j],f[i-1][j]+1);
			if(j>0&&s[i]==t[j]) f[i][j]=min(f[i][j],f[i-1][j-1]);
			if(pre[i]!=-1) f[i][j]=min(f[i][j],f[pre[i]][j]);
			if(s[i]=='.') f[i][j]=min(f[i][j],f[i-1][j+1]);
		}
	}
	printf("%d\n",f[n][m]);
}