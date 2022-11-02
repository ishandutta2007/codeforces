#include<bits/stdc++.h>
using namespace std;
#define N 300010
#define mod 1000000007

int n, x, mx, cnt, ans;
vector <int> p[N];
int inv[N], c[N], r[N];

int pre(){
   inv[1] = 1;
   for(int i = 2; i <= n; i ++) inv[i] = mod - 1ll * (mod / i) * inv[mod % i] % mod;
   c[0] = 1;
   for(int i = 1; i < n; i ++) c[i] = 1ll * c[i-1] * (n - i) % mod * inv[i] % mod;
   int sum = 0;
   for(int i = n -1; i >= 0; i --){
      sum += c[i];
      sum %= mod;
      r[i] = sum;
   }
   sum = 0;
   for(int i = 0; i < n; i ++){
      sum += c[i];
      sum %= mod;
      r[i] -= sum;
      if(r[i] < 0) r[i] += mod;
   }
}

int main(){
   ios::sync_with_stdio(0);
   cin >> n;
   pre();
   for(int i = 0; i < n; i ++){
      cin >> x;
      mx = max(x, mx);
      for(int j = 2; j * j <= x; j ++){
         while( x % j == 0){ cnt ++; x = x / j; }
         if(cnt){ p[j].push_back(cnt); cnt = 0; }
      }
      if(x) p[x].push_back(1);
   }
   for(int i = 2; i <= mx; i ++) if(p[i].size()){
      sort(p[i].begin(), p[i].end());
      reverse(p[i].begin(), p[i].end());
      for(int j = 0; j < p[i].size(); j ++){ ans += 1ll * p[i][j] * r[j] % mod; ans %= mod; }
   }
   cout << ans << endl;
}