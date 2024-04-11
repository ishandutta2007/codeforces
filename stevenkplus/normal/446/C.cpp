#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
const int MAXN = 300100;
const int BLOCK = 800;
const int MOD = 1E9 + 9;

int sums[MAXN];
int fib[MAXN];
int pref[MAXN];

int N, M;

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}

void prec() {
  fib[0] = 1;
  fib[1] = 1;
  for(int i = 2; i < MAXN; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
    fib[i] %= MOD;
  }
  for(int i = 0; i + 1 < MAXN; ++i) {
    pref[i + 1] = pref[i] + fib[i];
    pref[i + 1] %= MOD;
  }
}

typedef pair<int, int> pii;
vector<pii> tmp;

int ask(int x) {
  int ret = sums[x];
  repi(i, tmp) {
    int a = i->first, b = i->second;
    int c = 1;
    if (b < 0) {
      b = -b;
      c = -c;
    }

    if (a < x) {
      add(ret, (pref[x - b] - pref[a - b]) * c);
    }
  }
  return ret;
}

void go() {
  sort(tmp.begin(), tmp.end());
  int z = tmp.size();
  int pos = 0;

  int prv = 0;
  int cur = 0;
  int prf = 0;

  for(int i = 1; i <= N; ++i) {
    while (pos < z && tmp[pos].first == i) {
      int x = tmp[pos].second;
      int y = 1;
      if (x < 0) {
        x = -x;
        y = -y;
      }

      add(cur, fib[i - x] * y);
      if (i - x > 0) {
        add(prv, fib[i - x - 1] * y);
      }

      ++pos;
    }

    add(prf, cur);
    add(sums[i + 1], prf);

    int nxt = cur;
    add(nxt, prv);

    prv = cur;
    cur = nxt;
  }

  tmp.clear();
}

int main() {
  prec();

  scanf("%d %d", &N, &M);

  for(int i = 1; i <= N; ++i) {
    int x;
    scanf("%d", &x);
    sums[i + 1] = sums[i];
    add(sums[i + 1], x);
  }


  for(int i = 0; i < M; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    ++c;
    if (a == 1) {
      tmp.push_back(pii(b, b));
      tmp.push_back(pii(c, -b));
    } else {
      int ans = ask(c);
      add(ans,  -ask(b));
      printf("%d\n", ans);
    }

    if (tmp.size() > BLOCK) {
      go();
    }
  }

  return 0;
}