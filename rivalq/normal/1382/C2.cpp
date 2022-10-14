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


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn=300005;
struct node{
	node* l;
	node* r;
	int sum,val;
	int key,prior;
	int size;
	bool rev;
	int lazy;
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
     x->lazy=0;
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
   void propogate(node *t){
   	if(!t || !t->lazy)return;
   	t->val+=t->lazy;
   	t->sum+=t->lazy*size(t);
   	if(t->l)t->l->lazy+=t->lazy;
    	if(t->r)t->r->lazy+=t->lazy;
    	t->lazy=0;
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
   	   propogate(t->l);propogate(t->r);
   	   combine(t,t->l,t);
   	   combine(t,t,t->r);
   }
   
   // it splits the treap t into two treaps one having key less than some given key
   // other with bigger ones
   void split(node* t,node* &left,node* &right,int32_t key,int32_t add=0){
        pushdown(t); // first update if required
        propogate(t); // lazy 
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
   	   propogate(l);
   	   propogate(r);
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
   void rupd(node *&t,int l,int r,int val){
   	node *left,*mid,*right;
   	split(t,left,right,l-1);
   	split(right,mid,right,r-l);
   	mid->lazy+=val;
   	merge(right,mid,right);
   	merge(t,left,right);
   }
   void rupd(int l,int r,int val){
   	rupd(tree,l,r,val);
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




int solve(){
	Treap<node>tr;
	int n;cin>>n;
	vector<int>a(n+1),b(n+1);
	rep3(n){
		char c;cin>>c;
		a[i]=c-48;
	}
	rep3(n){
		char c;cin>>c;
		b[i]=c-48;
	}
	rep3(n){
		tr.insert(i,a[i]);
	}
	vector<int>ans;
	for(int i=n-1;i>=0;i--){
		int val=tr.get(i)%2;
		if(val==b[i])continue;
		int val2=tr.get(0)%2;
		if(val!=val2){
		         tr.rupd(0,0,1);
		         ans.pb(1);
		}
		ans.pb(i+1);
		tr.rupd(0,i,1);
		node *left,*right;
		tr.split(tr.tree,left,right,i);
		tr.reverse(left);
		tr.merge(tr.tree,left,right);
	}
	//vector<int> v;
	//tr.print(v);
	//for(auto i:v)cout<<i%2<<" ";cout<<endl;
	cout<<sz(ans)<<" ";
	for(auto i:ans)cout<<i<<" ";cout<<endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}