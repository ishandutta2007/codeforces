#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

// Segment tree (RMQ type)
struct seg {
  int n;
  vector<int> color; // 0
  vector<ll> sum; // 
  vector<ll> added; // 
  seg(){}
  seg(int mx) {
    n = 1; while (n < mx) n <<= 1;
    color = vector<int>(n<<1);
    sum = vector<ll>(n<<1);
    added = vector<ll>(n<<1);
  }
  bool isFlat(int i) { return color[i] != 0;}
  int width(int i) { return 1<<(__builtin_clz(i)-__builtin_clz(n));}
  void prop(int i, int c) {
    color[c] = color[i];
    added[c] += added[i];
    sum[c] += added[i]*width(c);
  }
  void prop(int i) {
    prop(i,i<<1);
    prop(i,i<<1|1);
    color[i] = 0;
    added[i] = 0;
  }
  void upd(int i) {
    int l = i<<1, r = i<<1|1;
    if (isFlat(l) && isFlat(r) && color[l] == color[r]) {
      color[i] = color[l];
    }
    sum[i] = sum[l]+sum[r];
  }
  void set(int a, int b, int x) { set(a,b,x,1,0,n);}
  void set(int a, int b, int x, int i, int l, int r){
    if (a <= l && r <= b && isFlat(i)) {
      sum[i] += llabs(color[i]-x)*(r-l);
      added[i] += abs(color[i]-x);
      color[i] = x;
      return;
    }
    if (isFlat(i)) prop(i);
    int c = (l+r)>>1;
    if (a < c) set(a,b,x,i<<1,l,c);
    if (c < b) set(a,b,x,i<<1|1,c,r);
    upd(i);
  }
  ll get(int a, int b) { return get(a,b,1,0,n);}
  ll get(int a, int b, int i, int l, int r){
    if (a <= l && r <= b) return sum[i];
    int c = (l+r)>>1;
    if (isFlat(i)) prop(i);
    ll res = 0;
    if (a < c) res += get(a,b,i<<1,l,c);
    if (c < b) res += get(a,b,i<<1|1,c,r);
    return res;
  }
};
//


int main() {
  int n, m;
  scanf("%d%d",&n,&m);
  seg t(n);
  for (int i = 0; i < n; ++i) t.color[t.n+i] = i+1;

  for (int i = 0; i < m; ++i) {
    int typ,l,r;
    scanf("%d%d%d",&typ,&l,&r);
    --l;
    if (typ == 1) { // update
      int x;
      scanf("%d",&x);
      t.set(l,r,x);
    } else { // sum
      printf("%I64d\n",t.get(l,r));
    }
  }
  return 0;
}