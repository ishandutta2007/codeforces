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
int T;
int n;
int a[1010][1010];
bool b[1010][1010];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) a[i][j]=read();
		int ans=0;
		for(int i=1;i<n;++i){
			for(int j=1;j<=n;++j){
				int t=b[i-1][j]^b[i][j-1]^b[i][j+1];b[i+1][j]=(t^1);if(b[i+1][j]) ans^=a[i+1][j];
			}
		}
		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) b[i][j]=0;
		printf("%d\n",ans);
	}
}