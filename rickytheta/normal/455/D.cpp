#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);i++)

const int B = 400;
const int C = 400;

int n;
int a[125252];

typedef int nodeid;
struct node{
  static node ff[125252];
  nodeid ths,l,r;
  int v;
  node(){}
  void set(nodeid ths_,int v_){
    ths = l = r = ths_;
    v = v_;
  }
  node left(){return ff[l];}
  node right(){return ff[r];}
  // this - x - this.r
  void ins(nodeid x){
    ff[x].l = ths;
    ff[x].r = r;
    ff[r].l = x;
    ff[ths].r = x;
  }
  void ers(){
    ff[l].r = r;
    ff[r].l = l;
    l = r = ths;
  }
};
node node::ff[125252];
nodeid gai = 0;
nodeid mynew(int v){
  node::ff[gai].set(gai,v);
  return gai++;
}
node nd(nodeid x){return node::ff[x];}
void debug(nodeid x){
  return;
  printf("(%d)[l:%d,r:%d,v:%d]\n",x,nd(x).l,nd(x).r,nd(x).v);
}

nodeid ghq[C];
int cnt[C][125252];

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",a+i);
  int cc = (n+B-1)/B;
  REP(i,cc){
    ghq[i] = mynew(-1);
  }
  REP(i,n){
    int pos = i/B;
    cnt[pos][a[i]]++;
    nodeid po = nd(ghq[pos]).l;
    nd(ghq[pos]).left().ins(mynew(a[i]));
  }
  int q;
  scanf("%d",&q);
  int lastans = 0;
  while(q--){
    int t;
    scanf("%d",&t);
    if(t==1){
      int l,r;
      scanf("%d%d",&l,&r);
      l = (l+lastans-1)%n;
      r = (r+lastans-1)%n;
      if(l>r)swap(l,r);
      int lp = l/B;
      int rp = r/B;
      nodeid cur;
      // erase r
      cur = nd(ghq[rp]).r;
      REP(i,r-rp*B)cur = nd(cur).r;
      nodeid er = cur;
      cnt[rp][nd(cur).v]--;
      nd(cur).ers();
      // slide
      FOR(i,lp,rp){
        // i tail to i+1 head
        nodeid yo = nd(ghq[i]).l;
        int v = nd(yo).v;
        cnt[i][v]--;
        cnt[i+1][v]++;
        nd(yo).ers();
        nd(ghq[i+1]).ins(yo);
      }
      // insert l
      cur = ghq[lp];
      REP(i,l-lp*B)cur = nd(cur).r;
      cnt[lp][nd(er).v]++;
      nd(cur).ins(er);
    }else{
      int l,r,k;
      scanf("%d%d%d",&l,&r,&k);
      l = (l+lastans-1)%n;
      r = (r+lastans-1)%n;
      if(l>r)swap(l,r);
      k = (k+lastans-1)%n + 1;
      int ans = 0;
      int lp = l/B;
      int rp = r/B;
      if(lp==rp){
        nodeid cur = ghq[lp];
        int o = l-lp*B;
        int p = r-lp*B;
        REP(i,o)cur=nd(cur).r;
        REP(i,p-o+1){
          cur=nd(cur).r;
          ans += nd(cur).v==k;
        }
      }else{
        nodeid cur;
        // left
        cur = ghq[lp];
        cur = nd(cur).r;
        REP(i,l-lp*B)cur=nd(cur).r;
        while(nd(cur).v!=-1){
          ans += nd(cur).v==k;
          cur=nd(cur).r;
        }
        // right
        cur = ghq[rp];
        REP(i,r-rp*B+1){
          cur=nd(cur).r;
          ans += nd(cur).v==k;
        }
        // center
        FOR(i,lp+1,rp){
          ans += cnt[i][k];
        }
      }
      printf("%d\n",ans);
      lastans = ans;
    }
  }
  return 0;
}