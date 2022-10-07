#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1000010;
const int SIZE = 1010;
vector<pii> buckets[SIZE];

int N;
int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    int buckt = y / SIZE;
    if (buckt % 2 == 1) {
      x *= -1;
    }
    buckets[buckt].push_back(pii(x, i));
  }
  for(int i = 0; i < SIZE; ++i) {
    vector<pii> v = buckets[i];
    sort(v.begin(), v.end());
    for(int j = 0; j < v.size(); ++j) {
      printf("%d ", v[j].second);
    }
  }
  printf("\n");
}