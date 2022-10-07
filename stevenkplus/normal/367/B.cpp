#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 200100;

int N, M, P;

int A[MAXN];
int B[MAXN];

int main() {
  scanf("%d %d %d", &N, &M, &P);
  for(int i = 0; i < N; ++i) {
    scanf("%d", A + i);
  }
  for(int i = 0; i < M; ++i) {
    scanf("%d", B + i);
  }

  map<int, int> mymap;
  vector<int> ans;
  for(int q = 0; q < P; ++q) {
    if (q + (long long)(M - 1) * P >= N) break;
    mymap.clear();
    int need = 0;
    for(int i = 0; i < M; ++i) {
      int &r = mymap[B[i]];
      --r;
      if (r == -1) ++need;
    }

    for(int i = 0; i < M; ++i) {
      int &r = mymap[A[q + i * P]];
      ++r;
      if (r == 1) ++need;
      else if (r == 0) --need;
    }
    //printf("q= %d, need =%d\n", q, need);
    if (need == 0) ans.push_back(q);

    for(int i = M; q + i * P < N; ++i) {
      int &r = mymap[A[q + i * P]];
      ++r;
      if (r == 1) ++need;
      else if (r == 0) --need;

      int &p = mymap[A[q + (i - M) * P]];
      --p;
      if (p == 0) --need;
      else if (p == -1) ++need;

//printf("q = %d, need = %d\n", q + (i - M + 1) * P, need);
      if (need == 0) ans.push_back(q + (i - M + 1) * P);
    }
  }

  sort(ans.begin(), ans.end());
  int z = ans.size();
  printf("%d\n", z);
  for(int i = 0; i < z; ++i) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
  return 0;
}