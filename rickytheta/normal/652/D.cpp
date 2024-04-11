#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

struct Treap{
private:
  static const ll rd_msk = (1ll<<32)-1;
  static ll rd(){
    static ll rd_x = 123456789;
    static ll rd_y = 362436069;
    static ll rd_z = 521288629;
    static ll rd_w = 88675123;
    ll t = (rd_x^(rd_x<<11))&rd_msk;
    rd_x = rd_y;
    rd_y = rd_z;
    rd_z = rd_w;
    return rd_w = (rd_w^(rd_w>>19)) ^ (t^(t>>8));
  }
  struct node{
    ll val,pri,cnt;;
    node *lch, *rch;
    node(ll val):val(val),cnt(1){
      pri = rd();
      lch = rch = NULL;
    }
  };
public:
  node *root;
  Treap():root(NULL){}
private:
  ll count(node *t){return t==NULL?0:t->cnt;}
  node* update(node *t){t->cnt=count(t->lch)+count(t->rch)+1;return t;}
  node* merge(node *l, node *r){
    if(!l || !r)return !l?r:l;
    if(l->pri > r->pri){
      l->rch = merge(l->rch,r);
      return update(l);
    }else{
      r->lch = merge(l,r->lch);
      return update(r);
    }
  }
  pair<node*,node*> split(node *t, ll k){
    if(!t) return make_pair<node*,node*>(NULL,NULL);
    if(k <= count(t->lch)){
      pair<node*,node*> s = split(t->lch,k);
      t->lch = s.second;
      return make_pair(s.first,update(t));
    }else{
      pair<node*,node*> s = split(t->rch,k-count(t->lch)-1);
      t->rch = s.first;
      return make_pair(update(t),s.second);
    }
  }
  ll __find(node *p,ll v){
    if(!p)return 0;
    if(p->val==v)return count(p->lch);
    return (p->val > v)?__find(p->lch,v):(count(p->lch)+1+__find(p->rch,v));
  }
  ll __less(node *p,ll v){
    if(!p)return 0;
    return (p->val >= v)?__less(p->lch,v):(count(p->lch)+1+__less(p->rch,v));
  }
  ll __less_eq(node *p,ll v){
    if(!p)return 0;
    return (p->val > v)?__less_eq(p->lch,v):(count(p->lch)+1+__less_eq(p->rch,v));
  }
  ll __get_at(node *p,ll k,ll acc){
    if(!p)return -1;
    ll lc=count(p->lch);
    if(acc+lc==k)return p->val;
    if(acc+lc>k)return __get_at(p->lch,k,acc);
    if(acc+lc<k)return __get_at(p->rch,k,acc+lc+1);
  }
public:
  void merge(Treap that){
    root = merge(root, that.root);
  }
  Treap split(ll k){
    Treap that;
    pair<node*,node*> p = split(root,k);
    root = p.first;
    that.root = p.second;
    return that;
  }
  void insert_at(ll v,ll k){
    pair<node*,node*> p = split(root,k);
    node* nn = new node(v);
    root = merge(p.first, nn);
    root = merge(root, p.second);
  }
  void erase_at(ll k){
    pair<node*,node*> p,q;
    q = split(root,k+1);
    p = split(q.first,k);
    root = merge(p.first, q.second);
  }
  void insert_by(ll v){
    insert_at(v,__less(root,v));
  }
  void erase_by(ll v){
    erase_at(__find(root,v));
  }
  ll count_less(ll v){
    return __less(root,v);
  }
  ll count_less_equal(ll v){
    return __less_eq(root,v);
  }
  ll get_at(ll k){
    return __get_at(root,k,0);
  }
  ll size(){
    return count(root);
  }
};


int n;
pair<pii,int> seg[252521];
int res[252521];

int main(){
  scanf("%d",&n);
  REP(i,n){
    int x,y;
    scanf("%d%d",&x,&y);
    seg[i] = make_pair(pii(x,y),(int)i);
  }
  sort(seg,seg+n);
  Treap tr;
  REP(i,n){
    tr.insert_by(seg[i].first.second);
  }
  REP(i,n){
    tr.erase_by(seg[i].first.second);
    res[seg[i].second] = tr.count_less_equal(seg[i].first.second);
  }
  REP(i,n){
    printf("%d\n", res[i]);
  }
  return 0;
}