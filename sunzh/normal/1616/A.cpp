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
int a[110];
map<int,int>Map;
int main(){
	T=read();
	while(T--){
		n=read();
		Map.clear();
		for(int i=1;i<=n;++i) a[i]=read();
		int ans=0;
		for(int i=1;i<=n;++i){
			ans+=(a[i]==0?Map[0]==0:Map[abs(a[i])]<2);++Map[abs(a[i])];
		}
		printf("%d\n",ans);
	}
}