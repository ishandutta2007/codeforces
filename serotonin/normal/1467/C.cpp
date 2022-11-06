#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

ll a[sz], b[sz], c[sz];

int main() {
   ll sum = 0;
   int n1, n2, n3;
   scanf("%d", &n1);
   scanf("%d", &n2);
   scanf("%d", &n3);
   for(int i=0; i<n1; i++) scanf("%lld", &a[i]), sum += a[i];
   for(int i=0; i<n2; i++) scanf("%lld", &b[i]), sum += b[i];
   for(int i=0; i<n3; i++) scanf("%lld", &c[i]), sum += c[i];

   ll cut = LLONG_MAX;
   sort(a, a+n1);
   sort(b, b+n2);
   sort(c, c+n3);

   cut = min(cut, a[0] + b[0]);
   cut = min(cut, c[0] + b[0]);
   cut = min(cut, a[0] + c[0]);

   ll z;

   z = 0;
   for(int i=0; i<n1; i++) z += a[i];
   cut = min(cut, z);
   z = 0;
   for(int i=0; i<n2; i++) z += b[i];
   cut = min(cut, z);
   z = 0;
   for(int i=0; i<n3; i++) z += c[i];
   cut = min(cut, z);

   cout << sum - cut * 2LL << endl;
}