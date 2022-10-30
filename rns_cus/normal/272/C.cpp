#include<bits/stdc++.h>
using namespace std;

#define N 1000100
typedef long long LL;

LL tree[N];

int x, m, w, h, n;

inline void add(int k, LL v) { for (; k <= n; k += k & -k) tree[k] = max(tree[k], v); }

LL sum(int k) {
   LL rlt = 0;
   for (int i = k; i; i -= i & -i) rlt = max(rlt, tree[i]);
   return rlt;
}


int main(){
   //freopen("aaa.in", "r", stdin);
   scanf("%d", &n);
   for(int i = 1; i <= n; i ++){
      scanf("%d", &x);
      add(i, x);
   }
   scanf("%d", &m);
   for(int i = 1; i <= m; i ++){
      scanf("%d %d", &w, &h);
      LL high = sum(w);
      printf("%I64d\n", high);
      add( 1, high + h);
   }
}