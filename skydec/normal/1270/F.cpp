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
const int N=210000;
char s[N];int n;
int a[N];
int b[N];
const int S=200;
LL ksm(){
	LL ans=0;
	rep(k,1,S){
		rep(i,0,n)b[i]=k*a[i]-i;
		sort(b,b+1+n);
		for(int i=0;i<=n;i++){
			int j=i;
			while(j<n&&b[j+1]==b[i])++j;
			ans+=(j-i+1)*1ll*(j-i)/2;
			i=j;
		}
	}
	return ans;
}
int c[N];int t;
LL ck(int lp,int rp,int i){
	if(lp>rp)swap(lp,rp);
	if(i<=min(lp,rp))return i+1;
	if(i>lp&&i<=rp){
		return lp+1;
	}
	else{
		return max(0,lp-(i-rp)+1);
	}
}
LL calc(int d){
	LL res=0;
	rep(i,d,t){
		//c[i-d+1]...c[i]
		int ml=c[i]-c[i-d+1]+1;
		int rp=c[i+1]-1-c[i];
		int lp=c[i-d+1]-c[i-d]-1;
		rep(i,0,lp+rp)if((i+ml)%d==0)if(i+ml>d*S){
			res+=ck(lp,rp,i);
		}
	}
	return res;
}
LL kbg(){
	LL ans=0;
	t=0;
	rep(i,1,n)if(s[i]==1)c[++t]=i;
	c[t+1]=n+1;
	rep(i,1,n/max(S,1)){
		ans+=calc(i);
	}
	return ans;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,n)s[i]=s[i]-'0';
	rep(i,1,n)a[i]=a[i-1]+s[i];
	printf("%lld\n",ksm()+kbg());
	return 0;
}