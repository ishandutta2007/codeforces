#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

typedef pair <int,int> pii;
#define x first
#define y second

int m, stk[sz], k, ans[sz];
pii a[sz];
char s[5];

void fnc(vector <pii> odd) {
   k = 0;
   sort(odd.begin(), odd.end());
   for(auto &[x, i] : odd) {
      if(!k) stk[++k] = i;
      else {
         int j = stk[k];
         if(a[j].y and !a[i].y) {
            k--;
            ans[j] = ans[i] = (a[i].x - a[j].x) / 2;
         }
         else stk[++k] = i;
      }
   }
   int l = 1;
   while(l + 1 <= k) {
      int i = stk[l], j = stk[l + 1];
      if(!a[i].y and !a[j].y) {
         ans[i] = ans[j] = (a[j].x - a[i].x) / 2 + a[i].x;
         l += 2;
      }
      else break;
   }
   int r = k;
   while(r - 1 >= 1) {
      int i = stk[r - 1], j = stk[r];
      if(a[i].y and a[j].y) {
         ans[i] = ans[j] = (a[j].x - a[i].x) / 2 + m - a[j].x;
         r -= 2;
      }
      else break;
   }
   if(l < r) {
      int i = stk[l], j = stk[r];
      ans[i] = ans[j] = (a[i].x - a[j].x) / 2 + m;
   }
}

void solve() {
   int n;
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) scanf("%d", &a[i].x), ans[i] = -1;
   for(int i=0; i<n; i++) scanf("%s", s), a[i].y = s[0] == 'R';
   vector <pii> odd, eve;
   for(int i=0; i<n; i++) {
      if(a[i].x & 1) odd.emplace_back(a[i].x, i);
      else eve.emplace_back(a[i].x, i);
   }
   fnc(odd); fnc(eve);
   for(int i=0; i<n; i++) printf("%d ", ans[i]);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}