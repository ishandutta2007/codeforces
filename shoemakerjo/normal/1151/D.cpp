#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int maxn = 100010;
int n;

ll ai[maxn];
ll bi[maxn];
#define pli pair<ll, int>
vector<pli> stuff;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ai[i] >> bi[i];
    stuff.push_back(pli(bi[i]-ai[i], i));
  }
  sort(stuff.begin(), stuff.end());

  ll res = 0LL;

  for (int ind = 1; ind <= n; ind++) {
    int i = stuff[ind-1].second;
    res +=ai[i] * (ind-1);
    res += bi[i] * (n-ind);
  }
  cout << res << endl;
}