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
int a[200010],b[200010];
bool check(int x){
	int t=0;
	for(int i=1;i<=n;++i){
		if(b[i]>=t&&t+1+a[i]>=x){
			++t;
		}
	}
	return t>=x;
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read(),b[i]=read();
		int l=1,r=n,res=1;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid)) res=mid,l=mid+1;else r=mid-1;
		}
		printf("%d\n",res);
	}
}