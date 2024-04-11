#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define printArr(arr, n) forn(i, n){if (i) cout << " "; cout << arr[i];} cout << endl;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}
void file_io(string taskname){
   string fin = taskname + ".in";
   string fout = taskname + ".out";
   const char* FIN = fin.c_str();
   const char* FOUT = fout.c_str();
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
   fast_io();
}

#define MAXN 100005

int sm[MAXN], par[MAXN];
double ans[MAXN];
vector<int> adj[MAXN];

void dfs1(int v) {
  for (int u : adj[v]) {
    dfs1(u);
    sm[v] += sm[u];
  }
  sm[v]++;
}

void dfs2(int v) {
  if (v == 0)
    ans[v] = 1;
  else
    ans[v] = (double) (sm[par[v]] - sm[v] - 1) / 2 + ans[par[v]] + 1;
  for (int u : adj[v]) {
    dfs2(u);
  }
}

int main(){
    fast_io();

    memset(sm, 0, sizeof(sm));

    int n;
    cin >> n;
    for (int i=1; i<n; i++) {
      int x;
      cin >> x;
      x--;
      par[i] = x;
      adj[x].pb(i);
    }

    dfs1(0);
    dfs2(0);

    for (int i=0; i<n; i++)
      cout << ans[i] << "\n";
}