#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

const int N = 333333;

pair<int, int> w[N];
int n, result[N];
set<int> s;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        w[i].first = a;
        w[i].second = i;
    }
    sort(w + 1, w + n + 1);
    int now = 0;
    for(int i = 1; i <= n; i++) {
        now = max(now, w[i].first);
        while(s.count(now)) {
            now++;
        }
        result[w[i].second] = now;
        ++now;
    }
    for(int i = 1; i <= n; i++) {
        printf("%d%c", result[i], i == n ? '\n' : ' ');
    }
    return 0;
}