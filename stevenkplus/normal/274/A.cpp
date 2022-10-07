#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> mymap;

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
        int cur = ar[i];
        if (cur % K == 0 && mymap[cur / K]) {
            ++cnt;
        } else {
            mymap[cur] = 1;
        }
    }
    
    int ans = N - cnt;
    printf("%d\n", ans);
    return 0;
}