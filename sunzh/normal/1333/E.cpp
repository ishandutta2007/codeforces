#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int ans[510][510];
int main(){
	n=read();
	if(n<=2) printf("-1\n");
	else{
		int cnt=0;
		for(int i=n;i>3;--i){
			if(i&1){
				for(int j=1;j<=i;++j) ans[i][j]=++cnt;
				for(int j=i-1;j>=1;--j) ans[j][i]=++cnt;
			}
			else{
				for(int j=1;j<=i;++j) ans[j][i]=++cnt;
				for(int j=i-1;j>=1;--j) ans[i][j]=++cnt;
			}
		}
		ans[3][1]=++cnt;ans[2][2]=++cnt;
		ans[3][2]=++cnt;ans[3][3]=++cnt;
		ans[1][2]=++cnt;ans[1][3]=++cnt;
		ans[2][1]=++cnt;ans[2][3]=++cnt;
		ans[1][1]=++cnt;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j) printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
}