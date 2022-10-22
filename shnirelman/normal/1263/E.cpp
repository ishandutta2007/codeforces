#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 13;
const int INF = 1e9;

int tmn[4 * N], tmx[4 * N], t[4 * N];

void push(int v) {
    int v1 = v * 2 + 1;
    int v2 = v * 2 + 2;

    t[v1] += t[v];
    t[v2] += t[v];

    tmx[v1] += t[v];
    tmx[v2] += t[v];

    tmn[v2] += t[v];
    tmn[v1] += t[v];

    t[v] = 0;
}

void upd(int v) {
    tmx[v] = max(tmx[v * 2 + 1], tmx[v * 2 + 2]);
    tmn[v] = min(tmn[v * 2 + 1], tmn[v * 2 + 2]);
}

void update(int v, int l, int r, int ql, int qr, int x) {
    //cout << v << ' ' << l << ' ' << r << ' ' << t[v] << ' ' << tmx[v] << endl;
    if(l >= qr || r <= ql)
        return;

    if(ql <= l && r <= qr) {
        t[v] += x;
        tmx[v] += x;
        tmn[v] += x;
        return;
    }


    push(v);

    int m = (l + r) / 2;

    update(v * 2 + 1, l, m, ql, qr, x);
    update(v * 2 + 2, m, r, ql, qr, x);

    upd(v);
}

/*pair<int, int> get(int v, int l, int r, int ql, int qr) {
    if(l >= qr || r <= ql)
        return {INF, -INF};

    if(ql <= l && r <= qr)
        return {};
}*/

int main() {
    int n;
    cin >> n;
    
    n += 2;

    string s;
    cin >> s;

    string a(n + 1, ' ');

    int i = 0;

    int cnt = 0;
    int cur = 0;
    for(auto c : s) {
        cur++;
        //cout << c << endl;
        if(c == 'L')
            i -= (i > 0 ? 1 : 0);
        else if(c == 'R')
            i++;
        else {
            if(a[i] == '(') {
                update(0, 0, n + 1, i, n + 1, -1);
                cnt--;
            } else if(a[i] == ')') {
                update(0, 0, n + 1, i, n + 1, 1);
                cnt++;
            }

            a[i] = c;

            if(a[i] == '(') {
                update(0, 0, n + 1, i, n + 1, 1);
                cnt++;
            } else if(a[i] == ')') {
                update(0, 0, n + 1, i, n + 1, -1);
                cnt--;
            }
        }
//        cout << a << endl;
//        cout << tmn[0] << ' ' << tmx[0] << ' ' << t[0] << endl;
        cout << (tmn[0] < 0 || cnt != 0 ? -1 : tmx[0]) << ' ';
    }
}