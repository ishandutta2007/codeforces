#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
#define M 2020
const int mod = 1000003;
typedef pair<int, int> pii;
#define x first
#define y second

int n;
int m;

int main() {
    //freopen("A2.in", "r", stdin);
    scanf("%d %d", &n, &m);
    int ans = 0;
    for (int i = 0; i < n * m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x + y) ans++;
    }
    printf("%d\n", ans);
    return 0;
}