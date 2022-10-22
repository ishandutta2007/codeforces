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
int a[2050];int pos[2050];
vector<int>ans;
void doit(int x){
	for(int i=1;i+i<x;++i){
		swap(a[i],a[x-i+1]);
		swap(pos[a[i]],pos[a[x-i+1]]);
	}
	ans.pb(x);
}
int main(){
	T=read();
	while(T--){
		ans.clear();
		n=read();
		for(int i=1;i<=n;++i) a[i]=read(),pos[a[i]]=i;
		bool f=1;
		for(int i=n;i>1;i-=2){
			if(!(pos[i]&1)){
				f=0;break ;
			}
			if(pos[i-1]&1){
				f=0;break ;
			}
			if(pos[i-1]<pos[i]) doit(pos[i]);
			if(pos[i]!=1) doit(pos[i]);
			doit(pos[i-1]-1);
			doit(pos[i-1]+1);
			doit(pos[i]);doit(i);
		}
		if(f){
			printf("%d\n",ans.size());
			for(int i:ans) printf("%d ",i);printf("\n");
		}
		else printf("-1\n");
	}
}