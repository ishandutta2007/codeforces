#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<random>
#include<queue>
#include<set>
#include<chrono>
#include<random>
#include<unordered_map>
#define ull unsigned long long
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
auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rnd(SEED);
int n;
long long ans;
int a[500010];
int Q[500010][4];
ull cnt[500010],val[500010];
ull su[500010];
unordered_map<ull,long long>mp;
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) val[i]=rnd()>>1;
	int pos=0;
	ull sum=0;
	su[0]=0;mp[0]=1;
	for(int i=1;i<=n;++i){
		if(Q[a[i]][3]){
			while(pos<Q[a[i]][1]) mp[su[pos++]]--;
			Q[a[i]][1]=Q[a[i]][2],Q[a[i]][2]=Q[a[i]][3],Q[a[i]][3]=i;
		}
		else{
			if(Q[a[i]][2]) Q[a[i]][3]=i;
			else if(Q[a[i]][1]) Q[a[i]][2]=i;
			else Q[a[i]][1]=i;
		}
		sum-=(cnt[a[i]]%3)*val[a[i]];
		++cnt[a[i]];
		sum+=(cnt[a[i]]%3)*val[a[i]];
		if(mp.count(sum)) ans+=mp[sum];
		++mp[sum];
		su[i]=sum;
//		printf("su[%d]:%llu,ans:%d\n",i,su[i],ans);
	}
//	printf("%lld %lld\n",su[1],su[4]);
	printf("%lld\n",ans);
	return 0;
}