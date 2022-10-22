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
#include<random>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n;
int a[100010],b[100010];
int v1[100010],cnt1;
int v2[100010],cnt2;
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();cnt1=cnt2=0;
		for(int i=1;i<=n;++i){
			b[i]=read();
			if(a[i]==0) v1[++cnt1]=b[i];else v2[++cnt2]=b[i];
		}
		sort(v1+1,v1+cnt1+1);
		sort(v2+1,v2+cnt2+1);
		int len=min(cnt1,cnt2);
		long long ans=0;
		for(int i=1;i<=cnt1;++i) ans+=v1[i];
		for(int i=cnt1-len+1;i<=cnt1;++i) ans+=v1[i];
		for(int i=1;i<=cnt2;++i) ans+=v2[i];
		for(int i=cnt2-len+1;i<=cnt2;++i) ans+=v2[i];
		if(cnt1==cnt2){
			ans-=min(v2[1],v1[1]);
		}
		printf("%lld\n",ans);
	}
}