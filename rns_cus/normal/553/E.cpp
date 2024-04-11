#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <complex>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ROF(i,a,b) for(int i=(b)-1;i>=a;i--)
#define ALL(v) v.begin(),v.end()
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<double, double> pdd;
typedef pair<string, string> pss;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vii;
typedef vector<double> vd;
typedef vector<pii> vpii;
const int INF = 1000000000;
const LL INFL = 1000000000000000000;

int chk[55];
typedef std::complex<double> cmplx;

const double pi = atan2(0, -1);

class FFT {
public:
  FFT(int n);

  void forward(vector<cmplx>& data) {
    compute(data, roots_);
  }
  void reverse(vector<cmplx>& data) {
    compute(data, inv_roots_);
    for (int i = 0; i < n_; i++) {
      data[i] /= n_;
    }
  }

private:
  int n_, p_;
  vector<int> reversed_bits_;
  cmplx roots_[20];
  cmplx inv_roots_[20];
  void compute(vector<cmplx>& data, cmplx* roots);
};

FFT::FFT(int n)
  : n_(n)
  , reversed_bits_(n)
  , p_(0)
{
  while ((1 << p_) < n_) ++p_;

  for (int num = 0; num < n; ++num) {
    int original = num;
    int reversed = 0;
    for (int k = 0; k < p_; ++k) {
      reversed = (reversed << 1) | (original & 1);
      original >>= 1;
    }
    reversed_bits_[num] = reversed;
  }

  for (int order = 0; order < p_; ++order) {
    double angle = 2 * pi / (1 << (order + 1));
    inv_roots_[order] = cmplx(cos(angle), sin(angle));
    roots_[order] = std::conj(inv_roots_[order]);
  }
}

void FFT::compute(vector<cmplx>& data, cmplx* roots) {
  for (int i = 0; i < n_; ++i) {
    if (reversed_bits_[i] > i) {
      swap(data[i], data[reversed_bits_[i]]);
    }
  }

  for (int len = 2; len <= n_; len <<= 1) {
    cmplx root = *roots++;
    for (int i = 0; i < n_; i += len) {
      cmplx w(1, 0);
      for (int j = 0; j < len / 2; ++j) {
        cmplx u = data[i + j];
        cmplx v = data[i + j + len / 2] * w;
        data[i + j] = u + v;
        data[i + j + len / 2] = u - v;
        w *= root;
      }
    }
  }
}

const int MT = 65536;

struct Route {
  int to;
  int cost;
  vector<cmplx> time;
  Route() {
    time.resize(MT);
  }
};
vector<Route> ve[64];
double res[MT][64];

FFT fft(MT);

int cost[64][64];

int q[100000], qr, ql;

int main() {
  int n, m, T, Fine;
  scanf("%d%d%d%d", &n, &m, &T, &Fine);
  FOR(i, 0, n) FOR(j, 0, n) cost[i][j] = INF;
  FOR(i, 0, n) cost[i][i] = 0;
  FOR(i, 0, m) {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    --a, --b;
    cost[a][b] = min(cost[a][b], c);
    ve[a].emplace_back();
    Route& r = ve[a].back();
    r.to = b;
    r.cost = c;
    FOR(t, 1, T + 1) {
      int p; scanf("%d", &p);
      r.time[T - t].real(p * 0.00001);
    }
  }
  FOR(k, 0, n) FOR(i, 0, n) FOR(j, 0, n) cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
  FOR(t, 0, MT) FOR(i, 0, n) res[t][i] = cost[i][n - 1] + Fine;
  FOR(t, 0, T + 1) res[t][n - 1] = 0;
  FOR(i, 0, n) for (auto& e : ve[i]) {
    fft.forward(e.time);
  }
  vector<cmplx> cur;
  set<int> upd;
  upd.insert(n - 1);
ql = qr = 0;
chk[n-1] = 1;
q[++qr] = n - 1;
  while (ql < qr) {
    int x = q[++ql];
    chk[x] = 0;
    vector<cmplx> cd(MT);
    FOR(t, 0, MT) cd[t].real(res[t][x]);
    fft.forward(cd);
    FOR(i, 0, n) for (auto& e : ve[i]) {
      if (e.to != x) continue;
      vector<cmplx> cur(MT);
      FOR(t, 0, MT) cur[t] = cd[t] * e.time[t];
      fft.reverse(cur);
      FOR(t, 0, T) {
        double val = cur[T + t].real() + e.cost;
        if (val < res[t][i] - 1e-9) {
          res[t][i] = val;
          if (!chk[i]) {
			chk[i] = 1;
			q[++qr] = i;
          }
        }
      }
    }
  }
  printf("%.9lf", res[0][0]);
  return 0;
}