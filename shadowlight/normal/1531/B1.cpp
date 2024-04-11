#include <bits/stdc++.h>
#define ll long long
#define db double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;

int main(){
#ifdef LOCAL
	freopen("J_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  
  map <int, int> cnt;
  map <pair<int, int>, int> cntp;
  
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    ++cnt[x];
    if (y != x) {
        ++cnt[y];
        ++cntp[{x, y}];
    }
  }
  
  ll res = 0;
  for (auto t : cnt) {
      res += t.y * (ll) (t.y - 1) / 2;
  }
  for (auto t : cntp) {
      res -= t.y * (ll) (t.y - 1) / 2;
  }
  cout << res << "\n";
}