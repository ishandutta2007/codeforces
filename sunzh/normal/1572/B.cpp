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
int a[200010];
int main(){
	T=read();
	while(T--){
		n=read();
		int x=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			x^=a[i];
		}
		if(x){
			printf("NO\n");
			continue ;
		}
		vector<int>ans;
		auto clear=[&](int l,int r){
			for(int i=l;i<=r-2;i+=2) ans.pb(i);
			for(int i=r-4;i>=l;i-=2) ans.pb(i);
		};
		if(n&1){
			clear(1,n);
			printf("YES\n");
			printf("%d\n",ans.size());
			for(int i:ans) printf("%d ",i);printf("\n");
			continue ;
		}
		int lst=-1;bool fl=0;
		if(!a[1]) clear(2,n);
		else if(!a[n]) clear(1,n-1);
		else{
			fl=1;
			int pr=a[1];
			for(int i=1;i<=n;i+=2){
				if(pr==0){
					fl=0;clear(1,i);clear(i+1,n);break ;
				}
				pr^=a[i+2];pr^=a[i+1];
			}
		}
		if(fl){
			printf("NO\n");
		}
		else{
			printf("YES\n");
			printf("%d\n",ans.size());
			for(int i:ans) printf("%d ",i);printf("\n");
		}
	}
}