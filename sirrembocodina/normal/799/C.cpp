#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int t1[400100], t2[400100];
pair<int, int> a1[100100], a2[100100];

void build_tree1(int v, int l, int r) {
    if (l >= r - 1) {
        t1[v] = a1[l].sc;
        return;
    }
    int m = (l + r) / 2;
    build_tree1(v * 2, l, m);
    build_tree1(v * 2 + 1, m, r);
    t1[v] = max(t1[v * 2], t1[v * 2 + 1]);
}

void build_tree2(int v, int l, int r) {
    if (l >= r - 1) {
        t2[v] = a2[l].sc;
        return;
    }
    int m = (l + r) / 2;
    build_tree2(v * 2, l, m);
    build_tree2(v * 2 + 1, m, r);
    t2[v] = max(t2[v * 2], t2[v * 2 + 1]);
}

void upd1(int v, int l, int r, int i) {
    if (l >= r - 1) {
        t1[v] = a1[l].sc;
        return;
    }
    int m = (l + r) / 2;
    if (i < m) {
        upd1(v * 2, l, m, i);
    } else {
        upd1(v * 2 + 1, m, r, i);
    }
    t1[v] = max(t1[v * 2], t1[v * 2 + 1]);
}

void upd2(int v, int l, int r, int i) {
    if (l >= r - 1) {
        t2[v] = a2[l].sc;
        return;
    }
    int m = (l + r) / 2;
    if (i < m) {
        upd2(v * 2, l, m, i);
    } else {
        upd2(v * 2 + 1, m, r, i);
    }
    t2[v] = max(t2[v * 2], t2[v * 2 + 1]);
}

const int inf = -1000000000;

int get1(int v, int l, int r, int R) {
    if (R <= l) {
        return inf;
    }
    if (r <= R) {
        return t1[v];
    }
    int m = (l + r) / 2;
    return max(get1(v * 2, l, m, R), get1(v * 2 + 1, m, r, R));
}

int get2(int v, int l, int r, int R) {
    if (R <= l) {
        return inf;
    }
    if (r <= R) {
        return t2[v];
    }
    int m = (l + r) / 2;
    return max(get2(v * 2, l, m, R), get2(v * 2 + 1, m, r, R));
}

int main() {
    ios::sync_with_stdio(false);
    int n, c1, c2;
    cin >> n >> c1 >> c2;
//    n = 3;
    int n1 = 0, n2 = 0;
    forn (i, n) {
        char tmp[10];
        int x, y;
        cin >> x >> y >> tmp;
//        x = rand(), y = rand();
//        tmp[0] = rand() % 2 ? 'C' : 'D';
//        cerr << x << " " << y << " " << tmp[0] << endl;
        if (tmp[0] == 'C') {
            a1[n1++] = mp(y, x);
        } else {
            a2[n2++] = mp(y, x);
        }
    }
    sort(a1, a1 + n1);
    sort(a2, a2 + n2);
    build_tree1(1, 0, n1);
    build_tree2(1, 0, n2);
    int ans = 0;
    
    forn (i, n1) {
        if (a1[i].fs > c1) {
            break;
        }
        int tmp = a1[i].sc;
        a1[i].sc = inf;
        upd1(1, 0, n1, i);
        c1 -= a1[i].fs;
        
        int r1 = lower_bound(a1, a1 + n1, mp(c1 + 1, 0)) - a1;
        int r2 = lower_bound(a2, a2 + n2, mp(c2 + 1, 0)) - a2;
        ans = max(ans, tmp + max(get1(1, 0, n1, r1), get2(1, 0, n2, r2)));
        
        a1[i].sc = tmp;
        upd1(1, 0, n1, i);
        c1 += a1[i].fs;
    }
    
    forn (i, n2) {
        if (a2[i].fs > c2) {
            break;
        }
        int tmp = a2[i].sc;
        a2[i].sc = inf;
        upd2(1, 0, n2, i);
        c2 -= a2[i].fs;
        
        int r1 = lower_bound(a1, a1 + n1, mp(c1 + 1, 0)) - a1;
        int r2 = lower_bound(a2, a2 + n2, mp(c2 + 1, 0)) - a2;
        ans = max(ans, tmp + max(get1(1, 0, n1, r1), get2(1, 0, n2, r2)));
        
        a2[i].sc = tmp;
        upd2(1, 0, n2, i);
        c2 += a2[i].fs;
    }
    
    cout << ans << endl;
    return 0;
}