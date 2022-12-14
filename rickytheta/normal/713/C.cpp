#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

const int MAX = 1<<30;
struct node{
  ll val;
  node *lch,*rch;
  node(){
    val=0;
    lch=rch=NULL;
  }
};
node *root;
void add(int l,int r,ll v,int a,int b,node *cur){
  if(r<=a || b<=l)return;
  if(l<=a && b<=r){
    cur->val += v;
  }else{
    if(cur->lch==NULL)cur->lch = new node();
    if(cur->rch==NULL)cur->rch = new node();
    int mid = (a+b)>>1;
    add(l,r,v,a,mid,cur->lch);
    add(l,r,v,mid,b,cur->rch);
  }
}
void add(int l,int r,ll v){
  add(l,r,v,0,MAX,root);
}
ll getat(int k){
  ll ret = 0;
  node *cur = root;
  int a=0,b=MAX;
  while(cur != NULL){
    ret += cur->val;
    int mid = (a+b)>>1;
    if(k<mid){
      b=mid;
      cur=cur->lch;
    }else{
      a=mid;
      cur=cur->rch;
    }
  }
  return ret;
}
ll sum(node *cur,ll cnt){
  if(cur==NULL)return 0;
  return cnt*cur->val + sum(cur->lch,cnt>>1) + sum(cur->rch,cnt>>1);
}
ll sum(){
  return sum(root,MAX);
}

int n;
int a[3531];

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",a+i);
  root=new node();
  REP(i,n)a[i]=a[i]+n-i;
  ll ans = 0;
  REP(i,n){
    ll v = a[i];
    ans += v;
    int l=-1, r=MAX;
    while(l+1<r){
      int mid = (l+r)>>1;
      if(getat(mid)>=0){
        r = mid;
      }else{
        l = mid;
      }
    }
    add(0,v,-1);
    add(v,r,1);
  }
  ans += sum();
  printf("%lld\n",ans);
  return 0;
}