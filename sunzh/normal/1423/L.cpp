#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<vector>
#include<chrono>
#include<random>
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
auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rnd(SEED);
int n,s,d;
uint64_t hsh[1010];
uint64_t val[31];
unordered_map<uint64_t,int>Map;
int main(){
	n=read(),s=read(),d=read();
	hsh[1]=1;
	for(int i=2;i<=n;++i) hsh[i]=3*hsh[i-1];
	for(int i=1;i<=s;++i){
		int c=read();
		for(int j=1;j<=c;++j){
			int x=read();val[i]^=hsh[x];
		}
//		printf("val:%llu\n",val[i]);
	}
	for(int i=1;i<(1<<15);++i){
		uint64_t hs=0;
		int cnt=0;
		for(int j=1;j<=15;++j){
			if((1<<j-1)&i){
				hs^=val[j];++cnt;
			}
		}
		if(Map.count(hs)) Map[hs]=min(Map[hs],cnt);
		else Map[hs]=cnt;
	}
	Map[0]=0;
	for(int i=1;i<=d;++i){
		int t=read();
		uint64_t hs=0;
		for(int j=1;j<=t;++j){
			int x=read();hs^=hsh[x];
		}
		int ans=0x3f3f7f7f;
		if(Map.count(hs)) ans=Map[hs];
		for(int j=1;s>15&&j<(1<<(s-15));++j){
			uint64_t h=0;
			int cnt=0;
			for(int k=1;k<=s-15;++k){
				if((1<<(k-1))&j){
					h^=val[k+15];
					++cnt;
				} 
			}
			if(Map.count(hs^h)) ans=min(ans,cnt+Map[hs^h]);
		}
		printf("%d\n",ans>=0x3f3f3f3f?-1:ans);
	}
	return 0;
}