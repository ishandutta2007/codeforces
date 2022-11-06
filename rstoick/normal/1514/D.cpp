#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
struct Mo
{
  vector< int > left, right, order;
  vector< bool > v;
  int width;
  int nl, nr, ptr;

  Mo(int n) : width((int) sqrt(n)), nl(0), nr(0), ptr(0), v(n) {}

  void insert(int l, int r) /* [l, r) */
  {
    left.push_back(l);
    right.push_back(r);
  }

  /*  */
  void build()
  {
    order.resize(left.size());
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&](int a, int b)
    {
      if(left[a] / width != left[b] / width) return left[a] < left[b];
      return right[a] < right[b];
    });
  }

  /*  1 , id */
  int process()
  {
    if(ptr == order.size()) return (-1);
    const auto id = order[ptr];
    while(nl > left[id]) distribute(--nl);
    while(nr < right[id]) distribute(nr++);
    while(nl < left[id]) distribute(nl++);
    while(nr > right[id]) distribute(--nr);
    return (order[ptr++]);
  }

  inline void distribute(int idx)
  {
    v[idx].flip();
    if(v[idx]) add(idx);
    else del(idx);
  }

  void add(int idx);

  void del(int idx);
};
int N, M, A[400000], ans[400000];
int reach[400001], sum[800001], now;

void Mo::add(int idx)
{
  reach[sum[A[idx]]]--;
  ++sum[A[idx]];
  reach[sum[A[idx]]]++;
  if(sum[A[idx]] > now) ++now;
}

void Mo::del(int idx)
{
  reach[sum[A[idx]]]--;
  if(sum[A[idx]] == now && reach[sum[A[idx]]] == 0) --now;
  --sum[A[idx]];
  reach[sum[A[idx]]]++;
}

int main()
{
  fast_io;
  while(scanf("%d", &N), N) {
    memset(sum, 0, sizeof(sum));
    memset(reach, 0, sizeof(reach));
    now = 0;

    scanf("%d", &M);
    for(int i = 0; i < N; i++) {
      scanf("%d", &A[i]);
      A[i] += 400000;
    }
    Mo mo(N);
    vector<int> kukan;
    for(int i = 0; i < M; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      mo.insert(--x, y);
      kukan.push_back(y-x);
    }
    mo.build();
    for(int i = 0; i < M; i++) {
      int idx = mo.process();
      ans[idx] = now;
    }
    for(int i = 0; i < M; i++) {
      if(ans[i] <= kukan[i]/2 + kukan[i]%2){
        cout<<1<<endl;
        continue;
      }
      cout<<ans[i]-(kukan[i]-ans[i])<<endl;
    }
    break;
  }
}