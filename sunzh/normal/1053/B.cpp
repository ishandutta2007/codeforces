#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define int long long
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n;
int a[300010];
int cnt[300010];
int pr[300010];
int sc[300510][2];
signed main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),cnt[i]=__builtin_popcountll(a[i]),pr[i]=(cnt[i]&1);
	for(int i=1;i<=n;++i) pr[i]^=pr[i-1];
	for(int i=n;i>=1;--i){
		memcpy(sc[i],sc[i+1],sizeof(sc[i]));
		sc[i][pr[i]]++;
	}
	long long ans=0;
	for(int i=1;i<=n;++i){
		int mx=0,sum=0;
		for(int j=0;j<128&&i+j<=n;++j){
			mx=max(mx,cnt[i+j]);
			sum+=cnt[i+j];
			if(sum%2==0&&2*mx<=sum) ++ans;
		}
		ans+=sc[i+128][pr[i-1]];
	}
	printf("%lld\n",ans);
}