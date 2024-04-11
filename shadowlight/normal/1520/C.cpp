#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Tree {
  int t[100007];

  void up(int v, int val) {
    for (; v < 100007; v = (v | (v + 1))) t[v] += val;
  }

  int get(int v) {
    int res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1) res += t[v];
  }

  int get(int vl, int vr) {
    int ans = get(vr);
    if (vl) ans -= get(vl - 1);
    return ans;
  }
} tr; 


void solve() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << "-1\n";
    return;
  }

  vector <vector <int>> a(n, vector<int>(n));

  int now = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = now;
      now += 2;
      if (now >= n * n) {
        now = 1;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << a[i][j] + 1 << " ";
    }
    cout << "\n";
  }
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}