#include<bits/stdc++.h>
#define rd(x) scanf("%d",&x)
#define ls k<<1
#define rs k<<1|1
#define ll long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;

const int N=200005,M=N*4;
int n,q,a[N],t,l,r,k;
struct __{
	ll p[M],s[M];
	void B(int l,int r,int k,bool t){
		if(l==r){if(((l&1)&&!t)||(!(l&1)&&t)) p[k]=min(0,a[l]-a[l-1]),s[k]=a[l]-a[l-1];return;}
		int mid=l+r>>1;
		B(l,mid,ls,t);B(mid+1,r,rs,t);
		p[k]=min(p[ls],s[ls]+p[rs]);s[k]=s[ls]+s[rs];
	}
	void C(int l,int r,int x,int y,int k){
		if(l==r){s[k]+=y;p[k]=min(0ll,s[k]);return;}
		int mid=l+r>>1;
		if(x<=mid) C(l,mid,x,y,ls); else C(mid+1,r,x,y,rs);
		p[k]=min(p[ls],s[ls]+p[rs]);s[k]=s[ls]+s[rs];
	}
	pii G(int l,int r,int x,int y,int k){
		if(l==x&&y==r) return mp(p[k],s[k]);
		int mid=l+r>>1;pii L,R;
		if(y<=mid) return G(l,mid,x,y,ls);
		if(x>mid) return G(mid+1,r,x,y,rs);
		L=G(l,mid,x,mid,ls);R=G(mid+1,r,mid+1,y,rs);
		return mp(min(L.first,L.second+R.first),L.second+R.second);
	}
	void C(int x,int y){C(1,n,x,y,1);}
	ll G(int x,int y){return G(1,n,x,y,1).first;}
	ll S(int x,int y){return G(1,n,x,y,1).second;}
};
struct _S{
	__ p0,p1;
	ll G(int x){return p0.S(1,x)+p1.S(1,x);}
	void B(){p0.B(1,n,1,0);p1.B(1,n,1,1);}
	void C(int x,int y){if(x>n)return;else if(x&1) p0.C(x,y);else p1.C(x,y);}
	bool c(int l,int r){
		ll val=G(l);
		if(l==r){if(val>1) return 0; else return 1;}
		if(l&1){
			ll tmp=G(r);if(!(r&1)) tmp=0;
			if(p1.S(++l,r)!=tmp) return 0;
			if(p1.G(l,r)<0) return 0;
			if(p0.G(l,r)+val<0) return 0;
		}
		else{
			ll tmp=G(r);if(r&1) tmp=0;
			if(p0.S(++l,r)!=tmp) return 0;
			if(p0.G(l,r)<0) return 0;
			if(p1.G(l,r)+val<0) return 0;
		}return 1;
	}
}s;

int main(){
	rd(n);
	for(int i=1;i<=n;i++) rd(a[i]),a[i]--;
	s.B(),rd(q);
	for(int _=1;_<=q;_++){
		rd(t);rd(l);rd(r);l++,r++;
		if(t==1)rd(k),s.C(l,k),s.C(r+1,-k); else printf("%d\n",s.c(l,r));
	}
	return 0;
}