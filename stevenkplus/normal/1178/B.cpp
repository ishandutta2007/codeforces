#include <iostream>
using namespace std;

const int MAXN = 1001000;
typedef long long ll;
ll A[MAXN]; // "w"
ll B[MAXN]; // "wo"

int main() {
  string s;
  cin >> s;
  ll ans = 0;
  for(int i = 0; i < s.size(); ++i) {
    if (s[i] == 'w' || (i > 0 && s[i] == 'v' && s[i - 1] == 'v')) {
      A[i + 1] = A[i] + 1;
      ans += B[i];
    } else {
      A[i + 1] = A[i];
    }
    if (s[i] == 'o') {
      B[i + 1] = B[i] + A[i];
    } else {
      B[i + 1] = B[i];
    }
  }
  cout << ans << "\n";
}