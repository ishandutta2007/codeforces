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
#include<random>
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
int b[100010];
int sum[100010];
int a[100010];
vector<int>vec[100010];
int pr[100010];
bool used[100010];
int ans[100010];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) b[i]=read(),sum[b[i]]++;
		int k=n+1;
		for(int i=n;i>=0;--i){
			sum[i]+=sum[i+1];
			if(sum[i+1]==i) k=i;
		}
		for(int i=0;i<=n+1;++i) sum[i]=used[i]=0,vector<int>().swap(vec[i]);
		for(int i=1;i<=n;++i){
			pr[i]=(b[i]==0?n+1:b[i]);vec[pr[i]].pb(i);
		}
		for(int i=1;i<=n+1;++i){
			sort(vec[i].begin(),vec[i].end(),[&](int x,int y){
				return vec[x].size()<vec[y].size();
			});
		}
		queue<int>Q;Q.push(n+1);
		int cnt=0;
		while(!Q.empty()){
			int u=Q.front();Q.pop();ans[++cnt]=u;
			for(int v:vec[u]){
				Q.push(v);
			}
		}
		printf("%d\n",k);
		for(int i=2;i<=cnt;++i) printf("%d ",ans[i]);printf("\n");
		// int lst0=0,lst1=0;
		// for(int i=1;i<=n;++i){
		// 	printf("i:%d,%d %d\n",i,lst0,lst1);
		// 	if(b[i]<=k){
		// 		if(lst0) a[lst0]=b[i],used[b[i]]=1;lst1=i;
		// 	}
		// 	else{
		// 		if(lst1) a[lst1]=b[i],used[b[i]]=1;lst0=i;
		// 	}
		// }
		// int it1=1,it2=n;
		// for(int i=1;i<=n;++i){
		// 	if(a[i]==0){
		// 		if(b[i]<=k){
		// 			while(used[it2]) --it2;
		// 			a[i]=it2;used[it2]=1;
		// 		}
		// 		else{
		// 			while(used[it1]) ++it1;
		// 			a[i]=it1;used[it1]=1;
		// 		}
		// 	}
		// }
		// printf("%d\n",k);
		// for(int i=1;i<=n;++i) printf("%d ",a[i]);printf("\n");
	}
}