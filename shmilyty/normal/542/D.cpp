#include<bits/stdc++.h>
#define ll long long
#define ljc 998244353
using namespace std;
#ifdef Fading
#define gc getchar
#endif
#ifndef Fading
inline char gc(){
	static char now[1<<16],*S,*T;
	if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
	return *S++;
}
#endif
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
ll n,p[100101],P,PMAX,tot,vis[1010101];
unordered_map<ll,bool> has;
map<pair<ll,ll>,ll> mF;
inline bool check(ll num){
    if (num<=1000003) return !vis[num];
    if (has.count(num)) return 1;
	for (int i=1;i<=tot&&1LL*p[i]*p[i]<=num;i++){
		if (num%p[i]==0) return 0;
	}
	has[num]=1;
	return 1;
}
inline ll F(ll num,int las){
	if (num==1) return 1;
	if (p[las]+1>num) return 0;
	if (p[las]+1==num) return 1;
	if (1LL*p[las]*p[las]+1LL>num) return check(num-1);
	if (mF.count(make_pair(num,las))) return mF[make_pair(num,las)];
	ll now=p[las],sum=F(num,las+1);
	for (;now+1<=num;now=1LL*now*p[las]){
		if (num%(now+1)==0){
			sum+=F(num/(now+1),las+1);
		}
	}
	return (mF[make_pair(num,las)]=sum);
}
inline void init(int N){
	for (int i=2;i<=N;i++){
		if (!vis[i]) p[++tot]=i;
		for (int j=1;j<=tot&&i*p[j]<N;j++){
			vis[i*p[j]]=1;
			if (i%p[j]==0) break;	
		}
	}
}
signed main(){
	init(1e6+3);
	n=read();
	printf("%lld\n",F(n,1));
	return 0;
}