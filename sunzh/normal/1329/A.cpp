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
int n,m;
int l[100010];
int ans[100010];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i) l[i]=read();
	long long sum=0;
	for(int i=1;i<=m;++i) sum+=l[i];
	for(int i=1;i<=m;++i) if(n-l[i]+1<i) sum=0;
	if(sum<n){
		printf("-1\n");return 0;
	}
	long long ls=0;
	for(long long i=m;i>=1;--i){
		ls+=l[i];
		ans[i]=max(i,n-ls+1);
	}
	for(int i=1;i<=m;++i) printf("%d ",ans[i]);
}