#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;
const ll md = (int)1e9 + 7;

int n;
int getK(int r, int n) {
    if (r * 32 <= n) return 12;
    if (r * 16 <= n) return 10;
    if (r * 8 <= n) return 8;
    if (r * 4 <= n) return 6;
    if (r * 2 <= n) return 4;
    if (r <= n) return 2;
    exit(34);
}

int solve[5];
int s0, s1;
int k[5];
int nk[5];
int a[200][10];
int ans = md;

/*int getF(int s, int k, int nk) {
    if (k == nk) return 0;
    if (k < nk) {
        int tm = (1 << (nk / 2 - 1));
        return s * tm - n;
    }
    if (k > nk) {
        int tm = (1 << (nk / 2));
        int ch = n - s * tm;
        int zn = tm - 1;
        return ch / zn + 1;
    }
}*/

bool is_ok() {
    int s[2];
    for (int i = 0; i < 2; i++) {
        s[i] = 0;
        for (int j = 0; j < 5; j++) {
            if (a[i][j] == -1) continue;
            s[i] += nk[j] * 250 - nk[j] * a[i][j];
        }
    }
    //cerr << s[0] << " " << s[1] << "\n";
    return (s[0] > s[1]);
}

bool check(int s, int sum, int k, bool can) {
    int tm = (1 << (k / 2)); /// (1/tm; 2/tm]

    int mn = (k == 12 ? 0 : sum / tm + 1);
    int mx = 2 * sum / tm;

    int d = sum - n;

    if (can) {
        if (s + d < mn || s > mx) return false;
        return true;
    } else {
        return (mn <= s && s <= mx);
    }
}

void go(int sum, int num) {
    bool can;
    if (num == 5) {
        /*if (nk[0] == 2 && nk[1] == 6 && nk[2] == 4 && nk[3] == 6 && nk[4] == 12) {
            can = true;
        } else {
            return;
        }*/

        if (!is_ok()) return;

        for (int i = 0; i < 5; i++) {
            can = false;
            if (a[0][i] != -1) can = true;
            if (nk[i] == 4) {
                can = false;
            }
            if (!check(solve[i], sum, nk[i], can)) {
                //cerr << i << " i\n";
                return;
            }
        }

        /*for (int i = 0; i < 5; i++) {
            cout << nk[i] << " ";
        } cout << "\n";*/
        cout << sum - n;
        exit(0);
    }

    if (num == 5) return;
    for (int i = 2; i <= 12; i += 2) {
        nk[num] = i;
        go(sum, num + 1);
    }
}

int main() {
    init();
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
    for (int j = 0; j < 5; j++) {
        if (a[i][j] != -1)
            solve[j]++;
    }

    for (int i = 0; i < 5; i++) {
        k[i] = getK(solve[i], n);
        if (a[0][i] != -1) {
            s0 += k[i] * 250 - a[0][i] * k[i];
        }
    }

    for (int i = 0; i < 5; i++) {
        if (a[1][i] != -1) {
            s1 += k[i] * 250 - a[1][i] * k[i];
        }
    }

    //cerr << s0 << "\n" << s1 << "\n";

    for (int sum = n; clock() < 1.8 * CLOCKS_PER_SEC; sum++) {
        if (sum > 120 * 32) break;
        go(sum, 0);
        //break;
    }

    cout << -1 << "\n";

    return 0;
}