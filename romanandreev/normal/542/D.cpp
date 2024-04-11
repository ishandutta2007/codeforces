#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
ll A;
vector<pair<ll, int> > ls;
vector<ll> M2[100000];
vector<ll> ls2;
ll my_stp(ll x, int stp) {
  if (stp == 0) {
    return 1ll;
  }
  ll res = my_stp(x, stp / 2);
  res = res * res;
  if (stp & 1) {
    res = res * x;
  }
  return res;
}
inline pair<bool, ll> sqrtn(ll x, int stp) {
  ll t = (ll)pow((ld)x, (ld)1 / stp);
  for (ll k = max(2ll, t - 1); k <= t + 1; k++) {
    if (my_stp(k, stp) == x) {
      return mp(true, k);
    }
  }
  return mp(false, 0ll);
}
inline bool is_prime(ll x) {
  for (ll i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
void obr(ll term, int id) {
  for (int i = 1; (1ll << i) <= term - 1; i++) {
    pair<bool, ll> sq = sqrtn(term - 1, i);
    if (sq.x && is_prime(sq.y)) {
      ls2.pb(sq.y);
      M2[id].pb(sq.y);
      break;
    }
  }
}
vector<ll> ls3;
void bct(int k, ll mul, int id) {
  if (k == sz(ls)) {
    obr(mul, id);
    ls3[id] = mul;
    return;
  }
  for (int j = 0; j <= ls[k].y; j++) {
    bct(k + 1, mul, id * (ls[k].y + 1) + j);
    mul *= ls[k].x;
  }
}
vector<pair<int, int> > G[100000];
void bct2(int k, int mul1, int mul2) {
  if (k == sz(ls)) {
    if (mul2 != mul1)    
      G[mul1].pb(mp(mul2 - mul1, mul2));
    return;
  }
  for (int j = 0; j <= ls[k].y; j++) {
    for (int j1 = j; j1 <= ls[k].y; j1++) {
      bct2(k + 1, mul1 * (ls[k].y + 1) + j, mul2 * (ls[k].y + 1) + j1);
    }
  }
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  cin >> A;
  ll cur = A;
  for (ll i = 2; i * i <= cur; i++) {
    int cnt = 0;
    while (cur % i == 0) {
      cnt++;
      cur /= i;
    }
    if (cnt) {
      ls.pb(mp(i, cnt));
    }
  }
  if (cur > 1) {
    ls.pb(mp(cur, 1));
  }
  int szls3 = 1;
  for (auto x : ls) {
    szls3 *= (x.y + 1);
  }
  ls3.resize(szls3);
  bct(0, (ll)1, 0);
//  cerr<<clock() * 1. / CLOCKS_PER_SEC<<endl;
  image(ls2);  
  bct2(0, 0, 0);
//  cerr<<clock() * 1. / CLOCKS_PER_SEC<<endl;
  vector<vector<int> > DP(sz(ls3), vector<int>(sz(ls2) + 1, 0));
  DP[0][0] = 1;
  for (int x = 0; x < sz(ls3); x++) {
    for (auto& y : M2[x]) {
      y = lower_bound(all(ls2), y) - ls2.begin();
    }
  }
  for (int i = 0; i < sz(ls3); i++) {
    for (int j = 0; j < sz(ls2); j++) {
      DP[i][j + 1] += DP[i][j];
    }
    for (auto x : G[i]) {
      for (int y : M2[x.x]) {
        DP[x.y][y + 1] += DP[i][y];
      }
    }    
  }
  cout << DP[sz(ls3) - 1][sz(ls2)] << endl;
//  cerr<<clock() * 1. / CLOCKS_PER_SEC<<endl;
  return 0;
}