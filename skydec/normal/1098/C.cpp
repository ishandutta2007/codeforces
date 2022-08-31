#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=110000;
int n;LL s;
LL calc(int k){
	LL now=n;
	LL pre=1;
	LL ans=0;
	for(LL dep=1;now;++dep){
		pre=min(pre,now);
		ans+=dep*1ll*pre;
		now-=pre;
		pre=pre*k;
	}
	return ans;
}
LL a[N];
int fa[N];
void gao(int k){
	a[1]=1;
	LL rest=n-1;
	for(int i=2;rest;++i){
		a[i]=min(rest,a[i-1]*k);
		rest-=a[i];
	}
	int t=0;
	rep(i,0,n)if(a[i])t=i;

	rep(i,1,t)s-=i*1ll*a[i];

	int lst=t+1;
	for(int i=t;i>=1&&s;i--){
		while(a[i]>1){
			--a[i];
			s+=i;
			if(s>lst){
				s-=lst;
				a[lst]++;
				lst++;
			}
			else{
				a[(int)s]++;
				goto gtw;
			}
		}
	}
	gtw:;

	int pre=1;
	int now=1;
	rep(i,2,lst){
		int rp=k;
		int tt=now+1;
		rep(j,1,a[i]){
			++now;
			if(!rp){
				rp=k;
				++pre;
			}
			rp--;
			fa[now]=pre;
		}
		pre=tt;
	}
	puts("Yes");
	rep(i,2,n)printf("%d ",fa[i]);puts("");
}
int main(){
	scanf("%d%lld",&n,&s);
	if(n*1ll*(n+1)/2==s){
		puts("Yes");
		rep(i,2,n)printf("%d ",i-1);puts("");
		return 0;
	}
	if(s>n*1ll*(n+1)/2){
		puts("No");
		return 0;
	}
	if(s<2*n-1){
		puts("No");
		return 0;
	}
	rep(k,2,n-1){
		if(calc(k)<=s){
			gao(k);
			return 0;
		}
	}
	return 0;
}