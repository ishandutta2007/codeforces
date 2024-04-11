#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1010

int n, b[N], x;
vector <int> a;

int main(){
   scanf("%d", &n);
   for(int i = 0; i < n; i ++){
      scanf("%d", &x);
      if(!b[x]) a.push_back(x);
      b[x] ++;
   }
   int ans = 0;
   for(int i = 0; i < a.size(); i ++){
      ans = max(b[a[i]], ans);
   }
   printf("%d %d\n", ans, a.size());
}