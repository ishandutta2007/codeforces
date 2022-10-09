#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define int int64_t

// Type aliases

using ll = long long;
using str = string;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using si = set<int>;

// Vector Operations

#define sz (int)(x).size()
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define del(x, i) erase(begin(x)+i)
#define rem(x,i) erase(begin(x), begin(x)+i)

// Pairs

#define mp make_pair
#define sec second
#define fir first

// Sets and Maps

#define ins insert
#define ez erase
#define cnt count

// Math

#define MAX_INT 1e18*9

// Loops

#define Trav(a,x) for (auto& a: x)
#define For(i,a,b) for (int i = (a); i < (b); ++i)
#define printv(v) cout << "["; for(int i =0;i<v.size();i++){ cout << v[i]; if(i!=v.size()-1){ cout << ", "; } } cout << "]" << endl;

// To check time of submission, put below line after reading input
// clock_t z = clock();
#define time_up cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

// __gcd(20, 60) for in-built GCD function

int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vii a(n, vi(n));
  int ans = 0;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    for(int j = 0; j < n; j++){
      a[i][j] = (int) s[j] - '0';
      //cout << "\t" << a[i][j] << "\n";
    }
  }
  if(n == 1) {cout << "0\n"; return;}
  int num1 = 0;
  for(int i = 0; i < (n + 1)/2; i++){
    for(int j = 0; j < n/2; j++){
      num1 = 0;
      if(a[i][j]) num1++;
      if(a[n-1-j][i]) num1++;
      if(a[n-1-i][n-1-j]) num1++;
      if(a[j][n-i-1]) num1++;
      ans += min(num1, 4 - num1);
    }
  }
  cout << ans << "\n";
}

int32_t main(){
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
}