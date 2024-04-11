#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 1000100

int a[N], dp[N], ri[N], rdp[N], n, k, ans, rlt;
long long tmp;

int mul(int x, int y){
   if(y == 0) return 1;
   int tmp = mul(x, y >> 1);
   tmp = 1ll * tmp * tmp % mod;
   if(y & 1) return 1ll * tmp * x % mod;
   return tmp;
}

void pre(){
   ri[1] = 1;
   for(int i = 2; i < N; i ++){
      int u = mod / i;
      int r = mod % i;
      ri[i] = (1ll * (mod - ri[r]) * u ) % mod;
   }
   rdp[0] = 1;
   for(int i = 1; i < N; i ++){
      rdp[i] = (1ll * rdp[i-1] * ri[i]) % mod;
   }
}

int main(){
   //freopen("a.in", "r", stdin);
   pre();
   scanf("%d %d", &n, &k);

   dp[0] = 0; dp[1] = 1;
   for(int i = 2; i <= k + 10; i ++){
      dp[i] = (dp[i - 1] + mul(i, k)) % mod;
   }

   if(n <= k + 3){ printf("%d\n", dp[n]); return 0; }
   ans = 1;
   for(int i = 0; i <= k + 1; i ++) ans = (1ll * ans * (n - i)) % mod;
   rlt = 0;
   for(int i = 0; i <= k + 1; i ++){
      tmp = 1ll;
      tmp = (tmp * rdp[i]) % mod;
      tmp = (tmp * rdp[k + 1 - i]) % mod;
      if( (1 + k - i) & 1 ) tmp = mod - tmp;
      tmp = (tmp * mul(n - i, mod - 2)) % mod;
      tmp = (tmp * dp[i]) % mod;
      rlt = (rlt + tmp) % mod;
   }
   printf("%d\n", (1ll * rlt * ans) % mod);
}