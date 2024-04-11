#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 101000;
vector<pair<int, int> > bases;
vector<pair<int, int> > ships;

int ans[MAXN];

int main() {
  int s, b;
  cin >> s >> b;
  for(int i = 0; i < s; ++i) {
    int p;
    cin >> p;
    ships.push_back(pii(p, i));
  }
  for(int i = 0; i < b; ++i) {
    int d, g;
    cin >> d >> g;
    bases.push_back(pii(d, g));
  }
  sort(ships.begin(), ships.end());
  sort(bases.begin(), bases.end());

  int k = 0;
  int j = 0;
  for(int i = 0; i < s; ++i) {
    while (j < b && bases[j].first <= ships[i].first) {
      k += bases[j].second;
      ++j;
    }

    ans[ships[i].second] = k;
  }
  for(int i = 0; i < s; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";

}