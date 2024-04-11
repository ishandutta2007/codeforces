#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()

struct segval{
  ll mi,ma,minpref,maxpref,tot;
  segval(){}
  segval(int x): mi(x),ma(x), maxpref(max(0,x)), minpref(min(0,x)),tot(x){}
};
segval operator+(const segval& l,const segval& r) {
  segval res;
  res.mi=min(l.mi,r.mi);
  res.ma=max(l.ma,r.ma);
  res.minpref= min(l.minpref, l.tot+r.minpref);
  res.maxpref= max(l.maxpref, l.tot+r.maxpref);
  res.tot = l.tot+r.tot;
  return res;
}
const int MAXN = 100000;
segval t[4*MAXN];
int d[MAXN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = segval(d[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
segval sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N,Q;
  cin>>N>>Q;
  //vector<ll> D(N);
  for(int i=0;i<N;++i){
    cin>>d[i];
  }
  for(int i=0;i<N;++i){
    ll j;
    cin>>j;
    d[i]-=j;
  }
  build(1,0,N-1);
  // for a segment, sum must be 0, prefix sums must be nonpositive
  // value is the maximum absolute
  for(int i=0;i<Q;++i){
    int l,r;
    cin>>l>>r;
    --l;--r;
    segval p = sum(1,0,N-1,l,r);
    //cout<<p.minpref<<" "<<p.tot<<" "<<p.maxpref<<endl;
    if(p.tot!=0||p.maxpref>0){
      cout<<"-1\n";
    }
    else cout<<-p.minpref<<"\n";
  }
  cout<<flush;
}