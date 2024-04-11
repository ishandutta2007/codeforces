#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int inf=1000000005;
const int N=110000;
int P;
struct w{
	int a,b;
	inline w(int _a=0,int _b=0){
		a=_a;b=_b;
	}
};
inline w mul(w x,w y,int P){
	w c;
	c.a=x.a*1ll*y.a%P;
	if(x.b*1ll*y.b>inf)c.b=inf;
	else c.b=x.b*y.b;
	return c;
}
inline w Pow(w a,int b,int P){
	w c=w(1,1);
	for(;b;b>>=1,a=mul(a,a,P))if(b&1)c=mul(c,a,P);
	return c;
}
int n,Q;
int a[N];
int pp[N];
int t;
int phi(int x){
	int s=x;
	for(int i=2;i*i<=x;i++)if(x%i==0){
		while(x%i==0){
			x/=i;
		}
		s/=i;
		s*=(i-1);
	}
	if(x>1){
		s/=x;
		s*=(x-1);
	}
	return s;
}
w ask(int l,int r,int i){
	if(l==r)return w(a[l]%pp[i],a[l]);
	if(pp[i]==1)return w(0,a[l]);
	if(a[l]==1)return w(1%pp[i],1);

	w ans=ask(l+1,r,i+1);
	
	if(ans.b>=pp[i]){
		return Pow(w(a[l]%pp[i],a[l]),ans.a+pp[i+1],pp[i]);			
	}
	else{
		return Pow(w(a[l]%pp[i],a[l]),ans.b,pp[i]);
	}
}
int main(){
	scanf("%d%d",&n,&P);
	rep(i,1,n)scanf("%d",&a[i]);
	int Q;scanf("%d",&Q);
	pp[t=1]=P;
	while(pp[t]!=1){
		pp[t+1]=phi(pp[t]);
		++t;
	}
	while(Q--){
		int l,r;scanf("%d%d",&l,&r);
		printf("%d\n",ask(l,r,1).a);
	}
	return 0;
}