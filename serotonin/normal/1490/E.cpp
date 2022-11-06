#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

typedef pair <ll,int> pii;
#define x first
#define y second

pii a[sz];
ll cum[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%lld", &a[i].x), a[i].y = i;
   sort(a+1, a+n+1);
   for(int i=1; i<=n; i++) cum[i] = cum[i-1] + a[i].x;
   vector <int> ans;
   ans.push_back(a[n].y);
   for(int i=n-1; i; i--) {
      if(cum[i] < a[i+1].x) break;
      ans.push_back(a[i].y);
   }
   printf("%d\n", ans.size());
   sort(ans.begin(), ans.end());
   for(int x : ans) printf("%d ", x);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}