#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=5e5+9;

int n,t,ans[N];
ll a[N],tree[N*2];

ll query(int l, int r) {
	ll res=0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
   	if (l&1) res+=tree[l++];
   	if (r&1) res+=tree[--r];
	}
 	return res;
}
void add(int x){
	int p=x;
	x--,x+=n;
	while(x)
		tree[x]+=p,x/=2;
}
ll calc(ll x){
	return x*(x+1ll)/2-query(0,x);
}
void solve(int x){
	int l=0,r=n,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(calc(mid)<=a[x]) l=mid;
		else r=mid;
	}
	ans[x]=r;
	add(r);
}

int main(){
	cin>>n;
	f(i,1,n+1){ cin>>a[i];}
	f_(i,n,1)
		solve(i);
	f(i,1,n+1) cout<<ans[i]<<" ";
}