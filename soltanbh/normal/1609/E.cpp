#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=4e5+99;

int n,q,a[N];
string s;

struct node{
	int a=-N,b=-N,ab=-N,cnta=0,cntb=0,cntc=0;
} seg[N],lazy[N];

node merge(node u,node v){
	node ans;
	ans.cnta=u.cnta+v.cnta;
	ans.cntb=u.cntb+v.cntb;
	ans.cntc=u.cntc+v.cntc;
	
	ans.a = max(u.a+v.cnta, u.cntb+v.a);
	ans.b = max(u.b+v.cntb, u.cntc+v.b);
	ans.ab = max(u.ab+v.cnta+v.cntb, u.cntb+u.cntc+v.ab);
	maxm(ans.ab, u.a+u.cntc+v.b+v.cnta);
	
	return ans;
}
void build(int id=1,int l=0,int r=n){
	seg[id].a=seg[id].b=seg[id].ab=0;
	if(l+1==r){
		if(a[l]==0){
			seg[id].a=1;
			seg[id].cnta=1;
		}
		if(a[l]==1){
			seg[id].b=1;
			seg[id].cntb=1;
		}
		if(a[l]==2){
			seg[id].cntc=1;
		}
		//cout<<id<<" : "<<seg[id].a<<" "<<seg[id].b<<" "<<seg[id].ab<<endl;
		return ;
	}
	int mid=(l+r)/2;
	build(id*2+0,l,mid);
	build(id*2+1,mid,r);
	seg[id]=merge(seg[id*2+0],seg[id*2+1]);
	//cout<<id<<" : "<<seg[id].a<<" "<<seg[id].b<<" "<<seg[id].ab<<endl;
}
void upd(int x,int id=1, int l=0,int r=n){
   if(r<=x || x<l) return ;
   if(l==x && r==x+1){
   	seg[id].a=-N, seg[id].b=-N, seg[id].ab=-N, seg[id].cnta=0, seg[id].cntb=0, seg[id].cntc=0;
      if(a[l]==0){
			seg[id].a=1;
			seg[id].cnta=1;
		}
		if(a[l]==1){
			seg[id].b=1;
			seg[id].cntb=1;
		}
		if(a[l]==2){
			seg[id].cntc=1;
		}
		return ;
   }
   int mid=(l+r)>>1;
   upd(x,id*2+0,l,mid);
	upd(x,id*2+1,mid,r);
	seg[id]=merge(seg[id*2+0],seg[id*2+1]);
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>q>>s;
	f(i,0,n){
		a[i]=s[i]-'a';
	}
	build();	
	f(i,0,q){
		int x,val;
		char c;
		cin>>x>>c;
		val=c-'a',x--;
		a[x]=val;
		
		upd(x);
		
		int ans=n-seg[1].cnta;
		maxm(ans,seg[1].a+seg[1].cntc);
		maxm(ans,seg[1].ab);
		//cout<<seg[1].a<<" "<<seg[1].ab<<" ";
		cout<<n-ans<<endl;
	}
}
/*
3 10
abc

1 b
2 c
*/