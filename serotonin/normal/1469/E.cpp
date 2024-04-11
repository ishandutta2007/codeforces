#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

char ans[sz];

char s[sz];
int s0[(sz/3)+10], suf0[(sz/3)+10];
int n, k, ar[sz], suf[sz], bucket[sz], mem[sz << 2];
int cnt[sz];

void radixsort(int* source, int* dest, int* val, int n, int lim){
   int i, s = 0, x;
   memset(bucket, 0, lim << 2);
   for (i = 0; i < n; i++) bucket[val[source[i]]]++;

   for (i = 0; i < lim; i++){
      x = bucket[i];
      bucket[i] = s, s += x;
   }
   for (i = 0; i < n; i++) dest[bucket[val[source[i]]]++] = source[i];
}

void DC3(int* ar, int* suf, int n, int lim, int ptr){
   int *s12, *suf12;
   int allc = (n / 3) << 1, n0 = (n + 2) / 3;
   int i, j, k, l, c, d, p, t, m, r, counter;
   s12 = &mem[ptr], ptr += (allc + 5), suf12 = &mem[ptr], ptr += (allc + 5);

   c = 0, m = 0, r = n + ((n % 3) == 1);
   for (i = 0; i < r; i++, m++){
      if (m == 3) m = 0;
      if (m) s12[c++] = i;
   }
   s12[c] = suf12[c] = s12[c + 1] = suf12[c + 1] = s12[c + 2] = suf12[c + 2] = 0;
   radixsort(s12, suf12, ar + 2, c, lim + 1);
   radixsort(suf12, s12, ar + 1, c, lim + 1);
   radixsort(s12, suf12, ar, c, lim + 1);

   counter = 0, j = -1;
   for (i = 0; i < c; i++){
      if ((ar[suf12[i]] != j) || (ar[suf12[i] + 1] != k) || (ar[suf12[i] + 2] != l)){
         counter++;
         j = ar[suf12[i]], k = ar[suf12[i] + 1], l = ar[suf12[i] + 2];
      }
      if((suf12[i] % 3) == 1) s12[suf12[i] / 3] = counter;
      else s12[(suf12[i] / 3) + n0] = counter;
   }

   if (counter == c){
      for(i = 0; i < c; i++) suf12[s12[i] - 1] = i;
   }
   else{
      DC3(s12, suf12, c, counter, ptr);
      for (i = 0; i < c; i++) s12[suf12[i]] = i + 1;
   }

   for (i = 0, d = 0; i < c; i++){
      if (suf12[i] < n0) s0[d++] = (suf12[i] * 3);
   }
   radixsort(s0, suf0, ar, d, lim + 1);
   for (k = 0, l = ((n % 3) == 1), r = 0; r < n; r++){
      j = suf0[k];
      i = ((suf12[l] < n0) ? (suf12[l] * 3) + 1 : ((suf12[l] - n0) * 3) + 2);
      if (l == c) suf[r] = suf0[k++];
      else if (k == d) suf[r] = i, l++;
      else{
         if (suf12[l] < n0){
            if ((ar[i] < ar[j]) || (ar[i] == ar[j] && s12[suf12[l] + n0] <= s12[j / 3])) suf[r] = i, l++;
            else suf[r] = j, k++;
         }
         else{
            if ((ar[i] < ar[j]) || (ar[i] == ar[j] && ar[i + 1] < ar[j + 1]) || (ar[i] == ar[j] && ar[i + 1] == ar[j + 1] && s12[suf12[l] - n0 + 1] <= s12[(j /3) + n0]) ) suf[r] = i, l++;
            else suf[r] = j, k++;
         }
      }
   }
}

void Generate(){
   int i, j, lim = 0;
   for (i = 0; i < n; i++){
      ar[i] = s[i];
      if (ar[i] > lim) lim = ar[i];
   }

   ar[n] = ar[n + 1] = ar[n + 2] = 0;
   DC3(ar, suf, n, lim, 0);
}

bool fnc(int l, int r, int n, int dep = 0) {
   if(dep == k-1) {
      int z = 0;
      for(int i=l; i<=r; i++) {
         int x = suf[i] + dep;
         if(x >= n) continue;
         x = s[x] - '0';
         z |= 1 << x;
      }
      if(z == 2) ans[dep] = '1';
      else ans[dep] = '0';
      return z < 3;
   }

   int lo = l, hi = r+1;
   while(lo < hi) {
      int i = lo + hi >> 1;
      int x = suf[i] + dep;
      if(x >= n or s[x] == '0') lo = i + 1;
      else hi = i;
   }
   int m = lo-1;

   if(m == r) {
      for(int i=dep; i<k; i++) ans[i] = '0';
      return 1;
   }

   if(fnc(m+1, r, n, dep + 1)) {
      ans[dep] = '0';
      return 1;
   }

   if(m == l-1) {
      ans[dep] = '1';
      for(int i=dep+1; i<k; i++) ans[i] = '0';
      return 1;
   }

   if(fnc(l, m, n, dep + 1)) {
      ans[dep] = '1';
      return 1;
   }

   return 0;
}

void solve() {
   scanf("%d %d %s", &n, &k, s);
   Generate();

   if(fnc(0, n-1, n)) {
      puts("YES");
      ans[k] = 0;
      puts(ans);
   }
   else puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}