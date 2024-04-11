#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
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
int T,n,m;
int c[1010],d[1010];
char str[1010];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		scanf("%s",str+1);
		for(int i=1;i<=n;++i) c[i]=str[i]-'0';c[n+1]=0;
		for(int i=1;i<=min(n,m);++i){
			for(int j=1;j<=n;++j){
				if(c[j-1]+c[j+1]==1){
					d[j]=1;
				}
			}
			for(int j=1;j<=n;++j) c[j]|=d[j],d[j]=0;
		}
		for(int i=1;i<=n;++i) str[i]=c[i]+'0';
		printf("%s\n",str+1);
	}
}