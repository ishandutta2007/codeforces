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
int n,k;
int a[200010];
int tot[200010];
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;++i) tot[i]=0;
		for(int i=1;i<=n;++i) a[i]=read(),++tot[a[i]];
		int nw0=n,nw1=0;
		int it=0;
		PII res=mp(0,1e9);
		for(int i=1;i<=n;++i){
			while(it<n&&nw1-nw0<k){
				nw0-=tot[it+1];
				nw1+=tot[++it];
			}
			if(nw1-nw0<k) break ;
			if(it-i+1<res.se-res.fi+1){
				res=mp(i,it);
			}
			nw0+=tot[i];nw1-=tot[i];
		}
		printf("%d %d\n",res.fi,res.se);
		int cnt=0;
		for(int i=1;i<=n;++i){
			int nws=0;
			if(cnt==k-1){
				printf("%d %d\n",i,n);break ;
			}
			for(int j=i;j<=n;++j){
				nws+=((a[j]>=res.fi&&a[j]<=res.se)?1:-1);
				if(nws==1){
					printf("%d %d\n",i,j);
					++cnt;i=j;break ;
				}
			}
		}
	}
}