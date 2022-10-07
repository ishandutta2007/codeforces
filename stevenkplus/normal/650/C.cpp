#include <cstdio>
#include <vector>
#include <map>
using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
typedef pair<int, int> pii;

const int MAXN = 10010000;

int rows[MAXN], cols[MAXN];
vector<int> grid[MAXN];
map<int, vector<pii> > mp;

unsigned int k = 5462;
int rnd(int x) {
  k *= 31531;
  k += 563453;
  return k % x;
}

int N, M;
int main() {
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      grid[i].push_back(0);
    }
  }

  for(int i = 0; i <N ; ++i) {
    for(int j = 0; j < M; ++j) {
      int x;
      scanf("%d", &x);
      mp[x].push_back(pii(i, j));
    }
  }

  repi(i, mp) {
    vector<pii> v = i->second;
    repi(j, v) {
      int x = j->first, y = j->second;
      grid[x][y] = max(rows[x], cols[y]) + 1;
    }

    repi(j, v) {
      int x = j->first, y = j->second;
      rows[x] = max(rows[x], grid[x][y]);
      cols[y] = max(cols[y], grid[x][y]);
    }

    bool good = true;
    while (good) {
      good = false;
      int z = v.size();
      for(int i = 0; i < z; ++i) {
        int j = rnd(i + 1);
        swap(v[i], v[j]);
      }
      repi(j, v) {
        int x = j->first, y = j->second;
        int k = max(rows[x], cols[y]);
        if (k > grid[x][y]) {
          good = true;
          grid[x][y] = k;
          rows[x] = max(rows[x], grid[x][y]);
          cols[y] = max(cols[y], grid[x][y]);
        }
      }
    }
  }

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}