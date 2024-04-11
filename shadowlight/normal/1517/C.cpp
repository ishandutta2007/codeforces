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

  int n;
  cin >> n;

  vector <int> b(n);
  vector <vector <int>> a(n, vector<int>(n, 0));
  vector <int> counts(n, 0);
  iota(all(counts), 0);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    int c = x;
    int posx = i, posy = i; 
    while (x) {
      assert(counts[posx] <= posy);
      a[posy][posx] = c;
      --x;
      ++counts[posx];
      if (posx && counts[posx] > counts[posx - 1]) {
        assert(counts[posx] == counts[posx - 1] + 1);
        --posx;
        continue;
      }
      if (counts[posx] < n) {
        ++posy;
      } else {
        ++posx;
        posy = counts[posx];
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }

}