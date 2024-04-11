#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const int N = (int)1e6 + 34;

vector<int> es[N];
int pr[N], sz[N];

int fnd(int v) {
  return (pr[v] == v ? v : pr[v] = fnd(pr[v]));
}

void merg(int v1, int v2) {
  v1 = fnd(v1);
  v2 = fnd(v2);
  if (sz[v1] > sz[v2]) 
    swap(v1, v2);
  pr[v1] = v2;
  sz[v2] += sz[v1];
}

ll getMax(const vector<int> &a) {  
  int n = a.size();
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    pr[i] = i;
    sz[i] = 1;    
    p.emplace_back(a[i], i);
  }
  sort(p.begin(), p.end());
  vector<bool> u(n, false);

  ll ans = 0;
  for (int ord = 0; ord < n; ord++) {
    int v = p[ord].second;
    u[v] = true;

    ll sum = 0, sum2 = 0;
    for (int w : es[v]) {
      if (!u[w]) continue;
      ll s = sz[fnd(w)];
      sum += s;
      sum2 += s * s;
    }

    for (int w : es[v]) {
      if (!u[w]) continue;
      merg(v, w);
    }    

    ans += (sum + (sum * sum - sum2) / 2) * a[v];
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;

  for (int i = 0; i < n; i++) es[i].clear();
  for (int i = 0; i < n - 1; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    es[v1].push_back(v2);
    es[v2].push_back(v1);
  }

  ll mx = getMax(a);
  for (int &x : a) x = -x;
  ll mn = -getMax(a);  

  //cout << mx << " " << mn << endl;

  cout << mx - mn << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;  

#ifdef SERT
  t = 1;
#endif

  for (int i = 0; i < t; i++)
    solve();
}