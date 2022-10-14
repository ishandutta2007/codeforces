#include<bits/stdc++.h>
#pragma GCC optimize "trapv"
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;

ll maxn=1e18+10;
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
struct node{
	int l=0;
	char a,lazy;
};
struct node t[20000100];
int cur=0;
inline void extend(int idx){
    if(t[idx].l==0){
    	t[idx].l=++cur;
    	int r=++cur;
        t[t[idx].l].a=0;
        t[r].a=0;
        t[t[idx].l].lazy=0;
        t[r].lazy=0;
    }
}
inline void apply(int idx,int val){
	if(val==1){
		t[idx].a=2;
		t[idx].lazy=1;
	}
	else if(val==2){
		t[idx].a=0;
		t[idx].lazy=2;
	}
	else{
		t[idx].a=2-t[idx].a;
		if(t[idx].lazy==1 || t[idx].lazy==2)t[idx].lazy=3-t[idx].lazy;
		else if(t[idx].lazy==3)t[idx].lazy=0;
		else t[idx].lazy=3;
	}
}
inline void pushdown(int idx){
    extend(idx);
    if(t[idx].lazy){
    	int l=t[idx].l;
    	int r=l+1;
    	apply(l,t[idx].lazy);
    	apply(r,t[idx].lazy);
    	t[idx].lazy=0;
    }
}
inline void update(int idx,ll tl,ll tr,ll &l,ll &r,int &val){
	  if(tr<l || tl>r)return;
	  if(tr<=r && tl>=l){
	  	 apply(idx,val);
	  	 return;
	  }
	  if(tl!=tr)pushdown(idx);
	  extend(idx);
	  ll mid=(tl+tr)/2;
	  update(t[idx].l,tl,mid,l,r,val);
	  update(t[idx].l+1,mid+1,tr,l,r,val);
	  int ln=t[idx].l;
	  int rn=t[idx].l+1;
      if(t[ln].a==2 && t[rn].a==2)t[idx].a=2;
      else if(t[ln].a || t[rn].a)t[idx].a=1;
      else t[idx].a=0;
}
ll query(int idx,ll tl,ll tr){
	if(tl==tr){
		//assert(t[idx].a==0);
		return tl;
	}
	pushdown(idx);
	int l=t[idx].l;
	int r=t[idx].l+1;
	ll mid=(tl+tr)/2;
	if(t[idx].a==2)return tr+1;
	if(t[l].a==2)return query(r,mid+1,tr);
    else if(t[l].a==0)return tl;
    else return query(l,tl,mid); 
}
void solve(){
 int n;cin>>n;
 t[0].a=0;
 t[0].lazy=0;
 rep3(n){
 	int val;cin>>val;
 	ll l,r;cin>>l>>r;
 	update(0,1,maxn,l,r,val);
 	cout<<query(0,1,maxn)<<endl;
 }
 return;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}