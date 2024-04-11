#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int MAXN = 2 * 1e5 + 10;

lli n, k;
//a[MAXN];

int main(){
  cin >> n >> k;
  lli rem = 0, bags = 0;
  lli a;
  for(int i = 0; i < n; i++){
    cin >> a;
    // cout << rem <<  endl;
    if(rem){
      bags++;
      a = max((lli)0, a - k + rem);
    }
    bags += a / k;
    rem = a % k;
    if(i == n - 1 && rem){
      bags++;
    }
  }
  cout << bags << endl;
}