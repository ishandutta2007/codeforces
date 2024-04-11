#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 200100;

char input[MAXN];
int N, A, B, K;

int main() {
  scanf("%d %d %d %d\n", &N, &A, &B, &K);
  scanf("%s", input);

  vector<int> ships;
  int run = 0;
  for(int i = 0; i < N; ++i) {
    if (input[i] == '1') {
      run = 0;
    } else {
      ++run;
    }

    if (run == B) {
      // we may need to shoot here
      ships.push_back(i + 1);
      run = 0;
    }
  }

  int need = ships.size() - A + 1;
  printf("%d\n", need);
  for(int i = 0; i < need; ++i) {
    printf("%d ", ships[i]);
  }
  printf("\n");
  return 0;
}