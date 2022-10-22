#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define PII pair<int,int>
#define mp make_pair
#define fi first
#define se second 
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n,m;
int a[251][251];
int ans[251][251];
queue<PII>q;
bool c[100010],r[100010]; 
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) a[i][j]=read();
	for(int i=1;i<=n;++i){
		int x=-1;
		for(int j=1;j<=m;++j){
			x=max(x,a[i][j]);
		}
		c[x]=1;
	}
	for(int i=1;i<=m;++i){
		int x=-1;for(int j=1;j<=n;++j) x=max(x,a[j][i]);
		r[x]=1;
	}
	int x=0,y=0;
	for(int i=n*m;i;--i){
		x+=c[i],y+=r[i];
		if(r[i]||c[i]){
			ans[x][y]=i;
			if(r[i]){
				for(int j=x-1;j;--j) q.push(mp(j,y));
			}
			if(c[i]){
				for(int j=y-1;j;--j) q.push(mp(x,j));
			}
		}
		else{
			PII res=q.front();q.pop();ans[res.fi][res.se]=i;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}