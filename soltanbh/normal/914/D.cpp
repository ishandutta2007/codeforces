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
const int N=1e6+9;
int n,t,l,r,mid,q,tree[N],sor,x,y,g;
int query(int l2, int r2) {
  int res=0;
  r2++;
  for (l2 += n, r2 += n; l2 < r2; l2 >>= 1, r2 >>= 1) {
    if (l2&1) res=__gcd(res,tree[l2++]);
    if (r2&1) res=__gcd(res,tree[--r2]);
  }
  return res;
}
void change(int x,int y){
	x=x+n-1;
	tree[x]=y;
	x/=2;
	while(x){
		tree[x]=__gcd(tree[x*2],tree[x*2+1]);
		x/=2;
	}
}
void build(){
	f_(i,n-1,1)
		tree[i]=__gcd(tree[i*2],tree[i*2+1]);
}
int main(){
	cin>>n;
	f(i,n,2*n) gett(tree[i]);
	build();
	cin>>q;
	f(i,0,q){
		gett(sor);
		if(sor==1){
			Gett(x,y);
			x--,y--;
			gett(g);
			if(query(x,y)%g==0) cout<<"YES"<<endl;
			else{
				l=x-1,r=y;
				while(l+1<r){
					mid=(l+r)/2;
					if(query(x,mid)%g==0)
						l=mid;
					else 
						r=mid;
				}
				if(r==y || query(r+1,y)%g==0)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}
		}
		else{
			Gett(x,y);
			change(x,y);
		}
	}
}