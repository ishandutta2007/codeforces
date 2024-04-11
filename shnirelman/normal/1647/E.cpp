#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 40;
const int K = 22;
const int M = 998244353;//1e9 + 7;
const int A = 26;
const ld eps = 1e-8;

mt19937 rnd(45768);

/*
*/



/*
*/


int p[N], a[N], b[N];


int nxt[LOGN][N];
int q[N];

vector<int> pos[N];
int mn[N];
int ind[N];

bool used[N];
int wh[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<int> pst;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        pst.insert(p[i]);
    }

    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        mx = max(mx, a[i]);
    }

    int m = (mx - n + 1) / (n - pst.size());

    for(int i = 0; i < n; i++)
        nxt[0][i] = p[i];

    for(int i = 1; i < LOGN; i++) {
        for(int j = 0; j < n; j++) {
            nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
        }
    }

//    cout << m << endl;

    for(int i = 0; i < n; i++) {
        int v = i;
        for(int k = LOGN - 1; k >= 0; k--) {
            if((1ll << k) & m) {
                v = nxt[k][v];
            }
        }

        q[i] = v;

//        cout << i << ' ' << q[i] << endl;
    }

    for(int i = 0; i < n; i++) {
        mn[i] = INF;
    }

    for(int i = 0; i < n; i++) {
        pos[q[i]].push_back(i);
//        mn[q[i]] = min(mn[q[i]], a[i]);
    }

//    for(int i = 0; i < n; i++)
//        arr[i] = INF;
//cout << "sgf" << endl;
    for(int i = 0; i < n; i++) {
//        cout << i << ' ' << a[i] << ' ' << pos[i].size() << endl;
        if(a[i] < n) {
            wh[a[i]] = i;
            b[pos[i][0]] = a[i];
//            cout << "b " << pos[i][0] << ' ' << a[i] << endl;
            used[a[i]] = true;
//            if(pos[i].size() > 1) {
//                arr[a[i]] = pos[i][1];
//            }
            ind[i] = 1;
        }
    }

//    build(0, 0, n);

//    cout << "arr ";
//    for(int i = 0; i < n; i++)
//        cout << arr[i] << ' ';
//    cout << endl;
    set<int> st;
    for(int i = 0; i < n; i++) {
//        cout << i << endl;

        if(!used[i]) {
            used[i] = true;

            int j = *st.begin();//get(0, 0, n, 0, i);
            st.erase(st.begin());

            b[j] = i;

//            cout << "for b " << j << ' ' << i << endl;

            ind[q[j]]++;
            if(ind[q[j]] < pos[q[j]].size()) {
//                update(0, 0, n, a[q[j]], pos[q[j]][ind[q[j]]]);
                st.insert(pos[q[j]][ind[q[j]]]);
            }
//            else {
//                update(0, 0, n, a[q[j]], INF);
//            }
//            cout << "arr ";
//            for(int i = 0; i < n; i++)
//                cout << arr[i] << ' ';
//            cout << endl;
        } else if(pos[wh[i]].size() > 1) {
            st.insert(pos[wh[i]][ind[wh[i]]]);
        }
    }

    for(int i = 0; i < n; i++)
        cout << b[i] + 1 << ' ';
    cout << endl;
}