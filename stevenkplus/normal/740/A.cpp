// Codeforces Template by Steven Hao

#include <cstdio>
#include <vector>
#include <queue>
#include <complex>
#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;

// ==============================
// Debug helpers

// Uncomment this line to turn debugging on
// #define DEBUG

#ifdef DEBUG
#define RED_COLOR "\033[1;31m"
#define DEFAULT_COLOR "\033[1;39m"
// print to stdout to avoid stdoutout/stderr mixing
#define RED(x) do { cout << RED_COLOR; x; cout << DEFAULT_COLOR; } while(0)
#define P(x) RED(cout << #x << " " << x << "\n") // advanced printing
#define Q(x) RED(cout << x << "\n") // macro for "print"
#define PP(...) RED(fprintf (stdout, __VA_ARGS__)) // macro for printf
#define WHEN_DEBUG(x) x
#else
#define P(x)
#define Q(x)
#define PP(...)
#define WHEN_DEBUG(x)
#endif

// ==============================
// Data Structures

// (todo)

// ==============================
// Common algos

// TODO: BFS
// TODO: Dijkstra
// TODO: GCD
// TODO: ceildivision

// TODO: geometry templates


// ==============================
// Typedefs, macros, constants

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef long long ll;
typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;
const int inf = 1000 << 20;
const ll infl = ll(inf) << 30; // slightly more than 10^18
const int MOD = 1E9 + 7;

// customizable params

const int MAXN = 100100;

int ar[MAXN];
//pii ar[MAXN];

int N, M, K; // have these vars readily available
int P, Q;
ll A, B, C; // these too if necessary
ll ans;

// Main entry point
int main() {
  scanf("%d", &N);
  cin >> A >> B >> C;

  ans = infl;
  for(int i = 0; i < 4; ++i) {
    for(int j = 0; j < 4; ++j) {
      for(int k = 0; k < 4; ++k) {
        int buy = N + i + j * 2 + k * 3;
        ll cost = A * i + B * j + C * k;
        if (buy % 4 == 0) {
          if (cost < ans) ans = cost;
        }
      }
    }
  }

  cout << ans << "\n";
}