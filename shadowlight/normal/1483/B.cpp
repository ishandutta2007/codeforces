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

void solve() {
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  set<int> pos;
  pos.insert(0);
  
  vector <int> order;

  bool deleted = false;
  for (int i = 1; i < n; ++i) {
    if (deleted) {
      deleted = false;
      pos.insert(i);
    } else if (__gcd(a[*pos.rbegin()], a[i]) == 1) {
      deleted = true;
      order.pb(i);
    } else {
      pos.insert(i);
    }
  }
  if (!deleted && __gcd(a[*pos.rbegin()], a[*pos.begin()]) == 1) {
    order.pb(0);
    pos.erase(pos.begin());
  }

  set <int> badq;
  int pr = -1;
  for (int val : pos) {
    if (pr != -1 && __gcd(a[pr], a[val]) == 1) {
      badq.insert(pr);
    }
    pr = val;
  }

  if (pos.size() && __gcd(a[pr], a[*pos.begin()]) == 1) {
    badq.insert(pr);
  }

  int now = -1;

  while (badq.size()) {
    auto it = badq.upper_bound(now);
    int val = -1;
    if (it == badq.end()) {
      val = *badq.begin();
    } else {
      val = *it;
    }
    int nxt = -1;
    auto itt = pos.upper_bound(val);
    if (itt == pos.end()) {
      nxt = *pos.begin();
    } else {
      nxt = *itt;
    }
    //cout << val << " " << nxt << endl;
    assert(__gcd(a[val], a[nxt]) == 1);

    order.pb(nxt);
    badq.erase(val);
    badq.erase(nxt);
    pos.erase(nxt);

    if (!pos.size()) break;
    
    int nxt1 = -1;
    auto it1 = pos.upper_bound(nxt);
    if (it1 == pos.end()) {
      nxt1 = *pos.begin();
    } else {
      nxt1 = *it1;
    }

    if (__gcd(a[val], a[nxt1]) == 1) {
      //cout << "INSERTED" << endl;
      badq.insert(val);
    }
    now = nxt;
  }

  cout << order.size() << " ";
  for (int x : order) {
    cout << x + 1 << " ";
  }
  cout << "\n";

}



int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}