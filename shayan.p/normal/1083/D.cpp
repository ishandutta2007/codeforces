// Remember...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int n;
struct Seg{
    int lza[4*maxn], lzb[4*maxn];
    ll sma[4*maxn], smb[4*maxn], val[4*maxn];

    Seg(){
	fill(lza, lza+4*maxn, -2);
	fill(lzb, lzb+4*maxn, -2);
    }
    void shift(int l,int r,int id){
	if(lza[id]==-2 && lzb[id]==-2) return;
	if(lza[id]!=-2) sma[id]= 1ll*(r-l)*lza[id];
	if(lzb[id]!=-2) smb[id]= 1ll*(r-l)*lzb[id];
	if(lza[id]!=-2) val[id]= smb[id] * lza[id];
	if(lzb[id]!=-2) val[id]= sma[id] * lzb[id];
	if(r-l>1){
	    if(lza[id]!=-2) lza[2*id]= lza[2*id+1]= lza[id];
	    if(lzb[id]!=-2) lzb[2*id]= lzb[2*id+1]= lzb[id];
	}
	lza[id]= lzb[id]= -2;
    }
    void mrg(int id){
	sma[id]= sma[2*id] + sma[2*id+1];
	smb[id]= smb[2*id] + smb[2*id+1];
	val[id]= val[2*id] + val[2*id+1];
    }
    void puta(int f,int s,int x,int l=0,int r=n,int id=1){
	if(f>=s || l>=r) return;
	shift(l,r,id);
	if(s<=l || r<=f) return;
	if(f<=l && r<=s){ lza[id]=x; shift(l,r,id); return; }
	int mid=(l+r)>>1;
	puta(f,s,x,l,mid,2*id);
	puta(f,s,x,mid,r,2*id+1);
	mrg(id);
    }
    void putb(int f,int s,int x,int l=0,int r=n,int id=1){
	if(f>=s || l>=r) return;
	shift(l,r,id);
	if(s<=l || r<=f) return;
	if(f<=l && r<=s){ lzb[id]=x; shift(l,r,id); return; }
	int mid=(l+r)>>1;
	putb(f,s,x,l,mid,2*id);
	putb(f,s,x,mid,r,2*id+1);
	mrg(id);
    }
    ll ask(int f,int s,int l=0,int r=n,int id=1){
	if(f>=s || l>=r) return 0;
	shift(l,r,id);
	if(s<=l || r<=f) return 0;
	if(f<=l && r<=s) return val[id];
	int mid=(l+r)>>1;
	return ask(f,s,l,mid,2*id) + ask(f,s,mid,r,2*id+1);
    }
};
inline ll f(int a,int b){
    return (1ll*(b+a)*(b-a+1))/2;
}

Seg seg1,seg2,seg3;

map<int,int> mp;

int a[maxn], bef[maxn], aft[maxn];
deque<int> mx, mn;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    for(int i=0;i<n;i++){
	if(mp.count(a[i])) bef[i]= mp[a[i]];
	else bef[i]=-1;
	mp[a[i]]=i;
    }
    mp.clear();
    for(int i=n-1;i>=0;i--){
	if(mp.count(a[i])) aft[i]= mp[a[i]];
	else aft[i]= n;
	mp[a[i]]=i;
    }
    for(int i=0;i<n;i++){
	seg2.putb(i,i+1,i-1);
    }

    ll ans=0;
    
    int l=0;
    for(int r=0;r<n;r++){
	l=max(l, bef[r]+1);
	while(sz(mn) && mn[0]<l) mn.pop_front();
	while(sz(mx) && mx[0]<l) mx.pop_front();
	while(sz(mn) && aft[ mn.back() ] >= aft[r]) mn.pop_back();
	while(sz(mx) && bef[ mx.back() ] <= bef[r]) mx.pop_back();

	seg3.puta(0,n,r+1);
	
	int pos=l;
	if(sz(mn)) pos=mn.back()+1;
	mn.PB(r);
	seg1.puta(pos,r+1,aft[r]);
	seg2.puta(pos,r+1,aft[r]);
	
	pos=l;
	if(sz(mx)) pos=mx.back()+1;
	mx.PB(r);
	seg1.putb(pos,r+1,bef[r]);
	seg3.putb(pos,r+1,bef[r]);

	ans+= seg2.ask(l,r+1);
	ans+= seg3.ask(l,r+1);
	ans-= seg1.ask(l,r+1);
	ans-= 1ll* (r+1) * f(l-1,r-1);
	ans%=mod;
    }
    if(ans<0) ans+= mod;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")