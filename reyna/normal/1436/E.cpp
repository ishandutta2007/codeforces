#include <bits/stdc++.h>

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long LL;
const int N = (int) 2e5 + 5, mod = (int) 0;
int seg[N << 2];
vector<int> all[N];
vector<pair<int, int>> query[N];
int mark[N];
int a[N], n;

void update(int pos, int x, int v = 1, int b = 0, int e = n+5) {
   if (b + 1 == e) {
      seg[v] = x;
      return;
   }
   int m = b + e >> 1, l = v << 1, r = l | 1;
   if (pos < m) {
      update(pos, x, l, b, m);
   } else {
      update(pos, x, r, m, e);
   }
   seg[v] = min(seg[l], seg[r]);
}
int get_query(int more, int v = 1, int b = 0, int e = n+5) {
   if (seg[v] >= more) return -1;
   if (b + 1 == e) return b;
   int m = b + e >> 1, l = v << 1, r = l | 1;
   int ansl = get_query(more, l, b, m);
   if (ansl != -1) return ansl;
   return get_query(more, r, m, e);
}
int main() {
   ios_base::sync_with_stdio(0);
   cin >> n;
   int all_zero = 1;
   for (int j = 0; j < n; ++j) {
      cin >> a[j];
      --a[j];
      all_zero &= (a[j] == 0);
      all[a[j]].push_back(j);
   }
   if (all_zero) {
      cout << 1 << endl;
      return 0;
   }
   mark[0] = 1;
   for (int i = 0; i < n + 5; ++i) {
      all[i].push_back(n);
      int last = 0;
      for (int pos : all[i]) {
         query[pos].push_back(make_pair(last, i));
         last = pos+1;
      }
   }
   for (int i = 0; i < n + 5; ++i) update(i, -1);
   for (int r = 0; r < n; ++r) {
      update(a[r], r);
      for (auto q : query[r+1]) {
         int l = q.first;
         
         int mex = get_query(l);
         if (mex == q.second) {
            mark[q.second] = 1;
         }
      }
   }
   int res = 0;
   while (mark[res]) ++res;
   cout << res+1 << endl;
}