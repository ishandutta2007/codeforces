#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int MAX = 1100000;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return ans;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  mt19937 mt(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
  long long BASE1 = mt() % 10000000 + 10000000;
  long long BASE2 = mt() % 10000000 + 20000000;
  long long INV1 = modinv(BASE1);
  long long INV2 = modinv(BASE2);
  vector<long long> pow1(MAX);
  pow1[0] = 1;
  for (int i = 1; i < MAX; i++){
    pow1[i] = pow1[i - 1] * BASE1 % MOD;
  }
  vector<long long> pow2(MAX);
  pow2[0] = 1;
  for (int i = 1; i < MAX; i++){
    pow2[i] = pow2[i - 1] * BASE2 % MOD;
  }
  vector<long long> inv1(MAX);
  inv1[0] = 1;
  for (int i = 1; i < MAX; i++){
    inv1[i] = inv1[i - 1] * INV1 % MOD;
  }
  vector<long long> inv2(MAX);
  inv2[0] = 1;
  for (int i = 1; i < MAX; i++){
    inv2[i] = inv2[i - 1] * INV2 % MOD;
  }
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  string t;
  cin >> t;
  while (n < 20){
    n++;
    t += '@';
  }
  int m = s.size();
  vector<long long> s0hash1(m + 1, 0);
  vector<long long> s0hash2(m + 1, 0);
  for (int i = 0; i < m; i++){
    s0hash1[i + 1] = (s0hash1[i] + s[i] * pow1[m - 1 - i]) % MOD;
    s0hash2[i + 1] = (s0hash2[i] + s[i] * pow2[m - 1 - i]) % MOD;
  }
  vector<long long> P(MAX);
  P[0] = 1;
  for (int i = 1; i < MAX; i++){
    P[i] = P[i - 1] * 2 % MOD;
  }
  vector<long long> Q(MAX);
  Q[0] = 1;
  Q[1] = modinv(2);
  for (int i = 2; i < MAX; i++){
    Q[i] = Q[i - 1] * Q[1] % MOD;
  }
  int n2 = min(n, 20);
  vector<string> S(n2 - 1);
  S[0] = string(1, t[0]);
  for (int i = 1; i < n2 - 1; i++){
    S[i] = S[i - 1] + t[i] + S[i - 1];
  }
  vector<vector<long long>> hash1(n2 - 1);
  vector<vector<long long>> hash2(n2 - 1);
  for (int i = 0; i < n2 - 1; i++){
    int L = S[i].size();
    hash1[i] = vector<long long>(L + 1, 0);
    hash2[i] = vector<long long>(L + 1, 0);
    for (int j = 0; j < L; j++){
      hash1[i][j + 1] = (hash1[i][j] + S[i][j] * pow1[L - 1 - j]) % MOD;
      hash2[i][j + 1] = (hash2[i][j] + S[i][j] * pow2[L - 1 - j]) % MOD;
    }
  }
  vector<vector<long long>> sum(26, vector<long long>(n + 1, 0));
  for (int i = 0; i < n; i++){
    if (t[i] != '@'){
      sum[t[i] - 'a'][i + 1] += P[n - 1 - i];
    }
  }
  for (int i = 0; i < 26; i++){
    for (int j = 1; j <= n; j++){
      sum[i][j] += sum[i][j - 1];
      sum[i][j] %= MOD;
    }
  }
  for (int i = 0; i < q; i++){
    int k;
    string w;
    cin >> k >> w;
    int L = w.size();
    vector<long long> whash1(L + 1, 0);
    vector<long long> whash2(L + 1, 0);
    for (int j = 0; j < L; j++){
      whash1[j + 1] = (whash1[j] + w[j] * pow1[L - 1 - j]) % MOD;
      whash2[j + 1] = (whash2[j] + w[j] * pow2[L - 1 - j]) % MOD;
    }
    vector<string> w2(m + 1);
    vector<vector<int>> p(m + 1);
    for (int j = 0; j < L; j++){
      w2[j % (m + 1)] += w[j];
      p[j % (m + 1)].push_back(j);
    }
    vector<bool> ok(m + 1, true);
    for (int j = 0; j <= m; j++){
      int cnt = p[j].size();
      if (cnt == 0){
        long long shash1 = (s0hash1[m - j + L] - s0hash1[m - j] + MOD) % MOD * inv1[j - L] % MOD;
        long long shash2 = (s0hash2[m - j + L] - s0hash2[m - j] + MOD) % MOD * inv2[j - L] % MOD;
        if (shash1 != whash1[L] || shash2 != whash2[L]){
          ok[j] = false;
        }
      } else {
        long long Lshash1 = (s0hash1[m] - s0hash1[m - j] + MOD) % MOD;
        long long Lshash2 = (s0hash2[m] - s0hash2[m - j] + MOD) % MOD;
        long long Lwhash1 = whash1[j] * inv1[L - j] % MOD;
        long long Lwhash2 = whash2[j] * inv2[L - j] % MOD;
        int tmp = (L - j + m) % (m + 1);
        long long Rshash1 = s0hash1[tmp] * inv1[m - tmp] % MOD;
        long long Rshash2 = s0hash2[tmp] * inv2[m - tmp] % MOD;
        long long Rwhash1 = (whash1[L] - whash1[p[j].back() + 1] + MOD) % MOD;
        long long Rwhash2 = (whash2[L] - whash2[p[j].back() + 1] + MOD) % MOD;
        if (!(Lshash1 == Lwhash1 && Lshash2 == Lwhash2 && Rshash1 == Rwhash1 && Rshash2 == Rwhash2)){
          ok[j] = false;
        } else {
          for (int l = 0; l < cnt - 1; l++){
            long long wmhash1 = (whash1[p[j][l + 1]] - whash1[p[j][l] + 1] + MOD) * inv1[L - p[j][l + 1]] % MOD;
            long long wmhash2 = (whash2[p[j][l + 1]] - whash2[p[j][l] + 1] + MOD) * inv2[L - p[j][l + 1]] % MOD;
            if (wmhash1 != s0hash1[m] || wmhash2 != s0hash2[m]){
              ok[j] = false;
              break;
            }
          }
        }
      }
    }
    long long ans = 0;
    for (int j = 0; j <= m; j++){
      if (ok[j]){
        if (w2[j].empty()){
          ans += P[k];
          ans %= MOD;
        } else {
          int L2 = w2[j].size();
          int tmp = L2;
          int id = -1;
          while (tmp > 0){
            tmp /= 2;
            id++;
          }
          int L3 = S[id].size();
          if (id < k){
            vector<long long> hash3(L2 + 1, 0);
            vector<long long> hash4(L2 + 1, 0);
            for (int l = 0; l < L2; l++){
              hash3[l + 1] = (hash3[l] + w2[j][l] * pow1[L2 - 1 - l]) % MOD;
              hash4[l + 1] = (hash4[l] + w2[j][l] * pow2[L2 - 1 - l]) % MOD;
            }
            for (int l = 0; l <= L3 - L2; l++){
              int r = l + L2;
              long long shash1 = (hash1[id][r] - hash1[id][l] + MOD) % MOD * inv1[L3 - r] % MOD;
              long long shash2 = (hash2[id][r] - hash2[id][l] + MOD) % MOD * inv2[L3 - r] % MOD;
              if (shash1 == hash3[L2] && shash2 == hash4[L2]){
                ans += P[k - id - 1];
                ans %= MOD;
              }
            }
            for (int l = 0; l < L2; l++){
              int r = L2 - 1 - l;
              long long left11 = (hash1[id][L3] - hash1[id][L3 - l] + MOD) % MOD;
              long long left12 = (hash2[id][L3] - hash2[id][L3 - l] + MOD) % MOD;
              long long left21 = hash3[l] * inv1[L2 - l] % MOD;
              long long left22 = hash4[l] * inv2[L2 - l] % MOD;
              long long right11 = hash1[id][r] * inv1[L3 - r] % MOD;
              long long right12 = hash2[id][r] * inv2[L3 - r] % MOD;
              long long right21 = (hash3[L2] - hash3[L2 - r] + MOD) % MOD;
              long long right22 = (hash4[L2] - hash4[L2 - r] + MOD) % MOD;
              if (left11 == left21 && left12 == left22 && right11 == right21 && right12 == right22){
                int a = w2[j][l] - 'a';
                long long tmp2 = (sum[a][k] - sum[a][id + 1] + MOD) % MOD;
                tmp2 *= Q[n - k];
                tmp2 %= MOD;
                ans += tmp2;
                ans %= MOD;
              }
            }
          }
        }
      }
    }
    cout << ans << "\n";
  }
}