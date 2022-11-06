#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

void solve() {
   int n;
   cin >> n;
   for(int i=0; i<2*n; i++) scanf("%d", &a[i]);

   queue <int> q;
   for(int i=0; i<2*n; i++) {
      if(q.empty() || q.front() ^ a[i]) {
         printf("%d ", a[i]);
         q.push(a[i]);
      }
      else q.pop();
   }
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}