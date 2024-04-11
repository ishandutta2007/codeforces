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
int T,n;
int a[110];
int main(){
	T=read();
	while(T--){
		n=read();for(int i=1;i<=n;++i) a[i]=read();
		sort(a+1,a+n+1);
		int cnt=0;
		for(int i=n;i>=1;--i){
			if(a[i]==a[1]) break ;++cnt;
		}
		printf("%d\n",cnt);
	}
}