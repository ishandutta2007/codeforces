#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

ll ans;
int n, a[sz], b[sz], c[sz];
char s[sz], p[sz];

void mrg(int l, int m, int r) {
   int i = l, j = m + 1, k = 0;
   while(i <= m and j <= r) {
      if(a[i] < a[j]) c[k++] = a[i++];
      else c[k++] = a[j++], ans += m - i + 1;
   }
   while(i <= m) c[k++] = a[i++];
   while(j <= r) c[k++] = a[j++];
   for(int i=l, k=0; i<=r; i++, k++) a[i] = c[k];
}

void fnc(int l, int r) {
   if(l >= r) return;
   int m = l + r >> 1;
   fnc(l, m); fnc(m + 1, r);
   mrg(l, m, r);
}

map<char,queue<int>> mp;
map <char,int> cnt;

void go(vector <char> ara) {
   int i = 0;
   for(char &x : ara) {
      int c = cnt[x];
      while(c--) p[i++] = x;
   }
}

void solve() {
   scanf("%s", s);
   n = strlen(s);
   cnt.clear();
   for(int i=0; i<n; i++) cnt[s[i]]++;
   ll big = -1;
   vector <char> ara = {'A', 'N', 'O', 'T'}, who;
   do {
      go(ara);
      for(int i=0; i<n; i++) mp[s[i]].push(i);
      for(int i=0; i<n; i++) a[i] = mp[p[i]].front(), mp[p[i]].pop();
      ans = 0;
      fnc(0, n-1);
      if(ans > big) big = ans, who = ara;
   } while(next_permutation(ara.begin(), ara.end()));
   go(who);
   p[n] = 0; puts(p);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}