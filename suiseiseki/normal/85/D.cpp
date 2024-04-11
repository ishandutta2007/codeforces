#include <iostream>
#include <string.h>
#include<cstdlib>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;
ll n,x;
ll tree[800005][6],add[400005],pan[400005],shu[400005];
ll num[800005];
char a[10];
map <ll,ll> id;
inline ll read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
ll ls(ll k) {
	return k<<1;
}
ll rs(ll k) {
	return k<<1|1;
}
void push_up(ll i) {
	num[i]=num[ls(i)]+num[rs(i)];
	for(ll j=0; j<=4; j++) {
		tree[i][j]=tree[ls(i)][j]+tree[rs(i)][((j-num[ls(i)])%5+5)%5];
	}
}
inline void in(ll left,ll right,ll i,ll wei,ll wor,ll sum) {
	if(left==right) {
		tree[i][1]+=wor;
		num[i]+=sum;
		return;
	} else {
		ll mid=(left+right)/2;
		if(wei<=mid) in(left,mid,ls(i),wei,wor,sum);
		else in(mid+1,right,rs(i),wei,wor,sum);
		push_up(i);
	}
}
int main() {
	ll cnt=0;
	n=read();
	for(ll i=1; i<=n; i++) {
		cin>>a;
		if(a[0]=='a') {
			x=read();
			add[++cnt]=x;
			shu[i]=x;
			pan[i]=1;
		}
		if(a[0]=='d') {
			x=read();
			shu[i]=x;
			pan[i]=-1;
		}
	}
	sort(add+1,add+cnt+1);
	ll sum=1;
	for(ll i=1; i<=cnt; i++) {
		if(id[add[i]]==0) {
			id[add[i]]=sum;
			sum++;
		}
	}
	for(ll i=1; i<=n; i++) {
		if(pan[i]==0) printf("%I64d\n",tree[1][3]);
		else {
			in(1,n,1,id[shu[i]],pan[i]*shu[i],pan[i]);
		}
	}
	return 0;
}