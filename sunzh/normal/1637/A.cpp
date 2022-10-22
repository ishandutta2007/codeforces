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
int a[100010];
int mx[100010],mn[100010];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i) mx[i]=max(mx[i-1],a[i]);
		mn[n+1]=1e9+10;
		for(int i=n;i>=1;--i) mn[i]=min(mn[i+1],a[i]);
		bool f=0;
		for(int i=1;i<n;++i){
			if(mx[i]>mn[i+1]) f=1;
		}
		printf(f?"YES\n":"NO\n");
	}
}