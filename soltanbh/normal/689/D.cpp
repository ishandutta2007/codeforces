#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
const int N=4e5+9;
int n,l,r,l1,r1,p1,p2,g1,g2,mid,a[N],b[N],a1,a2;
ll ans;
int query1(int l, int r) {
  int res=-1e9;
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) maxm(res,a[l++]);
    if (r&1) maxm(res,a[--r]);
  }
  return res;
}
int query2(int l, int r) {
  int res=1e9;
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) minm(res,b[l++]);
    if (r&1) minm(res,b[--r]);
  }
  return res;
}
void find_l1_r1(int x,int y){
	l=-1,r=x;
	while(l+1<r){
		mid=(l+r)/2;
		if(query1(mid,x-1)<=y) r=mid;
		else l=mid;
	}
	l1=r;
	y++;
	l=x,r=n;
	while(l+1<r){
		mid=(l+r)/2;
		if(query1(x,mid)<=y) l=mid;
		else r=mid;
	}
	r1=l;
}
void find_p1_p2_g1_g2(int x,int y){
	l=-1,r=x;
	while(l+1<r){
		mid=(l+r)/2;
		if(query2(mid,x)>=y) r=mid;
		else l=mid;
	}
	p1=r;
	l=x-1,r=n;
	while(l+1<r){
		mid=(l+r)/2;
		if(query2(x,mid)>=y) l=mid;
		else r=mid;
	}
	p2=l,y--;
	l=-1,r=x;
	while(l+1<r){
		mid=(l+r)/2;
		if(query2(mid,x)>=y) r=mid;
		else l=mid;
	}
	g1=r;
	l=x,r=n;
	while(l+1<r){
		mid=(l+r)/2;
		if(query2(x,mid)>=y) l=mid;
		else r=mid;
	}
	g2=l;
}
void build(){
	f_(i,n-1,0)
		a[i]=max(a[i*2],a[i*2+1]),b[i]=min(b[i*2],b[i*2+1]);
}
int main(){
	cin>>n;
	f(i,n,n*2)
		gett(a[i]);
	f(i,n,n*2)
		gett(b[i]);
	build();
	f(i,0,n){
		if(b[i+n]>=a[i+n]){
			find_l1_r1(i,a[i+n]-1);
			find_p1_p2_g1_g2(i,a[i+n]+1);
			ans+=(1ll*(i-max(g1,l1)+1)*(min(r1,g2)-i+1))-(1ll*(i-max(p1,l1)+1)*(min(r1,p2)-i+1));
		}
	}
	cout<<ans;
}