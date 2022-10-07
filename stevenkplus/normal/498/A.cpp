#include <cstdio>
#include <complex>
using namespace std;

bool sect(double ax, double ay, double bx, double by, int a, int b, int c) {
  double ac = a * ax + b * ay;
  double bc = a * bx + b * by;
  if ((ac + c > 0 && bc + c < 0) || (ac + c < 0 && bc + c > 0)) {
    return true;
  } else {
    return false;
  }
}


int N;

int main() {
  int ax, ay, bx, by;
  scanf("%d %d", &ax, &ay);
  scanf("%d %d", &bx, &by);

  scanf("%d", &N);
  int cnt = 0;
  for(int i = 0; i < N; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (sect(ax, ay, bx, by, a, b, c)) {
//      printf("Intersect line %d\n", i);
      ++cnt;
    }
  }

  printf("%d\n", cnt);
  return 0;
}