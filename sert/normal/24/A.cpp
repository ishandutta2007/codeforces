#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
vector <int> es[N];
vector <int> c[N];
int n, m, v1, v2, v, cs, p, ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v1 >> v2 >> cs;
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
        c[v1].push_back(0);
        c[v2].push_back(cs);
    }

    v = es[0][0];
    p = 0;
    cs = c[0][0];
    while (v != 0) {
        if (es[v][0] == p) {
            v1 = v;
            cs += c[v][1];
            v = es[v][1];
            p = v1;
        } else {
            v1 = v;
            cs += c[v][0];
            v = es[v][0];
            p = v1;
        }
    }

    ans = cs;


    v = es[0][1];
    p = 0;
    cs = c[0][1];
    while (v != 0) {
        if (es[v][0] == p) {
            v1 = v;
            cs += c[v][1];
            v = es[v][1];
            p = v1;
        } else {
            v1 = v;
            cs += c[v][0];
            v = es[v][0];
            p = v1;
        }
    }

    cout << min(ans, cs);
}