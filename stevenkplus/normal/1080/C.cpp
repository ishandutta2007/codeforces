#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<pair<ll, ll>, pair<ll, ll> > rect;
#define x1 first.first
#define y1 first.second
#define x2 second.first
#define y2 second.second

ll countArea(rect r) {
  return max(0LL, r.x2 - r.x1 + 1) * max(0LL, r.y2 - r.y1 + 1);
}

ll countWhite(rect r) {
  ll area = countArea(r);
  ll ans = area / 2;
  if (area % 2 == 1) {
    if ((r.x1 + r.y1) % 2 == 0) {
      ++ans;
    }
  }
  return ans;
}

ll countBlack(rect r) {
  return countArea(r) - countWhite(r);
}

rect intersect(rect a, rect b) {
  rect r;
  r.x1 = max(a.x1, b.x1);
  r.x2 = min(a.x2, b.x2);
  r.y1 = max(a.y1, b.y1);
  r.y2 = min(a.y2, b.y2);
  return r;
}

int main() {
  int q;
  cin >> q;
  for(int i = 0; i < q; ++i) {
    rect r0;
    rect r1, r2;
    r0.x1 = r0.y1 = 1;
    cin >> r0.y2 >> r0.x2;
    cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
    cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;

    rect r3 = intersect(r1, r2);
    ll white = countWhite(r0);
    white += countBlack(r1);
    white -= countWhite(r2);

    white -= countBlack(r3);
    cout << white << " " << countArea(r0) - white << "\n";
  }
 
}