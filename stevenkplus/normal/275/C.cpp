#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

set<int> myset;

const int MAXN = 100100;
int ar[MAXN];
int N, K;
int main() {
scanf("%d %d", &N, &K);
for(int i = 0; i < N; ++i) {
scanf("%d", ar + i);
}

sort(ar, ar + N);
int cnt = 0;
for(int i = 0; i < N; ++i) {
    int nxt = ar[i];
    if (nxt % K == 0 && myset.find(nxt/K) != myset.end()) {
    } else {
    ++cnt;
    myset.insert(nxt);
    }
    }
    printf("%d\n", cnt);
    return 0;
    }