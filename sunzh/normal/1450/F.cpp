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
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n;
int a[100010];
int cnt[100010];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read(),cnt[i]=0;
		for(int i=1;i<=n;++i) ++cnt[a[i]];
		bool f=0;
		for(int i=1;i<=n;++i)
			if(cnt[i]>(n+1>>1)){
				printf("-1\n");f=1;break ;
			}
		if(f) continue ;
		for(int i=1;i<=n;++i) cnt[i]=0;
		int mxn=0;
		int tot=0;
		++cnt[a[1]],++cnt[a[n]];++tot;
		for(int i=2;i<=n;++i){
			if(a[i]==a[i-1]){
				++tot;++cnt[a[i]],++cnt[a[i-1]];
			}
		}
		for(int i=1;i<=n;++i) mxn=max(mxn,cnt[i]);
		int sum=2*(tot-1);
		printf("%d\n",tot-1+max(0,((mxn-2)*2)-sum>>1));
	}
}