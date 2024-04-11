#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef long double ld;

const ld B = 0.75;

const int N = 10111;
ld bp[N];

int main() {
  srand(time(nullptr));
  bp[0] = 1;
  for (int i = 1; i < N; ++i)
    bp[i] = bp[i - 1] * B;
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> errs(n, 0);
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;

    int me = *min_element(all(errs));
    ld w[2] = {0, 0};
    for (int j = 0; j < n; ++j) {
      w[s[j] - '0'] += bp[errs[j] - me];
    }
    cout << (rand() * 1. / RAND_MAX > (w[0] / (w[1] + w[0]))) << "\n";
    cout.flush();

    int c;
    cin >> c;
    for (int j = 0; j < n; ++j)
      if (s[j] != ('0' + c))
        ++errs[j];
  }
}