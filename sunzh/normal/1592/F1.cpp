#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m;
char str[510][510];
int a[510][510];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",str[i]+1);
		for(int j=1;j<=m;++j) if(str[i][j]=='B'){
			a[i][j]^=1;a[i-1][j]^=1;a[i-1][j-1]^=1;a[i][j-1]^=1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			// printf("%d ",a[i][j]);
			ans+=a[i][j];
		}//printf("\n");
	}bool fl=0;
	for(int i=2;i<=n;++i){
		for(int j=2;j<=m;++j){
			if(a[n][m]&&a[i-1][m]&&a[n][j-1]&&a[i-1][j-1]){
				fl=1;
			}
		}
	}
	printf("%d\n",ans-fl);
}