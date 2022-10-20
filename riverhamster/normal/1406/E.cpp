#include <iostream>
#include <cmath>
using namespace std;

const int N = 100004;
bool np[N];
int p[N], lpf[N], lc[N], pc = 0;
void prime_sieve(int n){
  for(int i=2; i<=n; i++){
    if(!np[i]) p[++pc] = i, lpf[i] = pc;
    ++lc[lpf[i]];
    for(int j=1; j<=pc && i * p[j] <= n; ++j){
      np[i * p[j]] = true;
      lpf[i * p[j]] = j;
      if(i % p[j] == 0) break;
    }
  }
}

int main(){
  int n, res = 1;
  cin >> n;
  prime_sieve(n);
  if(n == 1) {
    cout << "C 1" << endl;
    return 0;
  }
  int i;
  for(i=1; p[i]*p[i]<=n; ++i){
    cout << "B " << p[i] << endl;
    int x;
    cin >> x;
    cout << "A " << p[i] << endl;
    int c;
    cin >> c;
    if(c){
      res *= p[i];
      for(int j=p[i]*p[i]; j<=n; j*=p[i]){
        cout << "A " << j << endl;
        int c; cin >> c;
        if(c) res *= p[i];
        else break;
      }
    }
  }
  int S, last = i;
  cout << "A 1" << endl;
  cin >> S;
  int B = sqrt(pc);
  int cnt = 0;
  bool flag = false;
  for(; i<=pc; ++i){
    cout << "B " << p[i] << endl;
    int x; cin >> x;
    cnt += x;
    if(cnt >= B){
      cout << "A 1" << endl;
      int nowS; cin >> nowS;
      if(S - nowS != cnt){
        for(int j=last; j<=i; j++){
          cout << "A " << p[j] << endl;
          int c; cin >> c;
          if(c){
            res *= p[j];
            flag = true;
            break;
          }
        }
      }
      last = i + 1;
      S = nowS;
      cnt = 0;
    }
    if(flag) break;
  }
  --i;
  cout << "A 1" << endl;
  int nowS; cin >> nowS;
  if(S - nowS != cnt){
    for(int j=last; j<=i; j++){
      cout << "A " << p[j] << endl;
      int c; cin >> c;
      if(c){
        res *= p[j];
        break;
      }
    }
  }
  cout << "C " << res << endl;
  return 0;
}