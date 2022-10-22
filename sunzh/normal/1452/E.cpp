#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define pow powl
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
int n,m,k;
int ans;
PII seg[4010];
int det[4010];
int main(){
	n=read(),m=read(),k=read();n+=k;
	for(int i=1;i<=m;++i) seg[i].fi=read()+k,seg[i].se=read()+k;
	for(int l=1;l+k-1<=n;++l){
		int r=l+k-1;
		int res=0;
		memset(det,0,sizeof(det));
		for(int i=1;i<=m;++i){
			int x=max(min(seg[i].se,r)-max(seg[i].fi,l)+1,0);
			int L=seg[i].fi,R=seg[i].se;
//			printf("l:%d,i:%d,x:%d\n",l,i,x);
			res+=x;
			det[L-k+1+x]++;
			--det[L+1];
			--det[R-k+2];
			++det[R-x+2];
		}
//		printf("l:%d,res:%d\n",l,res);
		int sum=0;int t=res;
		for(int i=1;i+k-1<=n;++i){
			sum+=det[i];
			res+=sum;
			if(i>k)ans=max(ans,res);
		}
	}
	printf("%d\n",ans);
}