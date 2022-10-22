#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define int __int128
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
int T;
int a,b,c,d,ans;
int solve(int x){
	int res=x*a;
//	printf("1:%lld\n",res);
	if(x*d>=c) res-=(x*d-c)/d*c*b;
//	printf("2:%lld\n",res);
	int k=(c-1)/d;
	if(x*d>=c)res-=(d+k*d)*k/2*b;
	else {
		res-=(d+(x-1)*d)*(x-1)/2*b;
	}
	ans=max(ans,res);
//	printf("x:%lld,res:%lld\n",x,res); 
	return res;
}
signed main(){
	T=read();
	while(T--){
		a=read(),b=read(),c=read(),d=read();
//		printf("%d\n",solve(1));
		if(a>b*c) printf("-1\n");
		else{
			ans=0;
			int l=1,r=1e9;
			while(r-l>=10){
				int d=(r-l)/3;
				int mid1=l+d,mid2=r-d;
				int res1=solve(mid1),res2=solve(mid2);
				if(res1>res2) r=mid2-1;
				else l=mid1+1;
			}
			while(l<=r) solve(l++);
			print(ans);
			putchar('\n');
		}
	}
}