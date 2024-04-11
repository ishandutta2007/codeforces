#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pp pair<pii, int>
#define mp make_pair
using ll = long long;
const int maxn = 500010;
int n, q;

const ll inf = 10000000000000000LL;

ll seg[maxn*4];
ll lazy[maxn*4];
int en[maxn];
ll dep[maxn];
int par[maxn];
ll we[maxn]; //weight down to me
vector<int> ch[maxn];

void buildseg(int ss = 1, int se = n, int si = 0) {
  if (ss == se) {
    if (ch[ss].size() == 0) {
      seg[si] = dep[ss];
    }
    else seg[si] = inf;
    return;
  }
  int mid = (ss+se)/2;
  buildseg(ss, mid, si*2+1);
  buildseg(mid+1, se, si*2+2);
  seg[si] = min(seg[si*2+1], seg[si*2+2]);
}

void delaze(int ss, int se, int si) {
  if (lazy[si] == 0) return;
  seg[si] += lazy[si];
  if (ss != se) {
    lazy[si*2+1]+=lazy[si];
    lazy[si*2+2]+=lazy[si];
  }
  lazy[si] = 0;
}

ll query(int qs, int qe, int ss = 1, int se = n, int si = 0) {
  delaze(ss, se, si);
  if (qs > qe || ss > se || qs > se || qe < ss) return inf;
  if (qs <= ss && se <= qe) return seg[si];

  int mid = (ss+se)/2;
  return min(query(qs, qe, ss, mid, si*2+1),
    query(qs, qe, mid+1, se, si*2+2));

}

void update(int us, int ue, ll diff, int ss = 1, int se = n, int si = 0) {

  // if (si == 0) {
    // cout << " doing " << us << " to " << ue << ": " << diff << endl;
  // }

  if  (us > ue || ss > se || us > se || ue < ss) return;
  delaze(ss, se, si);
  if (us <= ss && se <= ue) {
    lazy[si] += diff;
    delaze(ss, se, si);
    return;
  }
  int mid = (ss+se)/2;
  update(us, ue, diff, ss, mid, si*2+1);
  update(us, ue, diff, mid+1, se, si*2+2);
  seg[si] = min(seg[si*2+1], seg[si*2+2]);
}

void dfs(int u, ll cl) {
  dep[u] = cl;
  en[u] = u;
  for (int v : ch[u]) {
    dfs(v, cl + we[v]);
    en[u] = max(en[u], en[v]);
  }
}

vector<pp> qu[maxn];
ll ans[maxn];

void calc(int u) {
  //calculate down the chain
  // cout << "on: " << u << endl;

  for (pp vp : qu[u]) {
    ans[vp.second] = query(vp.first.first, vp.first.second);
    // cout << u << " -- " << ans[vp.second] << endl;
  }

  for (int v : ch[u]) {

    // cout << v << " .............." << endl;

    update(v, en[v], -we[v]);
    update(1, v-1, we[v]);
    update(en[v]+1, n, we[v]);
    calc(v);
    update(v, en[v], we[v]);
    update(1, v-1, -we[v]);
    update(en[v]+1, n, -we[v]);

  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    cin >> par[i] >> we[i];
    ch[par[i]].push_back(i);
  }
  dfs(1, 0);
  buildseg();

  int v, l, r;
  for (int i = 1; i <= q; i++) {
    cin >> v >> l >> r;
    qu[v].push_back(mp(mp(l, r), i));
  }
  calc(1);
  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }
  cout.flush();

}