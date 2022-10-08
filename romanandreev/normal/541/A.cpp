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
const int maxn = (int)1e6;

const int sh = 1 << 19;
pair<int, int> rm[2 * sh + 10];
pair<int, int> get_rmq(int l, int r) {
  l += sh;
  r += sh;
  pair<int, int> res = rm[l];
  while (l <= r) {
    res = max(res, rm[l]);
    res = max(res, rm[r]);
    l = (l + 1) / 2;
    r = (r - 1) / 2;
  }
  return res;
}
int n, m;
int l[maxn];
vector<int> st, stl, str;
int r[maxn];
pair<int, pair<int, int> > ls[maxn];
void upd(int v, pair<int, int> x) {
  v += sh;
  rm[v] = x;
  while (v > 1) {    
    v /= 2;
    rm[v] = max(rm[v * 2], rm[v * 2 + 1]);
  }  
}

pair<int, int> inters(int i, int L, int R) {
  return mp(max(0, min(R, r[i]) - max(L, l[i])), i);
}
pair<int, int> get_ans(int L, int R) {
  int pl = upper_bound(all(stl), L) - stl.begin() - 1;
  int pr = lower_bound(all(str), R) - str.begin();
  pl = max(pl, 0);
  pr = min(pr, sz(str) - 1);
  pair<int, int> res = mp(0, -1);
  res = max(res, inters(st[pl], L, R));
  res = max(res, inters(st[pr], L, R));
  if (pl + 1 <= pr - 1) {
    res = max(res, get_rmq(pl + 1, pr - 1));
  }
  return res;  
}
int main(){
  #ifdef home
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  #endif
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    ls[i] = mp(l[i], mp(-r[i], i));
  }
  sort(ls, ls + n);
  pair<int, int> mx = mp(-1, -1);
  for (int i = 0; i < n; i++) {
    int id = ls[i].y.y;
    if (r[id] > mx.x) {
      mx = mp(r[id], id);
      st.pb(id);
      stl.pb(l[id]);
      str.pb(r[id]);
    }
  }
  for (int i = 0; i < sz(st); i++) {
    upd(i, mp(str[i] - stl[i], st[i]));
  }
  pair<ll, pair<int, int> > ans = mp((ll)0, mp(-1, -1));
  for (int i = 0; i < m; i++) {
    int l2, r2, c;
    scanf("%d %d %d", &l2, &r2, &c);
    pair<int, int> cur = get_ans(l2, r2);
    ans = max(ans, mp((ll)c * cur.x, mp(cur.y, i)));
  }
  cout << ans.x << endl;
  if (ans.x) {
    cout << ans.y.x + 1 << " " << ans.y.y + 1 << endl;
  }
  return 0;
}