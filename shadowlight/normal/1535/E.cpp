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
 
const int N = 3e5 + 7;
const int LOGN = 30;
 
int binup[N][LOGN];
int a[N];
int c[N];
int h[N];
 
int up(int v, int d) {
  for (int i = 0; i < LOGN; ++i) {
    if (d & (1 << i)) {
      v = binup[v][i];
    }
  }
  return v;
}
 
int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
  int q;
  int n = 1;
  cin >> q >> a[0] >> c[0];
 
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < LOGN; ++j) {
      binup[i][j] = -1;
    }
  }
 
  for (int i = 0; i < q; ++i) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int p;
      n = i + 1;
      cin >> p >> a[n] >> c[n];
      
      h[n] = h[p] + 1;
 
      binup[n][0] = p;
      for (int i = 1; i < LOGN; ++i) {
        if (binup[n][i - 1] == -1) break;
        binup[n][i] = binup[binup[n][i - 1]][i - 1];
      }
    } else {
      int v, w;
      cin >> v >> w;
      int p = v;
      for (int d = LOGN - 1; d >= 0; --d) {
        if (binup[p][d] == -1 || !a[binup[p][d]]) continue;
        p = binup[p][d];
      }
      
      ll bought = 0, price = 0;
 
      while (w) {
        //cout << "PRED: " << p << " " << a[p] << " " << c[p] << endl;
        int t = min(w, a[p]);
        w -= t;
        a[p] -= t;
        bought += t;
        price += t * (ll) c[p];
 
        if (p == v) break;
        p = up(v, h[v] - h[p] - 1);
      }
      cout << bought << " " << price << endl;
    }
  }
 
}