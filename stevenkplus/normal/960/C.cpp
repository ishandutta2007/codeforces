#include <bits/stdc++.h>
using namespace std;

const long long MAXV = 1E9 + 2;
vector<long long> ans;

long long x = 1;

void go(int n) {
  for(int i = 0; i < n; i += 1) {
    ans.push_back(x);
  }
  x += MAXV;
}

long long S[40]; // 40 -> 200 million
void prec() {
  for(int i = 1; i < 40; ++i) {
    S[i] = S[i - 1] * 2 + 1;
  }
}


int n, d;
int main() {
  prec();
  cin >> n >> d;
  while (n > 0) {
    int i = 1;
    while (i + 1 < 40 && S[i + 1] <= n) {
      ++i;
    }
    n -= S[i];
    go(i);
  }

  cout << ans.size() << "\n";
  for(int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}