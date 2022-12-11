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


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e6 + 34;

int bst_ind = 0, bst_val = -INF;

int B = 1500;

ll rnd() {
    ll kek = rand();
    kek = (abs(kek << 16) ^ rand());
    return kek;
}

int nx[N], val[N];
int nest, value;

int main() {
    //init();
    srand(time(NULL));

    int n, st, x, ps;    ;

    cin >> n >> st >> x;

    for (int i = 0; i < N; i++) {
        nx[i] = val[i] = -1;
    }

    for (int i = 0; i < B; i++) {
        ps = (i == 0 ? st : rnd() % n + 1);
        cout << "? " << ps << endl;
        cin >> value >> nest;
        nx[ps] = nest;
        val[ps] = value;
        if (value < x && value > bst_val) {
            bst_val = value;
            bst_ind = ps;
        }
    }

    if (val[st] >= x) {
        cout << "! " << val[st] << endl;
        return 0;
    }

    int v = nx[bst_ind];
    for (int i = 0; i < 1995 - B && v != -1; i++) {
        cout << "? " << v << endl;
        cin >> value >> nest;
        nx[v] = nest;
        val[v] = value;

        if (value >= x) {
            cout << "! " << value << endl;
            return 0;
        }

        v = nx[v];
    }

    cout << "! -1" << endl;
    return 0;
}