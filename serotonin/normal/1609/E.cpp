#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int n;
char s[sz];

struct node {
   int a = 0, b = 0, c = 0;
   int ab = 0, bc = 0, ac = 0, abc = 0;

   node operator + (const node &oth) const {
      node res;
      res.a = a + oth.a;
      res.b = b + oth.b;
      res.c = c + oth.c;

      res.ab = min(res.a, res.b);
      res.bc = min(res.b, res.c);
      res.ac = min(res.a, res.c);

      res.ab = min({a + oth.ab, ab + oth.b, a + oth.b});
      res.bc = min({b + oth.bc, bc + oth.c, b + oth.c});
      res.ac = min({a + oth.ac, ac + oth.c, a + oth.c});

      res.abc = min({res.a, res.b, res.c});
      res.abc = min({res.abc, res.ab, res.bc, res.ac});
      res.abc = min({res.abc, a + oth.abc, ab + oth.bc, abc + oth.c});
      return res;
   }
} tree[sz << 2];

node fnc(int i) {
   node now;
   char c = s[i];
   if(c == 'a') now.a = 1;
   else if(c == 'b') now.b = 1;
   else now.c = 1;
   return now;
}

void form(int u = 1, int b = 1, int e = n) {
   if(b == e) {
      tree[u] = fnc(b);
      return;
   }
   int m = b + e >> 1, x = u << 1, y = x | 1;
   form(x, b, m); form(y, m + 1, e);
   tree[u] = tree[x] + tree[y];
}

void update(int i, int u = 1, int b = 1, int e = n) {
   if(b > i or e < i) return;
   if(b == e) {
      tree[u] = fnc(b);
      return;
   }
   int m = b + e >> 1, x = u << 1, y = x | 1;
   update(i, x, b, m); update(i, y, m + 1, e);
   tree[u] = tree[x] + tree[y];
}

int main() {
   int q;
   cin >> n >> q;
   scanf("%s", s + 1);
   form();
   while(q--) {
      int i; char c;
      scanf("%d %c", &i, &c);
      s[i] = c;
      update(i);
      printf("%d\n", tree[1].abc);
   }
}