#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,s;
int dep[100010];
int cnt[100010];
bool check(int x){
	int num=s;
	int d=0,sz=1;
	for(int i=1;i<=n;){
		if(i>1)sz*=x; ++d;
		for(int j=1;j<=sz&&i<=n;++i,++j) dep[i]=d,num-=dep[i];
	}
//	printf("x:%d,nym:%d\n",x,num);
	if(num<0) return 0;
	return 1;
}
void getans(int x){
	int num=s;
	int d=0,sz=1;
	for(int i=1;i<=n;){
		if(i>1)sz*=x; ++d;
		for(int j=1;j<=sz&&i<=n;++i,++j){
			 dep[i]=d,cnt[dep[i]]++,num-=dep[i];
		}
	}
	int j=n;
//	printf("X:%d,num:%d\n",x,num);
	while(num){
		++d;
		while(cnt[dep[j]]==1) --j;
		int t=min(num,d-dep[j]);
		num-=t;
		--cnt[dep[j]];
		dep[j]+=t;
		++cnt[dep[j]];--j;
	}
}
void chk(){
	int num=0;
	for(int i=1;i<=n;++i){
		dep[i]=dep[i-1]+1;
		num+=dep[i];
	}
	if(num<s){
		printf("No\n");exit(0);
	}
}
signed main(){
	n=read(),s=read();
	chk();
	int l=1,r=n;
	int ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	if(ans==-1){
		printf("No\n");
	}
	else{
		getans(ans);
		memset(cnt,0,sizeof(cnt));
		sort(dep+1,dep+n+1);
		int ps=1;
		printf("Yes\n");//printf("%d\n",ans);
		for(int i=2;i<=n;++i){
			while(dep[ps]!=dep[i]-1||cnt[ps]==ans) ++ps;
			printf("%lld ",ps);
			++cnt[ps];
		}
	}
	return 0;
}