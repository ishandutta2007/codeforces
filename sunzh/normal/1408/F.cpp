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
int n;
vector<PII>ans;
int cnt;
int main(){
	n=read();
	int lim=1;
	while(lim<n) lim<<=1;
	lim>>=1;
	for(int i=1;i<lim;i<<=1){
		for(int j=0;j<lim;j+=i<<1){
			for(int k=0;k<i;++k){
				ans.ep(j+k+1,j+k+i+1);++cnt;
			}
		}
	}
	for(int i=1;i<lim;i<<=1){
		for(int j=0;j<lim;j+=i<<1){
			for(int k=0;k<i;++k){
				ans.ep(n-j-k-i,n-j-k);++cnt;
			}
		}
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;++i) printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}