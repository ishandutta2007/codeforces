#include <bits/stdc++.h>
using namespace std;

void init() {
//#if __GLIBCXX__ == 20160609
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    ///freopen(TASKNAME".in", "r", stdin);
    ///freopen(TASKNAME".out", "w", stdout);
#endif
}
#define pb push_back
#define fi first
#define se second

typedef long long ll;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e6 + 34;
const ll md = (ll)1e9 + 7;

bool u[N];
int g;
int c;

int main() {
    init();

    g = 0;
    printf("1");

    int n;
    scanf("%d", &n);
    c = n;
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        u[x] = true;
        g++;

        while (u[c]) {
            g--;
            c--;
        }

        printf(" %d", g + 1);
    }


    return 0;
}