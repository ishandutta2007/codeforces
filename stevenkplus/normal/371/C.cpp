#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;
const ll MAXH = 1E13;
const int MAXN = 1010;

int nb,ns,nc;
int pb,ps,pc;
ll R;

char str[MAXN];
int A,B,C;

bool can(ll x) {
  ll a = A * x - nb;
  ll b = B * x - ns;
  ll c = C * x - nc;
  ll money = 0;
  if (a > 0) money += pb * a;
  if (b > 0) money += ps * b;
  if (c > 0) money += pc * c;
  return money <= R;
}

int main() {
  scanf("%s", str);
  for(int i = 0; str[i]; ++i) {
    if (str[i] == 'B') ++A;
    else if (str[i] == 'S') ++B;
    else if (str[i] == 'C') ++C;
  }
  scanf("%d %d %d %d %d %d", &nb, &ns, &nc, &pb, &ps, &pc);
  cin >> R;

  ll lo = 0;
  ll hi = MAXH;
  while (lo + 1 < hi) {
    ll mid = (lo + hi) / 2;
    if (can(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  cout << lo << "\n";
  return 0;
}