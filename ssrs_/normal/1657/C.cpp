#include <bits/stdc++.h>
using namespace std;
const long long M30 = ((long long) 1 << 30) - 1;
const long long M31 = ((long long) 1 << 31) - 1;
const long long MOD = ((long long) 1 << 61) - 1;
long long BASE;
unsigned long long modulo(unsigned long long x){
  unsigned long long xu = x >> 61;
  unsigned long long xd = x & MOD;
  unsigned long long res = xu + xd;
  if (res >= MOD){
    res -= MOD;
  }
  return res;
}
unsigned long long mul(unsigned long long a, unsigned long long b){
  unsigned long long au = a >> 31;
  unsigned long long ad = a & M31;
  unsigned long long bu = b >> 31;
  unsigned long long bd = b & M31;
  unsigned long long mid = au * bd + ad * bu;
  unsigned long long midu = mid >> 30;
  unsigned long long midd = mid & M30;
  return modulo(au * bu * 2 + midu + (midd << 31) + ad * bd);
}
struct rolling_hash{
  vector<long long> S;
  vector<long long> POW;
  rolling_hash(string s){
    int N = s.size();
    S = vector<long long>(N + 1, 0);
    for (int i = N - 1; i >= 0; i--){
      S[i] = modulo(mul(S[i + 1], BASE) + s[i]);
    }
    POW = vector<long long>(N + 1, 1);
    for (int i = 0; i < N; i++){
      POW[i + 1] = mul(POW[i], BASE);
    }
  }
  long long get(int L, int R){
    return modulo(S[L] - mul(S[R], POW[R - L]) + MOD);
  }
};
int main(){
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  BASE = mt() % 10000000 + 10000000;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    rolling_hash R1(s), R2(t);
    int L = 0;
    int c = 0;
    int sum = 0, mn = 0;
    for (int j = 1; j <= n; j++){
      if (s[j - 1] == '('){
        sum++;
      } else {
        sum--;
        mn = min(mn, sum);
      }
      if (sum == 0 && mn == 0){
        L = j;
        c++;
        sum = 0;
        mn = 0;
      } else if (j - L >= 2){
        long long h1 = R1.get(L, j);
        long long h2 = R2.get(n - j, n - L);
        if (h1 == h2){
          L = j;
          c++;
          sum = 0;
          mn = 0;
        }
      }
    }
    int r = n - L;
    cout << c << ' ' << r << endl;
  }
}