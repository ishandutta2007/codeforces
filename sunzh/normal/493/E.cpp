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
#define int long long
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
int k[100010];
int a,b,c;
signed main(){
	a=read(),b=read(),c=read();
	auto chk=[&](int x){
        if(b==1) return true;
        if(c==1) return false;
		while(x!=1){
			if(x%b!=0) return false;
			x/=b;
		}
		return true ;
	};
	if(a==1&&b==1&&c==1){
		printf("inf\n");
	}
	else if(a!=1||(!chk(c))){
		if(b==1){
			if(c!=1) printf("0\n");else printf("1\n");return 0;
		}
		int ans=(b==c);
		int cnt=0;
		while(c){
			k[cnt]=c%b;c/=b;++cnt;
		}
		long long tmp=0;long long t=1;
		for(int i=0;i<cnt;++i){
			tmp+=k[i]*t;t=1ll*t*a;
		}
		if(tmp==b) ++ans;
		printf("%lld\n",ans);
	}
	else{
		if(b==1){
			printf("0\n");
		}
		else{
			printf("1\n");
		}
	}
}