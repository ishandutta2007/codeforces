#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, k;
char orig[200005];
char newv[200005];

int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", orig);
    for (int i = 0; i < n; i++) {
        newv[i] = orig[i%k];
    }
    printf("%d\n", n);
    bool good = true;
    for (int i = 0; i < n; i++) {
        if (newv[i] != orig[i]) {
            good = newv[i] > orig[i]; break;
        }
    }
    if (good) {
        printf("%s", newv); return 0;
    }
    int cur = k - 1;
    while (1) {
        if (newv[cur] != '9') {
            newv[cur]++; break;
        } else {
            newv[cur] = '0'; cur--;
        }
    }
    for (int i = k; i < n; i++) {
        newv[i] = newv[i%k];
    }
    printf("%s", newv);
    return 0;
}