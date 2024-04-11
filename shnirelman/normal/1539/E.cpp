#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int LOGN = 20;
const int A = 27;

int n, m;


struct ST {
    vector<vector<int>> st;
    int t;

    ST(vector<int> a, int x) : t(x) {
        st.resize(LOGN, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            st[0][i] = a[i];
        for(int i = 1; i < LOGN; i++)
            for(int j = 0; j + (1 << i) <= n; j++)
                if(t == 1)
                    st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                else
                    st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }


};

int amx[N], bmx[N];
int adp[N], bdp[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
//    int t = 1;
////    cin >> t;
//
//    while(t--)
//        solve();

    cin >> n >> m;
    n++;

    vector<int> x(n), a1(n), b1(n), a2(n), b2(n);
    for(int i = 1; i < n; i++) {
        cin >> x[i] >> a1[i] >> b1[i] >> a2[i] >> b2[i];
    }

    ST sta1(a1, 2), stb1(b1, 1), sta2(a2, 2), stb2(b2, 1);

    for(int i = 0; i < n; i++) {
        if(a1[i] <= x[i] && x[i] <= b1[i]) {
            int res = i + 1;
            for(int k = LOGN - 1; k >= 0; k--)
                if(res + (1 << k) <= n && sta1.st[k][res] <= x[i] && x[i] <= stb1.st[k][res])
                    res += (1 << k);

            amx[i] = res;
        } else {
            amx[i] = -1;
        }

        if(a2[i] <= x[i] && x[i] <= b2[i]) {
            int res = i + 1;
            for(int k = LOGN - 1; k >= 0; k--)
                if(res + (1 << k) <= n && sta2.st[k][res] <= x[i] && x[i] <= stb2.st[k][res])
                    res += (1 << k);

            bmx[i] = res;
        } else {
            bmx[i] = -1;
        }
    }

    for(int i = 0; i < n; i++)
        adp[i] = bdp[i] = -1;

    adp[0] = 0;
    bdp[0] = 0;

    for(int i = 1; i < n; i++) {
        if(a1[i] <= x[i] && x[i] <= b1[i]) {
            if(adp[i - 1] != -1 && bmx[adp[i - 1]] > i)
                adp[i] = adp[i - 1];
            if((adp[i] == -1 || bmx[i - 1] > bmx[adp[i]]) && bdp[i - 1] != -1 && bmx[i - 1] > i)
                adp[i] = i - 1;
        }

        if(a2[i] <= x[i] && x[i] <= b2[i]) {
            if(bdp[i - 1] != -1 && amx[bdp[i - 1]] > i)
                bdp[i] = bdp[i - 1];
            if((bdp[i] == -1 || amx[i - 1] > amx[bdp[i]]) && adp[i - 1] != -1 && amx[i - 1] > i)
                bdp[i] = i - 1;
        }
    }

    if(adp[n - 1] == -1 && bdp[n - 1] == -1) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    int a, b;
    if(adp[n - 1] != -1)
        a = n - 1, b = adp[n - 1];
    else
        a = bdp[n - 1], b = n - 1;

    vector<int> res;
    while(max(a, b) > 0) {
        if(a > b + 1) {
            res.push_back(0);
            a--;
        } else if(a == b + 1) {
            res.push_back(0);
            a = bdp[b];
        } else if(b > a + 1) {
            res.push_back(1);
            b--;
        } else if(b == a + 1) {
            res.push_back(1);
            b = adp[a];
        }
    }

    reverse(res.begin(), res.end());
    for(auto x : res)
        cout << x << ' ';
    cout << endl;
}