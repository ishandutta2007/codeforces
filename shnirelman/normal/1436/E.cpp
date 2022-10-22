#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 350;

int a[N];
int c[N];
int cnt = 0;
int lst[N];
int t[N];
vector<int> pos[N];

int get(int i) {
    int res = 0;
    for(; i >= 0; i = (i & (i + 1)) - 1)
        res += t[i];
    return res;
}

void upd(int i, int x) {
    for(; i < N; i = (i | (i + 1)))
        t[i] += x;
}

void add(int x) {
    c[x]++;
    if(c[x] == 1) {
        upd(x, 1);
    }
//        cnt++;
}

void del(int x) {
    c[x]--;
    if(c[x] == 0) {
        upd(x, -1);
    }
//        cnt--;
}

bool cmp(pii x, pii y) {
    int b1 = x.f / B;
    int b2 = y.f / B;

    if(b1 != b2)
        return b1 < b2;
    else
        return x.s < y.s;
}

/*
2
1 2
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool is1 = true;
    for(int i = 0; i < n; i++) {
        if(a[i] != 1)
            is1 = false;
    }

    if(is1) {
        cout << 1 << endl;
        return 0;
    }

    for(int i = 0; i < N; i++) {
        lst[i] = -1;
        pos[i].push_back(-1);
    }


    vector<pii> b;
    for(int i = 0; i < n; i++) {
        b.emplace_back(lst[a[i]] + 1, i);
        lst[a[i]] = i;
        pos[a[i]].push_back(i);
    }

    for(int i = 0; i <= n + 1; i++) {
        pos[i].push_back(n);
        b.emplace_back(lst[i] + 1, n);
    }

    sort(b.begin(), b.end(), cmp);

    int l = 0, r = 0;
    map<pii, int> res;
    for(int i = 0; i < b.size(); i++) {
        while(r < b[i].s) {
            add(a[r]);
            r++;
        }

        while(l > b[i].f) {
            l--;
            add(a[l]);
        }

        while(r > b[i].s) {
            r--;
            del(a[r]);
        }

        while(l < b[i].f) {
            del(a[l]);
            l++;
        }

        int lf = 0, rg = n + 3;
        while(rg - lf > 1) {
            int m = (lf + rg) / 2;

            if(get(m) == m)
                lf = m;
            else
                rg = m;
        }

        res[b[i]] = rg;
//        cout << b[i].f << ' ' << b[i].s << ' ' << rg << endl;
//        for(int j = 0; j < 10; j++)
//            cout << t[j] << ' ';
//        cout << endl;
    }


    for(int i = 1; i <= n + 2; i++) {
        bool fl = false;
        for(int j = 0; j < pos[i].size() - 1; j++) {
//            cout << i << ' ' << pos[i][j] << ' ' << pos[i][j + 1] << endl;

            if(res[{pos[i][j] + 1, pos[i][j + 1]}] == i) {
                fl = true;
                break;
            }
        }

        if(!fl) {
            cout << i << endl;
            return 0;
        }
    }

}