#include<iostream>
#include<cstring>
#include<cassert>
using namespace std;

typedef long long ll;

const int MAXN = 1e6;
const int MAXT = 2e9;
const int MAXA = 2e3;

int N;
ll A, B, T;

char s[MAXN];

int sum[MAXN];

// can we see v photos
bool is_good(int v) {
  for(int l = 0; l < v; l++) {
    int r = v - l;
    assert(r > 0);
    ll t = min(l, r - 1) * A + (v - 1) * A + sum[r] - sum[0] + sum[N] - sum[N - l];
    if(t <= T) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> N;
  cin >> A >> B >> T >> s;

  sum[0] = 0;
  for(int i = 0; i < N; i++) {
    sum[i+1] = sum[i] + (s[i] == 'w') * B + 1;
  }
  int mi = 0;
  int ma = N + 1;
  while(ma - mi > 1) {
    int md = (mi + ma) / 2;
    if(is_good(md)) mi = md;
    else ma = md;
  }
  cout << mi << '\n';
}