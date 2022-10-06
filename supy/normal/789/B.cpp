#include<cstdio>
#include<cstring>
#include<set>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

int ans,b1,q,l,m;
int a[100005];
inline ll abs(ll x){return x>0?x:-x;}
set<int> Set;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(b1); read(q); read(l); read(m);
	if (abs(b1)>l) {puts("0"); return 0;}
	rep(i,1,m) read(a[i]);
	rep(i,1,m) Set.insert(a[i]);
	if (abs(q)==1) {
		bool Find=Set.count(b1);
		if (q==-1) Find&=Set.count(-b1);
		if (Find) puts("0");
		else puts("inf");
		return 0;
	}
	if (b1==0) {
		if (!Set.count(0)) puts("inf");
		else printf("0");
		return 0;
	}
	if (q==0) {
		if (!Set.count(0)) puts("inf");
		else printf("%d",Set.count(b1)^1); //!
		return 0;
	}
	ll b=b1;
	while ((b>0?b:-b)<=l) { //abs??????????
		if (!Set.count(b)) ans++;
		b*=q;
	}
	printf("%d",ans);
	return 0;
}