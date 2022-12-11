#include <bits/stdc++.h>
using namespace std;

#define scanf(a, b) assert(scanf(a, b) != -1)
#define TASKNAME "cactus"
void init() {
#if __gnu_linux__ == 1
    assert(freopen("a.in", "r", stdin));
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;
const int N = (int)5004;
const ll INF = (ll)1e18 + 34;
const ll md = (ll)1e9 + 7;

int n;
char s[N][N];
bool u[N];
pair <int, int> a[N];
int num;
bool isc;

int kek[N * 20];
int len = 0;

inline void check(int b, int c, int d) {
    b = a[b].second;
    c = a[c].second;
    d = a[d].second;
    if (s[d][b] == s[b][c] && s[b][c] == s[c][d]) {
        if (s[d][b] == '0') {
            swap(d, b);
        }
        printf("%d %d %d\n", d + 1, b + 1, c + 1);
        exit(0);
    }
}

int main() {
    init();

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
        gets(s[i]);

    for (int i = 0; i < n; i++) {
        num = 0;
        for (int j = 0; j < n; j++)
            if (s[i][j] == '1')
                num++;
        if (u[num]) isc = true;
        a[i] = {num, i};
        u[num] = true;
    }

    if (!isc) {
        printf("-1\n");
        return 0;
    }

    sort(a, a + n);

    for (int i = 2; i < n; i++) {
        num = (int)log(n / i) + 1;
        for (int j = 0; j < num; j++)
            kek[len++] = i;
    }


    srand(3431);
    int d, st;
    while (clock() < CLOCKS_PER_SEC * 1.2) {
        d = kek[rand() % len];
        st = rand() % (n - d);
        check(st, st + rand() % (d - 1) + 1, st + d);
    }

    cout << "-1 -1 -1";

    return 0;
}