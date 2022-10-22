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
#define pow powl
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
long long ans;
long long f[100010][13];
char str[100010];
int nxt(int x,int y){
	return (9+x%11*(x-1)%11*6%11+y+1)%11;
}
int main(){
	scanf("%s",str+1);
	int n=strlen(str+1);
	for(int i=1;i<=n;++i){
		for(int j=str[i]-'0'+1;j<=10;++j) f[i][nxt(j,str[i]-'0')]+=f[i-1][j];
		if(str[i]!='0') f[i][str[i]-'0']++;
		for(int j=0;j<=10;++j) ans+=f[i][j];
//		for(int j=0;j<=10;++j) printf("f[%d][%d]=%d\n",i,j,f[i][j]);
	}
	printf("%lld\n",ans);
}