#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

typedef pair <int,int> pii;
#define x first
#define y second

pii a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   map <pii,int> mp;
   for(int i=0; i<n; i++) {
      scanf("%d", &a[i].x), a[i].y = i & 1;
      mp[a[i]]++;
   }
   sort(a, a+n);
   for(int i=0; i<n; i++) {
      a[i].y = i & 1;
      mp[a[i]]--;
   }
   for(auto it : mp) if(it.y) {
      puts("NO");
      return;
   }
   puts("YES");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}