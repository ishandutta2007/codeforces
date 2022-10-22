//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18 + 13;
const int N = 4e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 19;

mt19937 rnd(time(0));

/*

*/
int cur = 1;
int a[N];

int p[N][LOGN];
//int res[N][LOGN];
li sum[N][LOGN];
int par_lst[N][LOGN];
int mx[N][LOGN];

void add(int par, int w) {
    int v = cur++;
    a[v] = w;

//    cout << "add " << v << ' '<< w << endl;

    p[v][0] = par;

    mx[v][0] = a[v];

    for(int i = 1; i < LOGN; i++) {
        p[v][i] = p[p[v][i - 1]][i - 1];
        mx[v][i] = max(mx[v][i - 1], mx[p[v][i - 1]][i - 1]);
    }

    int u = par;
    for(int i = LOGN - 1; i >= 0; i--) {
        if(mx[u][i] < a[v])
            u = p[u][i];
    }

    if(a[u] < a[v]) {
        sum[v][0] = a[v];
//        for(int i = 0; i < LOGN; i++) {
//            res[v][i] = 1;
//            sum[v][i] = a[v];
//            par_lst[v][i] = -1;
//        }
    } else {
//        res[v][0] = 1;
        sum[v][0] = a[v];
        par_lst[v][0] = u;
        for(int i = 1; i < LOGN; i++) {
            sum[v][i] = sum[v][i - 1] + sum[par_lst[v][i - 1]][i - 1];
            par_lst[v][i] = par_lst[par_lst[v][i - 1]][i - 1];
            if(par_lst[v][i] == -1)
                break;
        }
    }

//    for(int i = 0; i < LOGN; i++) {
//        cout << i << ' ' << sum[v][i] << ' ' << par_lst[v][i] << endl;
//    }
}

int get(int v, li x) {
//    cout << "get " << v << ' ' << x << endl;
    if(x < a[v])
        return 0;

    int res = 0;
    for(int i = LOGN - 1; i >= 0 && v != -1; i--) {
//        cout << "for " << v << ' ' << i << ' ' << x << ' ' << sum[v][i] << endl;
        if(sum[v][i] <= x) {
            res += (1 << i);
            x -= sum[v][i];
            v = par_lst[v][i];
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < LOGN; j++) {
            sum[i][j] = INF;
            par_lst[i][j] = -1;
        }
    }
    sum[0][0] = 0;
    for(int i = 0; i < LOGN; i++) {
        par_lst[0][i] = -1;
    }

    int q;
    cin >> q;

    int lst = 0;
    for(int ind = 0; ind < q; ind++) {
        int t;
        cin >> t;

        if(t == 1) {
            li p, q;
            cin >> p >> q;

            int par = p ^ lst;
            int w = q ^ lst;

            add(par - 1, w);
        } else {
            li p, q;
            cin >> p >> q;

            int r = p ^ lst;
            li x = q ^ lst;

            cout << (lst = get(r - 1, x)) << '\n';
        }
    }
}