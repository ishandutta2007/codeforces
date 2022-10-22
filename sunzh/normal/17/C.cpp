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
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
const int mod=51123987;
int n;
char str[160];
int f[152][53][53][53];
int nxt[160][3];
int N;
int main(){
	n=read();
	scanf("%s",str+1);
	for(int i=1;i<=n;++i){
		if(str[i]!=str[N]) str[++N]=str[i];
	}
	f[1][0][0][0]=1;
	nxt[N+1][0]=nxt[N+1][1]=nxt[N+1][2]=N+1;
	for(int i=N;i>=1;--i){
		nxt[i][0]=nxt[i+1][0];
		nxt[i][1]=nxt[i+1][1];
		nxt[i][2]=nxt[i+1][2];
		if(str[i]=='a') nxt[i][0]=i;
		else if(str[i]=='b') nxt[i][1]=i;
		else if(str[i]=='c') nxt[i][2]=i;
	}
	int ans=0;
	for(int i=1;i<=N;++i){
		for(int j=0;j<=(n/3+1);++j){
			for(int k=0;k<=(n/3+1);++k){
				for(int l=0;l<=(n/3+1)&&l+j+k<=n;++l){
					if(f[i][j][k][l]==0) continue ;
					if(j+k+l==n&&j>=(n/3)&&k>=(n/3)&&l>=(n/3)){
						(ans+=f[i][j][k][l])%=mod;
					}
					if(nxt[i][0]<=N) (f[nxt[i][0]][j+1][k][l]+=f[i][j][k][l])%=mod;
					if(nxt[i][1]<=N) (f[nxt[i][1]][j][k+1][l]+=f[i][j][k][l])%=mod;
					if(nxt[i][2]<=N) (f[nxt[i][2]][j][k][l+1]+=f[i][j][k][l])%=mod;
				}
			}
		}
	}
	printf("%d\n",ans);
}