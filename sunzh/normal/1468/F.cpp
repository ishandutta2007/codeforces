#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<map>
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
map<PII,int>Map;
int main(){
	T=read();
	while(T--){
		Map.clear();
		n=read();
		for(int i=1;i<=n;++i){
			int x=read(),y=read();
			int u=read(),v=read();
			int dx=u-x,dy=v-y;
//			printf("dx:%d,dy:%d\n",dx,dy);
			PII res;
			if(!dx){
				if(dy>0){
					res.fi=0,res.se=1;
				} 
				else res.fi=0,res.se=-1;
			}
			else if(!dy){
				if(dx>0){
					res.fi=1,res.se=0;
				}
				else res.fi=-1,res.se=0;
			}
			else{
				int a=abs(dx),b=abs(dy);
				int c=__gcd(a,b);
				if(dx<0) res.fi=-1;else res.fi=1;
				if(dy<0) res.se=-1;else res.se=1;
				res.fi*=(a/c);
				res.se*=(b/c);
			}
//			printf("res:%d %d\n",res.fi,res.se);
			Map[res]++; 
		}
		long long ans=0;
		for(auto i:Map){
			PII x=i.fi;int y=i.se;
			if(x.fi>0||(x.fi==0&&x.se>0)){
				ans+=1ll*y*Map[mp(-x.fi,-x.se)];
			}
		}
		printf("%lld\n",ans);
	}
}