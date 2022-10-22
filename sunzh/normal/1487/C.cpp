#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int T;
int n;
int g[110][110];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				g[i][j]=0;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=(n-1>>1);++j){
				int v=(i+j-1)%n+1;
				g[i][v]=1;g[v][i]=-1;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				printf("%d ",g[i][j]);
			}
		}
		printf("\n");
	}
}