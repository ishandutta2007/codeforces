#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

typedef pair <int,int> pii;
#define x first
#define y second

priority_queue <pii> pq;
bitset <sz> done;
int a[sz];

int main() {
   int q, n = 0, k = 1;
   cin >> q;
   while(q--) {
      int t;
      scanf("%d", &t);
      if(t == 1) {
         n++;
         scanf("%d", &a[n]);
         pq.emplace(a[n], -n);
      }
      else if(t == 2) {
         while(done[k]) k++;
         done[k] = 1;
         printf("%d ", k);
         k++;
      }
      else {
         while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int i = -p.y;
            if(done[i]) continue;
            done[i] = 1;
            printf("%d ", i);
            break;
         }
      }
   }
}