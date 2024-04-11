#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

char s[11];
int n;

int zfnc(int i) {
   if(i >= n) return 1;
   if(i == n - 2) {
      if(!i) return 0;
      if(s[i] != '0' and s[i] != '_') return 0;
      return zfnc(i + 1);
   }
   if(i == n - 1) {
      if(s[i] != '0' and s[i] != '_') return 0;
      return 1;
   }
   if(s[i] == '_') {
      if(!i) return 9 * zfnc(i + 1);
      return 10 * zfnc(i + 1);
   }
   return zfnc(i + 1);
}

int tfnc(int i) {
   if(i >= n) return 1;
   if(i == n - 2) {
      if(s[i] != '2' and s[i] != '_') return 0;
      return tfnc(i + 1);
   }
   if(i == n - 1) {
      if(s[i] != '5' and s[i] != '_') return 0;
      return 1;
   }
   if(s[i] == '_') {
      if(!i) return 9 * tfnc(i + 1);
      return 10 * tfnc(i + 1);
   }
   return tfnc(i + 1);
}

int ffnc(int i) {
   if(i >= n) return 1;
   if(i == n - 2) {
      if(s[i] != '5' and s[i] != '_') return 0;
      return ffnc(i + 1);
   }
   if(i == n - 1) {
      if(s[i] != '0' and s[i] != '_') return 0;
      return 1;
   }
   if(s[i] == '_') {
      if(!i) return 9 * ffnc(i + 1);
      return 10 * ffnc(i + 1);
   }
   return ffnc(i + 1);
}

int sfnc(int i) {
   if(i >= n) return 1;
   if(i == n - 2) {
      if(s[i] != '7' and s[i] != '_') return 0;
      return sfnc(i + 1);
   }
   if(i == n - 1) {
      if(s[i] != '5' and s[i] != '_') return 0;
      return 1;
   }
   if(s[i] == '_') {
      if(!i) return 9 * sfnc(i + 1);
      return 10 * sfnc(i + 1);
   }
   return sfnc(i + 1);
}

int main() {
   scanf("%s", s);
   n = strlen(s);

   if(n == 1) {
      if(s[0] == '0' or s[0] == 'X' or s[0] == '_') puts("1");
      else puts("0");
      return 0;
   }

   if(s[0] == '0') {
      cout << 0;
      return 0;
   }

   vector <int> a;
   for(int i=0; i<n; i++) if(s[i] == 'X') a.push_back(i);

   int ans = 0;
   if(!a.empty()) {
      for(int x=0; x<10; x++) {
         if(!x and s[0] == 'X') continue;
         for(int i : a) s[i] = '0' + x;
         ans += zfnc(0);
         ans += tfnc(0);
         ans += sfnc(0);
         ans += ffnc(0);
         for(int i : a) s[i] = 'X';
      }
   }
   else {
      ans += zfnc(0);
      ans += tfnc(0);
      ans += sfnc(0);
      ans += ffnc(0);
   }
   cout << ans;
}