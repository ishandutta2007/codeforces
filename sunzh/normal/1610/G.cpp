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
char str[300010];
int n;
int hsh[300010][21],f[300010][21];
int tr[300010];
int ps[300010],go[300010];
int lst[600010];
const int mod=998244353;
int pw[300010];
bool cmp(int x,int y){
	for(int i=18;i>=0;--i){
		if(f[x][i]==0||f[y][i]==0) continue ;
		if(hsh[x][i]==hsh[y][i]){
			x=f[x][i],y=f[y][i];
		}
	}
	// printf("x:%d,y:%d\n",x,y);
	// if(y>n) return 1;
	return str[x]<str[y];
}
int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	pw[0]=1;for(int i=1;i<=n;++i) pw[i]=(pw[i-1]<<1)%mod;
	for(int i=1;i<=n;++i) ps[i]=ps[i-1]+(str[i]=='('?1:-1);
	for(int i=n+1;i>=1;--i){
		if(str[i]=='('&&lst[ps[i-1]+n]){
			go[i]=lst[ps[i-1]+n];
		}
		lst[ps[i-1]+n]=i;
		// printf("go[%d]=%d\n",i,go[i]);
	}
	tr[n+1]=n+1;
	for(int i=n;i>=1;--i){
		f[i][0]=tr[i+1];
		hsh[i][0]=(str[i]=='('?1:0);
		for(int j=1;j<=18;++j){
			f[i][j]=f[f[i][j-1]][j-1];
			hsh[i][j]=(1ll*hsh[i][j-1]*pw[(1<<j-1)]+hsh[f[i][j-1]][j-1])%mod;
		}
		if(go[i]) tr[i]=(cmp(i,tr[go[i]])?i:tr[go[i]]);
		else tr[i]=i;
		// printf("tr[%d]=%d\n",i,tr[i]);
	}
	int p=tr[1];
	while(p<=n){
		putchar(str[p]);p=f[p][0];
	}
}