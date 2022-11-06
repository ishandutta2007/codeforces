#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 6e5+5;

char s[sz];
int dep[sz];
ll partner[sz];
vector <int> g[sz];

int main() {
   int n, q;
   cin >> n >> q;
   scanf("%s", s + 1);
   for(int i=1, j=n; i<=n; i++) {
      dep[i] = j;
      g[j].push_back(i);
      if(s[i] == '(') j++;
      else j--;
      if(g[j].empty() or s[i] == '(') continue;
      int l = g[j].back(), d = j + 1;
      ll up = g[d].end() - lower_bound(g[d].begin(), g[d].end(), l) - 1;
      partner[l] = 1 + up * (up - 1) / 2;
   }

   for(int i=1; i<=n; i++) partner[i] += partner[i-1];

   while(q--) {
      int t, l, r;
      scanf("%d %d %d", &t, &l, &r);
      ll ans = partner[r] - partner[l - 1];
      int d = dep[l];
      ll cnt = upper_bound(g[d].begin(), g[d].end(), r) - lower_bound(g[d].begin(), g[d].end(), l);
      ans += cnt * (cnt - 1) / 2;
      printf("%lld\n", ans);
   }
}