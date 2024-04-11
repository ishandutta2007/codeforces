#include <bits/stdc++.h>
 
using namespace std;
 
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second
 
#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
 
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
const ll inf = 1e12;
const ll mod = 1e9 + 7;
 
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
 
vector<int> adj[200000];
int dist[200000];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
      adj[i].clear();
    for (int i=0; i<m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u-1].push_back(v-1);
      adj[v-1].push_back(u-1);
    }

    memset(dist, -1, sizeof(int) * n);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();

      // do something with u

      for (int v : adj[u])
        if (dist[v] == -1) {
          q.push(v);
          dist[v] = dist[u] + 1;
        }
    }

    vector<int> odd, even;
    for (int i=0; i<n; i++) {
      if (dist[i] % 2)
        odd.push_back(i + 1);
      else
        even.push_back(i + 1);
    }

    if (odd.size() > even.size()) {
      cout << even.size() << "\n";
      ao(even, even.size());
    } else {
      cout << odd.size() << "\n";
      ao(odd, odd.size());
    }
  }
}