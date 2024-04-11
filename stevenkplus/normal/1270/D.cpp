#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAXN = 200100;
ll ar[MAXN];

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> ar;
  for(int j = 1; j <= k + 1; ++j) {
    cout << "?";
    for(int i = 1; i <= k + 1; ++i) {
      if (i == j) continue;
      cout << " " << i;
    }
    cout << endl;
    int x, y;
    cin >> x >> y;
    ar.push_back(y);
  }
  sort(ar.begin(), ar.end());
  int i = 0;
  while (ar[i] == ar[i + 1]) ++i;
  cout << "! " << k - i << endl;
}