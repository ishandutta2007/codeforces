#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define read(x) scanf("%lld",&x)
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
const int N = 555555;
ll n,a[N]; ll lst=0;
int ch[6333333][2],size,val[6333333];
void ins(ll x, int t) {
	int now=0;
	per(i,60,0) {
		int c=(x>>i)&1;
		if (!ch[now][c]) ch[now][c]=++size;
		now=ch[now][c]; val[now]+=t;
	}
}

ll solve() {
	int now=0,rec=-1; ll ans=0,pos=0;
	per(i,60,0) {
		if (!((lst>>i)&1)&&val[ch[now][1]]) {rec=ch[now][1]; ans=1LL<<i; pos=i;}
		now=ch[now][0]; if (!now||!val[now]) break;
	}
	if (rec==-1) {puts("No"); exit(0);}
	per(i,pos-1,0)
		if (ch[rec][0]&&val[ch[rec][0]]) rec=ch[rec][0];
		else rec=ch[rec][1],ans+=1LL<<i;
	ins(ans,-1); lst^=ans; return ans;
}
int main() {
	read(n); rep(i,1,n) read(a[i]);
	rep(i,1,n) ins(a[i],1); 
	rep(i,1,n) {
		a[i]=solve();
	}
	puts("Yes");
	rep(i,1,n) printf("%lld ",a[i]);
	return 0;
}