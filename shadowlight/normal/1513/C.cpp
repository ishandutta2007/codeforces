#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

const int N = 2e5 + 7;

vector<int> counts[N][10];
int lens[N][10];

void init() {
  for (int i = 0; i < 10; ++i) {
    vector <int> cnt(10, 0);
    if (i < 9) {
      cnt[i + 1] = 1;
      lens[1][i] = 1;
    } else {
      cnt[0] = cnt[1] = 1;
      lens[1][i] = 2;
    }
    counts[1][i] = cnt;
  }

  for (int i = 2; i < N; ++i) {
    for (int j = 0; j < 10; ++j) {
      counts[i][j].resize(10, 0);
      auto cnt = counts[i - 1][j];
      for (int k = 0; k < 10; ++k) {
        if (k < 9) {
          add(counts[i][j][k + 1], cnt[k]);
        } else {
          add(counts[i][j][1], cnt[k]);
          add(counts[i][j][0], cnt[k]);
        }
      }
      for (int k = 0; k < 10; ++k) {
        add(lens[i][j], counts[i][j][k]);
      }
    }
  }
}


void solve() {
  int n, m;
  cin >> n >> m;

  vector <int> counts(10, 0);

  do {
    counts[n % 10] += 1;
    n /= 10;
  } while (n);

  auto cnt = lens[m];
  int res = 0;
  for (int i = 0; i < 10; ++i) {
    add(res, cnt[i] * (ll) counts[i] % mod);
  }
  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  init();

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}