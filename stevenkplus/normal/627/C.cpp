#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
const int MAXN = 200100;

vector<pii> ar;
int X[MAXN];
ll P[MAXN]; // loc, price
int Q[MAXN];
int D, C, N;

vector<int> cool;
int main() {
  cin >> D >> C >> N;

  // X[0] = P[0] = 0;
  for(int i = 0; i < N; ++i) {
    int x,  p;
    cin >> x >> p;
    ar.push_back(pii(x, p));
  }
  sort(ar.begin(), ar.end());

  for(int i = 0; i < N; ++i) {
    X[i + 1] = ar[i].first;
    P[i + 1] = ar[i].second;
    cool.push_back(X[i + 1]);
    cool.push_back(X[i + 1] + C);
  }
  cool.push_back(C);
  cool.push_back(D);
  sort(cool.begin(), cool.end());

  int ql = 0, qr = 1; // Q = [0]
  int nxt = 1;
  ll ans = 0;
  int prv = 0;
  for(int i = 0; i < cool.size(); ++i) {
    int cur = cool[i];
    while (ql < qr && X[Q[ql]] + C < cur) {
      ++ql;
    }
    if (ql == qr) {
      ans = -1;
      break;
    }

    ans += P[Q[ql]] * (cur - prv);
    prv = cur;

    if (cur == D) break;

    if (X[nxt] == cur) {
      while (ql < qr && P[Q[qr - 1]] >= P[nxt]) {
        --qr;
      }
      Q[qr] = nxt;
      ++qr;
      ++nxt;
    }
  }
  cout << ans << "\n";
}