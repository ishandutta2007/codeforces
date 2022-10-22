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



int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector <vector<int>> xs(k, vector<int>(n));
  vector <ll> sums, sums2;

  for (int i = 0; i < k; ++i) {
    ll sum = 0;
    ll sum2 = 0;
    for (int j = 0; j < n; ++j) {
      cin >> xs[i][j];
      sum += xs[i][j];
      sum2 += xs[i][j] * (ll) xs[i][j];
    }
    sums.pb(sum);
    sums2.pb(sum2);
  }

  int y = -1;
  vector <ll> deltas;
  ll delta = -1;
  for (int i = 1; i < k; ++i) {
    deltas.pb(sums[i] - sums[i - 1]);
    if (deltas.size() >= 2 && deltas.back() == deltas[deltas.size() - 2]) {
      delta = deltas.back();
    }
  }


  for (int i = 1; i < k; ++i) {
    if (delta != deltas[i - 1]) {
      y = i;
      break;
    }
  }

  ll sumv2 = 0;

  for (int i = 0; i < k; ++i) {
    if (i <= y && y < i + 3) continue;

    ll a = sums2[i], b = sums2[i + 1], c = sums2[i + 2];

    ll tet = a + c - 2 * b;
    sumv2 = tet / 2;
    break;
  }
  ll add = 2 * sums[y] - sums[y - 1] - sums[y + 1];
  add = -add / 2;

  sums[y] += add;
  for (int i = 0; i < n; ++i) {
    ll was = sums2[y];
    sums2[y] -= xs[y][i] * (ll) xs[y][i];

    xs[y][i] += add;
    sums2[y] += xs[y][i] * (ll) xs[y][i];
    
    ll diff = sums2[y - 1] + sums2[y + 1] - 2 * sums2[y];
    //cout << sums2[y - 1] << " " << sums2[y + 1] << " " << sums2[y] << endl;
    if (diff == 2 * sumv2) {
      cout << y << " " << xs[y][i] << endl;
      return 0;
    }

    xs[y][i] -= add;
    sums2[y] = was;
  }
  assert(false);
}