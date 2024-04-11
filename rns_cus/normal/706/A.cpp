#include<bits/stdc++.h>
using namespace std;

double ans, tmp;
int a, b, x, y, v, n;

int main(){
   ans = 1000000;
   scanf("%d %d", &a, &b);
   scanf("%d", &n);
   for(int i = 0; i < n; i ++){
      scanf("%d %d %d", &x, &y, &v);
      tmp = hypot(x - a, y - b) / v;
      ans = min(tmp, ans);
   }
   printf("%lf\n", ans);
}