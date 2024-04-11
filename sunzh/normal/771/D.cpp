#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
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
int n;
char s[100];
int dp[80][80][80][2];
vector<int>Vec,Kvec,Xvec;
int vmax,kmax,xmax;
int count(vector<int>V,int begin,int lmt){
	int cnt=0;
	for(int i=begin;i<V.size()&&V[i]<lmt;++i) ++cnt;
	return cnt;
}
void cmin(int &x,int y){
	x=min(x,y);
}
int main(){
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) if(s[i]=='V') Vec.pb(i); else if(s[i]=='K') Kvec.pb(i);else Xvec.pb(i);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0][0]=0;
	vmax=Vec.size(),kmax=Kvec.size(),xmax=Xvec.size();
	for(int i=0;i<=vmax;++i){
		for(int j=0;j<=kmax;++j){
			for(int k=0;k<=xmax;++k){
				for(int t=0;t<2;++t){
					if(dp[i][j][k][t]>=0x15151515) continue ;
					if(i!=vmax){
						cmin(dp[i+1][j][k][1],dp[i][j][k][t]+count(Kvec,j,Vec[i])+count(Xvec,k,Vec[i]));
					}
					if(t==0&&j!=kmax){
						cmin(dp[i][j+1][k][0],dp[i][j][k][t]+count(Vec,i,Kvec[j])+count(Xvec,k,Kvec[j]));
					}
					if(k!=xmax){
						cmin(dp[i][j][k+1][0],dp[i][j][k][t]+count(Kvec,j,Xvec[k])+count(Vec,i,Xvec[k]));
					}
				}
			}
		}
	} 
	printf("%d\n",min(dp[vmax][kmax][xmax][0],dp[vmax][kmax][xmax][1]));
}