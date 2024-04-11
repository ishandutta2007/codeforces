#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
//#define rf random_shuffle
#define np next_permutation
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;

inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}

const int N=1000000,mod=1e9+7;
int ans,k,phi[N+5],fac[N+5],rf[N+5],cnt[N+5];
vi d[N+5];

inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}
	return ans;
}
inline int C(int x,int y){
	if(x<y) return 0;
	return (ll)fac[x]*rf[y]%mod*rf[x-y]%mod;
}
inline void add(int x){
	for(int i=0;i<d[x].size();i++){
		int y=d[x][i];
		cnt[y]++;
		ans=(ans+(ll)(C(cnt[y],k)-C(cnt[y]-1,k)+mod)%mod*phi[y])%mod;
	}
}

int main(){
	fac[0]=1;rf[0]=1;
	for(int i=1;i<=N;i++){
		fac[i]=(ll)fac[i-1]*i%mod; 
		rf[i]=exp(fac[i],mod-2);
	}
	for(int i=1;i<=N;i++){
		phi[i]+=i;d[i].pb(i);
		for(int j=i<<1;j<=N;j+=i)
			d[j].pb(i),phi[j]-=phi[i];
	}
//	for(int i=1;i<=10;i++) printf("%d\n",phi[i]);
	int n,q;
	read(n);read(k);read(q);
	for(;n--;){
		int x;read(x);
		add(x);
	}
	for(;q--;){
		int x;read(x);
		add(x);printf("%d\n",ans);
	}
	return 0;
}