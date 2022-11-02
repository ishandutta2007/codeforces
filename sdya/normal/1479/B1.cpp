#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int maxN = 110000;
const int inf = 1000000;

int t[4 * maxN], v[4 * maxN];
int b[maxN];

void build(int i, int l, int r) {
    if (l == r) {
        t[i] = -inf;
        v[i] = 0;
        return;
    }
    build(2 * i, l, (l + r) / 2);
    build(2 * i + 1, (l + r) / 2 + 1, r);
    t[i] = max(t[2 * i], t[2 * i + 1]);
    v[i] = 0;
}

void push(int i, int l, int r) {
    if (l == r) {
        return;
    }
    long long a = v[i];
    int m = (l + r) / 2;

    t[2 * i] += a;
    t[2 * i + 1] += a;
    v[2 * i] += a;
    v[2 * i + 1] += a;

    v[i] = 0;
}

void update(int i, int l, int r, int cl, int cr, int value) {
    if (l == cl && r == cr) {
        t[i] += value;
        v[i] += value;
        return;
    }
    int m = (l + r) / 2;

    push(i, l, r);
    if (cl > m) {
        update(2 * i + 1, m + 1, r, cl, cr, value);
    } else if (cr <= m) {
        update(2 * i, l, m, cl, cr, value);
    } else {
        update(2 * i, l, m, cl, m, value);
        update(2 * i + 1, m + 1, r, m + 1, cr, value);
    }
    t[i] = max(t[2 * i], t[2 * i + 1]);
}

int get(int i, int l, int r, int cl, int cr) {
    if (cl > cr) {
        return -1000000000;
    }
    if (l == cl && r == cr) {
        return t[i];
    }
    int m = (l + r) / 2;

    push(i, l, r);
    if (cl > m) {
        return get(2 * i + 1, m + 1, r, cl, cr);
    }
    if (cr <= m) {
        return get(2 * i, l, m, cl, cr);
    }

    return max(get(2 * i, l, m, cl, m), get(2 * i + 1, m + 1, r, m + 1, cr));
}

int solve(int n) {
    build(1, 0, n);
    update(1, 0, n, n, n, inf);

    for (int i = 0; i < n; ++i) {
        int add = (i == 0 || b[i - 1] != b[i] ? 1 : 0);
        int curbest = max(get(1, 0, n, 0, b[i] - 1), get(1, 0, n, b[i] + 1, n)) + 1;
        curbest = max(get(1, 0, n, b[i], b[i]), curbest);
        update(1, 0, n, 0, n, add);

        if (i > 0) {
            int v = get(1, 0, n, b[i - 1], b[i - 1]);
            if (v < curbest) {
                update(1, 0, n, b[i - 1], b[i - 1], curbest - v);
            }
        }
        //cerr << get(1, 0, n, 0, 0) << " " << get(1, 0, n, 1, 1) << endl;
    }

    return get(1, 0, n, 0, n);
}

int calc(vector < int >& x) {
    int res = 0;
    for (int i = 0; i < x.size(); ++i) {
        if (i == 0 || x[i] != x[i - 1]) {
            ++res;
        }
    }
    return res;
}

int trivial(int n) {
    int res = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector < int > x, y;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                x.push_back(b[j]);
            } else {
                y.push_back(b[j]);
            }
        }
        res = max(res, calc(x) + calc(y));
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    
    cout << solve(n) << endl;
    //cout << trivial(n) << endl;
    return 0;

    int test = 0;
    while (true) {
        ++test;
        cerr << test << endl;
        int n = rand() % 10 + 5;
        for (int i = 0; i < n; ++i) {
            b[i] = rand() % 5;
        }
        int u = solve(n);
        int v = trivial(n);
        if (u != v) {
            cerr << "BAD" << endl;
            for (int i = 0; i < n; ++i) {
                cout << b[i] + 1 << " ";
            }
            cout << endl;
            cout << solve(n) << " " << u << endl;
            cout << trivial(n) << " " << v << endl;
            exit(0);
        }
    }
   


    return 0;
}