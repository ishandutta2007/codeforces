#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a:x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define f first
#define s second
#define nl "\n"
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int MOD=1e9+7;
template<class T> using pqg=priority_queue<T, vector<T>, greater<T>>;

int n;
string s;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);

  cin >> n >> s;
  rep(i, 1, n){
    if(n%i==0){
      reverse(s.begin(), s.begin()+i);
    }
  }
  cout << s;
}