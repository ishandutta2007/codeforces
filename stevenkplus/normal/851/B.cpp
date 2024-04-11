// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second

// =========== Book ============ //

ll sq(ll x) {
  return x * x;
}

// =========== Solution ============= //

int main()  {
  int ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  ll ab = sq(ax - bx) + sq(ay - by);
  ll bc = sq(cx - bx) + sq(cy - by);
  if (ab == bc && !(ax + cx == bx + bx && ay + cy == by + by)) cout << "Yes\n";
  else cout << "No\n";
}