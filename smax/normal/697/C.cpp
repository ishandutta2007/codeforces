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


int main(){
    fast_io();
    int q;
    cin >> q;
    unordered_map<ll, ll> map;

    forn (i, q){
      ll type, u, v;
      cin >> type >> u >> v;
      if(type == 1){
        int w;
        cin >> w;
        if(u > v){
          swap(u, v);
        }
        while(1LL<<(63-__builtin_clzll(v)) > u){
          map[v] += w;
          v /= 2;
        }
        while(u != v){
          map[v] += w;
          map[u] += w;
          u /= 2;
          v /= 2;
        }
        //map[v] += w;

      }else if(type == 2){
        ll tot = 0;
        if(u > v){
          swap(u, v);
        }
        while(1LL<<(63-__builtin_clzll(v)) > u){
          tot += map[v];
          v /= 2;
        }
        while(u != v){
          tot += map[v];
          tot += map[u];
          u /= 2;
          v /= 2;
        }
        //tot += map[v];
        cout << tot << endl;
      }
    }
}