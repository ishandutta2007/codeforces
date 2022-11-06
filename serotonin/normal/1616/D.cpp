#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz], upto[sz], dp[sz];
pair <ll,int> p[sz];
ll cum[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   int x;
   scanf("%d", &x);

   for(int i=1; i<=n; i++) cum[i] = a[i] - x;
   for(int i=1; i<=n; i++) cum[i] += cum[i-1];
   for(int i=1; i<=n; i++) p[i] = {cum[i], i};

   vector <pair<ll,int>> quer;
   for(int i=1; i<=n; i++) quer.emplace_back(cum[i-1], i);
   sort(quer.begin(), quer.end());

   set <int> st;
   sort(p + 1, p + n + 1);
   int i = 1;
   for(auto [l, j] : quer) {
      while(i <= n and p[i].first < l) st.insert(p[i].second), i++;
      auto it = st.upper_bound(j);
      if(it == st.end()) upto[j] = n;
      else upto[j] = *it - 1;
   }

   // for(int i=1; i<=n; i++) printf("%d ", upto[i]); puts("");

   for(int i=n-1; i; i--) upto[i] = min(upto[i], upto[i+1]);

   dp[n + 1] = dp[n + 2] = 0;
   priority_queue <pair<int,int>> pq;
   for(int i=n; i; i--) {
      dp[i] = 1 + dp[i + 2];
      while(!pq.empty() and pq.top().second > upto[i]) pq.pop();
      if(!pq.empty()) {
         int j = pq.top().second;
         dp[i] = max(dp[i], j - i + 1 + dp[j + 2]);
      }
      pq.emplace(dp[i + 2] + i, i);
   }
   printf("%d\n", *max_element(dp + 1, dp + n + 1));
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}