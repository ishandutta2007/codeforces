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
int T;
int n,m;
bool used[300010];
struct node{
	int u,v;
}e[500010];
vector<int>ans;
int main(){
	T=read();
	while(T--){
		ans.clear();
		n=read(),m=read();
		for(int i=1;i<=3*n;++i) used[i]=0;
		for(int i=1;i<=m;++i) e[i].u=read(),e[i].v=read();
		int cnt=0; 
		for(int i=1;i<=m;++i){
			if(!used[e[i].u]&&!used[e[i].v]){
				++cnt;used[e[i].u]=1,used[e[i].v]=1;
				ans.pb(i);
			}
		}
		if(cnt>=n){
			printf("Matching\n");
			for(int i=0;i<n;++i) printf("%d ",ans[i]);
		}
		else{
			printf("IndSet\n"); 
			ans.clear();
			for(int i=1;i<=3*n;++i) if(!used[i]) ans.pb(i);
			for(int i=0;i<n;++i) printf("%d ",ans[i]);printf("\n");
		}
	}
}