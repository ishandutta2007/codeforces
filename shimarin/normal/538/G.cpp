#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}

inline void GG(){
	puts("NO");exit(0);
}

const int N = 2e5+10, M = 2e6+10;
const ll inf = 1e18;
int n,l;

int cnt1,cnt2;
struct node{
	ll t,k,b;
}v1[N],v2[N];
bool flag[2];
inline poly solve(node *a,int m){
	sort(a+1,a+m+1,[=](node a,node b){
		return a.t<b.t;
	});
	flag[0]=flag[1]=0;
	ll l=-inf,r=inf;
	auto Div1=[&](ll a,ll b){//
		if (a>=0) return a/b;
		return -(-a-1)/b-1;
	};
	auto Div2=[&](ll a,ll b){//
		if (a<=0) return a/b;
		return (a-1)/b+1;
	};
	For(i,2,m){
		ll dt=a[i].t-a[i-1].t,db=a[i].b-a[i-1].b,dk=a[i].k-a[i-1].k,L=-dt-db,R=dt-db;
		if (dk&1) flag[(R&1)^1]=1;
		else if (R&1) GG();
		if (!dk){
			if (L>R) GG();
		} else if (dk<0){
			r=min(r,Div1(-L,-dk)),l=max(l,Div2(-R,-dk));
		} else {
			r=min(r,Div1(R,dk)),l=max(l,Div2(L,dk));
		}
	}
	if (flag[l&1]) l++;
	if (flag[l&1]||l>r) GG();
	poly ans(::l+1);
	ans[0]=1;
	FOR(i,1,m){
		ll t=(a[i+1].b+a[i+1].k*l)-(a[i].b+a[i].k*l);
		if (t>0){
			int j=a[i].t+1;
			while (t>0) ans[j]=1,--t,++j;
			while (j<=a[i+1].t) ans[j]=-ans[j-1],++j;
		} else {
			int j=a[i].t+1;
			while (t<0) ans[j]=-1,++t,++j;
			while (j<=a[i+1].t) ans[j]=-ans[j-1],++j;
		}
	}
	return ans;
}
int main(){
//	freopen("sea.in","r",stdin);
//	freopen("sea.out","w",stdout);
	n=read(),l=read();
	For(i,1,n){
		ll t=read(),x=read(),y=read();
		v1[++cnt1]=(node){t%l,-t/l,x-y};
		v2[++cnt2]=(node){t%l,-t/l,x+y};
	}
	v1[++cnt1]=(node){0,0,0},v1[++cnt1]=(node){l,1,0};
	v2[++cnt2]=(node){0,0,0},v2[++cnt2]=(node){l,1,0};
	auto ansx=solve(v1,cnt1),ansy=solve(v2,cnt2);
	For(i,1,l){
		if (ansx[i]==-1&&ansy[i]==-1) putchar('L');
		if (ansx[i]==1&&ansy[i]==1) putchar('R');
		if (ansx[i]==-1&&ansy[i]==1) putchar('U');
		if (ansx[i]==1&&ansy[i]==-1) putchar('D');
	}
}
/*
3 3
1 1 0
2 1 -1
3 0 -1
30 3
10 4 0
11 4 -1
12 4 0
13 5 0
14 5 -1
15 5 0
16 6 0
17 6 -1
18 6 0
19 7 0
20 7 -1
21 7 0
22 8 0
23 8 -1
24 8 0
25 9 0
26 9 -1
27 9 0
28 10 0
29 10 -1
30 10 0
31 11 0
32 11 -1
33 11 0
34 12 0
35 12 -1
36 12 0
37 13 0
38 13 -1
39 13 0
*/