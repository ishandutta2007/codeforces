#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 505;

int n, k, ans, dis[sz];
vector <int> st, ara;
bitset <sz> done;

void ask() {
   printf("?");
   for(int &x : ara) printf(" %d", x); puts("");
   fflush(stdout); ara.clear();
   int v;
   scanf("%d", &v);
   ans ^= v;
}

void go() {
   int u = st.size(), w = n, c = 0;
   if(!u) return;
   for(int i=0, j=u+k; i<=min(u, k); i++, j-=2) if(u + k - i <= n and dis[w] > dis[j]) w = j, c = i;
   done.reset();
   for(int x : st) done[x] = 1;
   for(int j=0; j<c; j++) ara.push_back(st.back()), st.pop_back();
   for(int i=1, j=0; j<k-c; i++) {
      if(done[i]) continue;
      st.push_back(i);
      ara.push_back(i); j++;
   }
   ask();
   go();
}

int main() {
   cin >> n >> k;
   queue <int> q; q.push(0);
   for(int i=1; i<=n; i++) dis[i] = sz;
   while(!q.empty()) {
      int u = q.front(), d = dis[u] + 1; q.pop();
      for(int i=0, j=u+k; i<=min(u, k); i++, j-=2) if(u + k - i <= n and d < dis[j]) {
         dis[j] = d;
         q.push(j);
      }
   }
   if(dis[n] < sz) {
      for(int i=1; i<=n; i++) st.push_back(i);
      go();
      printf("! %d\n", ans);
   }
   else puts("-1");
}