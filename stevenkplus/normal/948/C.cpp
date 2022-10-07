#include <cstdio>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int MAXN = 100100;
int ar[MAXN];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", ar + i);
  }

  priority_queue<ll, vector<ll>, greater<ll> > q;

  ll sm = 0;
  for(int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);

    ll today = 0;
    q.push(ar[i] + sm);
    while (q.size() > 0 && q.top() < sm + t) {
      ll pile = q.top(); q.pop();
      today += pile - sm;
    }
    sm += t;
    cout << ll(t) * q.size() + today << " ";
  }
  cout << "\n";
}