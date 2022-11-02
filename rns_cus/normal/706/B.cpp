#include<bits/stdc++.h>
using namespace std;
#define N 1000019
int a[N], n, m, k, x;

int main(){
   scanf("%d", &n);
   for(int i = 0; i < n; i ++) scanf("%d", a + i);
   sort(a, a + n);
   scanf("%d", &m);
   for(int i = 0; i < m; i ++){
      scanf("%d", &x);
      k = lower_bound(a, a + n, x + 1) - a;
      printf("%d\n", k);
   }
}