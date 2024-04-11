#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (int i = (x); i < (y); i++)
#define repl(i,x,y) for (int i = (x); i <= (y); i++)

#define LSOne(S) (S & (-S))
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> li;
typedef vector<vector<li>> vv;
const int INF = 1e9;
typedef vector<int> vi;

class SegmentTree {                              // OOP style
private:
  int n;                                         // n = (int)A.size()
  vi A, st, lazy;                                // the arrays

  int l(int p) { return  p<<1; }                 // go to left child
  int r(int p) { return (p<<1)+1; }              // go to right child


  void build(int p, int L, int R) {              // O(n)
    if (L == R)
      st[p] = A[L];                              // base case
    else {
      int m = (L+R)/2;
      build(l(p), L  , m);
      build(r(p), m+1, R);
    }
  }

  void propagate(int p, int L, int R) {
    if (lazy[p] != -1) {                         // has a lazy flag                        // [L..R] has same value
    if (L != R) {
        lazy[l(p)] = lazy[r(p)] = lazy[p];  
    }                               // not a leaf       // propagate downwards
      else {
          st[p] = lazy[p];
      }                                      // L == R, a single index                         // time to update this
      lazy[p] = -1;                              // erase lazy flag
    }
  }

  int RMQ(int p, int L, int R, int x) {   // O(log n)
    propagate(p, L, R);                          // lazy propagation
                    // infeasible
    if ((L == x) && (R == x)) return st[p];      // found the segment
    int m = (L+R)/2;
    if (x <= m) {
        return RMQ(l(p), L, m, x);
    } else {
        return RMQ(r(p), m+1,R, x);
    }   
  }

  void update(int p, int L, int R, int i, int j, int val) { // O(log n)
    propagate(p, L, R);                          // lazy propagation
    if (i > j) return;
    if ((L >= i) && (R <= j)) {                  // found the segment
      lazy[p] = val;                             // update this
      propagate(p, L, R);                        // lazy propagation
    }
    else {
      int m = (L+R)/2;
      update(l(p), L  , m, i          , min(m, j), val);
      update(r(p), m+1, R, max(i, m+1), j        , val);
    }
  }

public:
  SegmentTree(int sz) : n(sz), st(4*n), lazy(4*n, -1) {}

  SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
  }

  void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

  int RMQ(int x) { return RMQ(1, 0, n-1, x); }
};

signed main() {
    ios_base::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);
   int n;cin>>n;
   vector<int> arr(n);
   set<int> coords;
   rep(i, 0, n) {
       cin>>arr[i];
       coords.insert(arr[i]);
   }
   vector<tuple<int,int,int>> queries;
   int q;cin>>q;
   rep(i,0, q) {
       int no;
       cin>>no;
       if (no == 1) {
           int k,w;cin>>k>>w;k--;
           queries.push_back({1,k,w});
           coords.insert(w);
       }
       if (no == 2) {
           int k;cin>>k;k--;
           queries.push_back({2,k,-1});
       }
       if (no == 3) {
           int l, r;cin>>l>>r;
           queries.push_back({3,l-1,r+1});
           coords.insert({l-1});
           coords.insert({r+1});
       }
   }
   map<int,int> coord_map;
   int co = 0;
   for (auto x: coords) {
       coord_map[x] = co++;
   }
   vector<int> next_node(n+2*q, INF);
   vector<int> node_val(n+2*q, -1);
   vi ini(co, INF);
    SegmentTree tr(ini);
    auto getnextnode = [&](int before, int x) {
        int xx = coord_map[x];
        int nxtinterval = tr.RMQ(xx);
        node_val[before] = x;
        if (nxtinterval == INF) return;
        auto [a1,a2,a3] = queries[nxtinterval];
        if (abs(x-a2) < abs(x- a3)) {
            next_node[before]= n + nxtinterval*2;
            //return n + nxtinterval*2;
        } else {
            next_node[before] = n + nxtinterval*2 + 1;
            //return n + nxtinterval*2+1;
        }
    };

    for (int qidx = q-1; qidx >= 0; qidx--) {
        auto [ty, v1,v2] = queries[qidx];
        if (ty == 2) continue;
        if (ty == 1) {
            getnextnode(qidx*2 + n, v2);
        }
        if (ty == 3) {
            getnextnode(qidx*2 + n, v1);
            getnextnode(qidx*2 + n + 1, v2);
            int x1 = coord_map[v1];
            int x2 = coord_map[v2];
            tr.update(x1,x2, qidx);
        }
    }
    rep(i, 0, n) {
        getnextnode(i, arr[i]);
    }
    const int MAXBINARY = 25;
    vector<vector<int>> hopsarr(MAXBINARY, vector<int>(n+2*q, INF));
    hopsarr[0] = next_node;
    rep(i, 1, MAXBINARY) {
        rep(u, 0, n+2*q) {
            int imd = hopsarr[i-1][u];
            if (imd == INF) continue;
            hopsarr[i][u] = hopsarr[i-1][imd];
        }
    }
    vector<int> buildingscurnode(n);
    rep(i,0, n) {
        buildingscurnode[i] = i;
    }
    rep(qidx, 0, q) {
        auto [ty, v1, v2] = queries[qidx];
        if (ty == 1) {
            buildingscurnode[v1] = n+2*qidx;
        } 
        if (ty == 2) {
            int atmost = n + qidx*2;
            int starting = buildingscurnode[v1];
            for (int i = MAXBINARY-1; i >=0; i--) {
                if (hopsarr[i][starting] < atmost) {
                    starting = hopsarr[i][starting];
                }
            }
            cout<<node_val[starting]<<"\n";
        }
    }


}