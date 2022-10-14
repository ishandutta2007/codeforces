// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int MOD = 998244353;
 
struct mod_int {
    int val;
 
    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
 
        if (v >= MOD)
            v %= MOD;
 
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
 
    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
 
    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }
 
    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }
 
    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    mod_int operator++(int32_t) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int32_t) { mod_int before = *this; --*this; return before; }
 
    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }
 
    mod_int inv() const {
        return mod_inv(val);
    }
 
    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, mod_int &m) {
        return stream>>m.val;   
    }
};
#define NCR
const int N = 5e5;
mod_int fact[N],inv[N];
void init(int n=N){
	fact[0]=inv[0]=inv[1]=1;
	rep(i,1,N)fact[i]=i*fact[i-1];
	rep(i,2,N)inv[i]=fact[i].inv();
}
mod_int C(int n,int r){
	if(r>n || r<0)return 0;
	return fact[n]*inv[n-r]*inv[r];
}


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn=300005;
struct node{
	node* l;
	node* r;
	int sum,val;
	int key,prior;
	int size;
	bool rev;
};
node t[maxn];
int cnt=0;
node* create(int idx,int val){
     node *x;
     if(cnt<maxn)x=&t[cnt++];
     else x=new node();
     x->key=idx;
     x->l=NULL;
     x->r=NULL;
     x->prior=uniform_int_distribution<int>(0,1e9)(rng);
     x->sum=val;
     x->val=val;
     return x;
}
// GOD LEVEL DS(Truly unlimited power)
template<typename node>
struct Treap{
   node* tree;
   Treap(){
   	   tree=NULL;
   }
   int32_t size(node* x){
   	   return x?x->size:0;
   }
   void upd_sz(node* x){
   	   if(x)x->size=size(x->l)+size(x->r)+1;
   }
   void reset(node* x){
   	   if(x)x->sum=x->val;
   }
   void combine(node* &t,node* l,node *r){
        if(!l)t->sum=r->sum;
        else if(!r)t->sum=l->sum;
        else t->sum=l->sum+r->sum;
        // this part is same as segtree where we store some value of associative function  
   }
   void combine(node* &t){
   	   if(!t)return;
   	   reset(t);
   	   combine(t,t->l,t);
   	   combine(t,t,t->r);
   }
   // pushdown lazy values to its children
   // reversing a treap is just swaping its children
   void pushdown(node *t){
        if(!t || !t->rev)return;
        if(t->l){
        	t->l->rev=!(t->l->rev);
        	swap(t->l->l,t->l->r);
        }
        if(t->r){
        	t->r->rev=!(t->r->rev);
        	swap(t->r->l,t->r->r);
        } 
        t->rev=0;
   }
   // it splits the treap t into two treaps one having key less than some given key
   // other with bigger ones
   void split(node* t,node* &left,node* &right,int32_t key,int32_t add=0){
        pushdown(t); // first update if required
        if(!t){
        	left=right=NULL;
        	return;
        	//base condition;
        }
        int32_t curidx=add+size(t->l); // we store keys as implict key in terms of sizes of subtree
        // hence it is similar to a dynamic array
        if(curidx<=key)split(t->r,t->r,right,key,curidx+1),left=t;
        else split(t->l,left,t->l,key,add),right=t;
        upd_sz(t);
        combine(t);
   }
   // it merges two treaps a,b into a single treap
   void merge(node* &t,node* l,node* r){
   	   pushdown(l);
   	   pushdown(r);
   	   if(!l)t=r;
   	   else if(!r)t=l;
   	   else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
   	   else merge(r->l,l,r->l),t=r;
   	   upd_sz(t);
   	   combine(t);
   }
   void reverse(node* &t){
   	   swap(t->l,t->r);
   	   t->rev=!t->rev; 
   }
   void insert(node* &t,int32_t idx,int32_t val){
        node* tmp=create(idx,val); 
        node* templ;
        node* tempr;
        node* mid;
        split(t,templ,tempr,idx-1);
        merge(mid,templ,tmp);
        merge(t,mid,tempr);
   }
   // insert element at some index
   void insert(int idx,int val){
   	    insert(tree,idx,val);
   }
   void erase(node *&t,int idx){
   	    node* left;
   	    node* right;
   	    node* ri;
   	    node* ri2;
   	    split(t,left,right,idx-1);
        split(right,ri,ri2,0);
        merge(t,left,ri2); 
   }
   void erase(int idx){
   	    erase(tree,idx);
   }
   int query(node* &t,int l,int r){
   	   if(!t)return 0;
   	   node *le,*ri,*mid;
   	   split(t,le,mid,l-1);
   	   split(mid,mid,ri,r-l);
   	   int ans=mid->sum;
   	   merge(mid,mid,ri);
   	   merge(t,le,mid);
   	   return ans;
   }
   int query(int l,int r){
   	   return query(tree,l,r);
   }
   void upd(node *t,int idx,int val){
   	    node *left,*mid,*right;
   	    split(t,left,mid,idx-1);
   	    split(mid,mid,right,0);
   	    mid->val+=val;
   	    merge(mid,mid,right);
   	    merge(t,left,mid);
   }
   void upd(int idx,int val){
   	    upd(tree,idx,val);
   }
   void print(node* t,vector<int>&v){
   	   if(!t)return;
   	   pushdown(t);
   	   print(t->l,v);
   	   v.pb(t->val);
   	   print(t->r,v);
   }
   void print(vector<int>&v){
   	    print(tree,v);
   }
   int get(node* t,int idx){
       node* left;
       node* right;
       node* mid;
       split(t,left,right,idx-1);
       split(right,mid,right,0);
       int ans=mid->val;
       merge(right,mid,right);
       merge(t,left,right); 
       return ans;
   }
   int get(int idx){
      return get(tree,idx);
   }  
};

Treap<node> tr;

int solve(){
 		int n,m; cin >> n >> m;
 		int cond = 0;
 		vector<pii> segs(m);
 		for(auto &i:segs){
 			cin >> i;
 		}
 		sort(all(segs));
 		map<int,int> mp;
 		vector<array<int,3>> upds;

 		//for(int i = 0; i < n; i++)cout << tr.get(i) << " ";cout << endl;

 		for(auto i:segs){
 			auto [x,y] = i;
 			auto val = tr.get(y - 1);
 			cond -= mp[val];
 			mp[val] = 1;
 			cond++;
 			tr.erase(x - 1);
 			tr.insert(y - 1,x);
 		}
 		reverse(all(segs));
 		for(auto i:segs){
 			auto [x,y] = i;
 			tr.erase(y - 1);
 			tr.insert(x - 1,x);
 		}
 		//cout << cond << endl;
 		int comp = cond + 1;
 		mod_int ans = C(2*n - comp,n);
 		cout << ans << endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for(int i = 1; i <= 200000; i++){
    	tr.insert(i - 1,i);
    }
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}