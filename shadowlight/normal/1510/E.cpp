#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
 
db eps = 1e-7;
 
int cmp(const db &a, const db &b) {
 
  if (abs(a-b) < eps) return 1;
  if (a < b) return 0;
  return 2;
 
}
 
struct lex_compare {
    bool operator() (const tuple<int, db, db>& lhs, const tuple<int, db, db>& rhs) const {
        int A = cmp(get<0>(lhs), get<0>(rhs));
        int B = cmp(get<1>(lhs), get<1>(rhs));
        int C = cmp(get<2>(lhs), get<2>(rhs));
        if (A == 0) return true;
        if (A == 2) return false;
 
        if (B == 0) return true;
        if (B == 2) return false;
 
        if (C == 0) return true;
        return false;
    }
};
 
map<tuple<int, db, db>, string, lex_compare> mm;
 
void upd(db &dx, db &dy, int py, int cy, int px, db x, db y) {
 
  if (py < 0 || cy < 0) return;
/////////////////////////////////////////////////////////////////////// X CALC
  
  int xx = 3*min(py, cy) * (2*px + 1);
  if (py < cy) xx += px + 2*(px+1);
  else xx += 2*px + (px + 1);
 
  int yy = 3*min(py, cy) + 3 * min(py, cy) * (min(py, cy) - 1);
  if (py < cy) yy += 3*min(py, cy) + 1;
  else yy += 3*min(py, cy) + 1;
 
  int cnt = 2*min(py, cy) + 1;
  db A = (db) xx - (db) cnt * 3. * x;
  db B = (db) yy - (db) cnt * 3. * y;
 
  dx += A;
  dy += B;
 
 
 
 
}
 
int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
  int n;
  cin >> n;
 
  db s, y;
  cin >> s >> y;
 
  for (int mask = 0; mask < (1<<(n/2)); ++mask) {
    string W = "";
    for (int i = 0; i < (n/2); ++i) {
      if ((1<<i)&mask) W += '(';
      else W += ')';
    }
 
    bool can = true;
    int bal = 0;
 
    reverse(all(W));
    db dx = 0, dy = 0;
 
    int u = n;
 
    for (auto x : W) {
 
      u--;
 
      int old_bal = bal;
 
      if (x == ')') bal++;
      else bal--;
      if (bal < 0) can = false;
      upd(dx, dy, bal, old_bal, u, s, y);
    }
 
    if (!can) continue;
 
    reverse(all(W));
   //if (bal == 14) cout << W << " " << dx << " " << dy << " " << bal << endl;
    mm[make_tuple(bal, -dx, -dy)] = W;
 
  }
 
  for (int mask = 0; mask < (1<<(n/2)); ++mask) {
    string W = "";
    for (int i = 0; i < (n/2); ++i) {
      if ((1<<i)&mask) W += '(';
      else W += ')';
    }
 
    bool can = true;
    int bal = 0;
 
    db dx = 0, dy = 0;
 
    int u = -1;
 
    for (auto x : W) {
 
      u++;
 
      int old_bal = bal;
 
      if (x == '(') bal++;
      else bal--;
      if (bal < 0) can = false;
         //if (bal == 14) cout << W << " " << dx << " " << dy << " " << bal << endl;
 
      upd(dx, dy, old_bal, bal, u, s, y);
    }
 
    if (!can) continue;
 
   // cout << W << " " << dx << " " << dy << " " << bal << endl;
 
    if (mm.count(make_tuple(bal, dx, dy))) {
      W += mm[make_tuple(bal, dx, dy)];
      cout << W;
 
      exit(0);
    }
  }
 
  assert(0);
}