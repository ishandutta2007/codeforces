#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e7+5;

int spf[sz], a[sz];

int main()
{
   for(int i=2; i<sz; i++) {
      if(spf[i]) continue;
      for(int j=i; j<sz; j+=i) spf[j] = i;
   }

   int n;
   cin >> n;
   for(int i=0; i<n; i++) {
      scanf("%d", &a[i]);
      int x = spf[a[i]];
      while(a[i] % x == 0) a[i] /= x;
		if(a[i] > 1) printf("%d ", x);
		else printf("-1 "), a[i] = -1;
   }

   puts("");
   for(int i=0; i<n; i++) printf("%d ", a[i]);
}