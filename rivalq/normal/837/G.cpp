#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
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


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
struct node{
	int y1=0,a=0,b=0;
	node operator+(const node &rhs){
         node temp;
         temp.y1=this->y1+rhs.y1;
         temp.a=this->a+rhs.a;
         temp.b=this->b+rhs.b;
         return temp;
	}
}nul;
struct Vertex {
    Vertex *l, *r;
    node sum;

    Vertex(node val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(nul) {
        if (l) sum = sum + l->sum;
        if (r) sum = sum + r->sum;
    }
};

Vertex* build(node a[], int tl, int tr) {
    if (tl == tr)
        return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}

node get_sum(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return nul;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}
Vertex* update(Vertex* v, int tl, int tr, int pos, node new_val) {
    if (tl == tr)
        return new Vertex(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}
const int maxn=200005;
node a[75005];
node b[75005];
Vertex* pre1[maxn];
Vertex* pre2[maxn];
int prefa[75005],prefb[75005];
int solve(){
 int n;cin>>n;
 map<int,vector<int>>mp1,mp2;
 rep(i,1,n+1){
    int x1,x2,y1,val1,val2,y2;cin>>x1>>x2>>y1>>val1>>val2>>y2;
    a[i].y1=y1;b[i].y1=y2;
    a[i].a=val1;b[i].a=val1;
    a[i].b=val2;b[i].b=val2;
    mp1[x1].pb(i);
    mp2[x2].pb(i);
    prefa[i]=val1+prefa[i-1];
    prefb[i]=val2+prefb[i-1];
 }
 pre1[0]=build(a,1,n);
 for(int i=1;i<=200000;i++){
 	Vertex* temp=pre1[i-1];
 	for(auto j:mp1[i-1])temp=update(temp,1,n,j,nul);
 	pre1[i]=temp;	 // pre[i]->segtree for x==i;
 }
 pre2[200001]=build(b,1,n);  // if x>2*10^5
 for(int i=200000;i>=0;i--){
     Vertex* temp=pre2[i+1];
     for(auto j:mp2[i])temp=update(temp,1,n,j,nul);
     pre2[i]=temp;  // if x==i 
 }
 int last=0;
 int m;cin>>m;
 rep3(m){
 	int l,r,x;cin>>l>>r>>x;
 	x=(x+last)%(hell-7);
 	//cout<<l<<" "<<r<<" "<<x<<endl; 
 	// handling boundary cases
 	if(x>200000){
 		last=get_sum(pre2[200001],1,n,l,r).y1;
 		cout<<last<<endl;
 	}
 	else{
 		int ta=prefa[r]-prefa[l-1];
 		int tb=prefb[r]-prefb[l-1];
        auto s1=get_sum(pre1[x],1,n,l,r);
        auto s2=get_sum(pre2[x],1,n,l,r);
        ta-=s1.a+s2.a;
        tb-=s1.b+s2.b;
        //cout<<s1.y1<<" "<<s2.y1<<endl;
        last=x*ta+tb+s1.y1+s2.y1;
        cout<<last<<endl;
 	}
 }
 return 0;
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