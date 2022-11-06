#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 44, dim = 444, mod = 998244353;

struct matrix {
   int n, v[dim][dim];

   matrix(int n) : n(n) {
      memset(v, 0, sizeof(v));
   }

   matrix operator *(const matrix &b) {
      matrix ans = matrix(n);
      for(int k=0; k<n; k++) {
         for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
               int &w = ans.v[i][j];
               w += (ll) v[i][k] * b.v[k][j] % mod;
               w >= mod ? w -= mod : 1;
            }
         }
      }
      return ans;
   }

   matrix operator ^(ll p) {
      matrix ans = matrix(n), b = *this;
      for(int i=0; i<n; i++) ans.v[i][i] = 1;

      while(p) {
         if(p & 1) ans = ans * b;
         p >>= 1;
         b = b * b;
      }
      return ans;
   }
};

char s[sz];
int trie[sz][26], k = 1;
bool word[sz], can[sz][sz][sz][sz];
int whe[sz][sz], a[dim][dim], mk;

void add(int x, int y, int fx, int fy) {
   for(int i=0; i<k; i++)
      for(int j=0; j<k; j++)
         can[x][y][i][j] |= can[fx][fy][i][j];
}

void go(int x, int y) {
   if(whe[x][y]) return;
   int &u = whe[x][y] = ++mk;
   for(int i=0; i<k; i++) {
      for(int j=0; j<k; j++) {
         if(can[x][y][i][j]) {
            if(!whe[i][j]) go(i, j);
            int v = whe[i][j];
            a[v][u] = 1;
         }
      }
   }
}

int main() {
   int n, m;
   cin >> n >> m;
   for(int i=0; i<n; i++) {
      scanf("%s", s);
      int u = 0;
      for(int j=0; s[j]; j++) {
         int x = s[j] - 'a', &w = trie[u][x];
         if(!w) w = k++;
         u = w;
      }
      word[u] = 1;
   }
   for(int i=0; i<k; i++) {
      for(int j=0; j<k; j++) {
         for(int c=0; c<26; c++) {
            int u = trie[i][c], v = trie[j][c];
            if(u and v) can[i][j][u][v] = 1;
         }
      }
   }
   for(int i=0; i<k; i++) {
      for(int j=0; j<k; j++) {
         if(word[i]) add(i, j, 0, j);
         if(word[j]) add(i, j, i, 0);
         if(word[i] and word[j]) add(i, j, 0, 0);
      }
   }
   go(0, 0);

   matrix mat(mk);
   for(int i=0; i<mk; i++)
      for(int j=0; j<mk; j++) mat.v[i][j] = a[i+1][j+1];

   ll ans = 0;
   mat = mat ^ m;
   for(int i=0; i<k; i++) {
      for(int j=0; j<k; j++) {
         int x = whe[i][j];
         if(x and word[i] and word[j]) ans += mat.v[x-1][0];
      }
   }
   cout << ans % mod;
}