#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 100100;
int ar[MAXN];
int N;

int main() {   
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", ar + i);
    }
    int mind = 100000;
    int best = 0;
    for(int i = 0; i < N; ++i) {
        int dif = abs(ar[(i + 1) % N] - ar[i]);
        if (dif < mind) {
            mind = dif;
            best = i + 1;
       }
   }
   int nxt = best % N + 1;
   printf("%d %d\n", best, nxt);
   return 0;
}