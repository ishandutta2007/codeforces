#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;
const int N = 2e5 + 34;

int n, m, s, d;
int a[N];

void solve() {
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);

    if (a[0] <= s) {
        printf("IMPOSSIBLE\n");
        return;
    }

    vector <pair<int, int> > v;
    v.push_back(make_pair(0, a[0] - 1));
    for (int i = 1; i < n; i++)
        if (a[i] - a[i - 1] - 2 >= s)
            v.push_back(make_pair(a[i - 1] + 1, a[i] - 1));
    v.push_back(make_pair(a[n - 1] + 1, m));

    for (int i = 1; i < (int)v.size(); i++)
        if (v[i - 1].second + d < v[i].first) {
            printf("IMPOSSIBLE\n");
            return;
        }

    int cur = 0;
    for (int i = 0; i + 1 < (int)v.size(); i++) {
        printf("RUN %d\n", v[i].second - cur);
        cur = v[i].second;
        printf("JUMP %d\n", v[i + 1].first - cur);
        cur = v[i + 1].first;
    }
    if (cur < m)
        printf("RUN %d\n", m - cur);
}

bool solve2() {
    ifstream fi("a.in");
    int x;
    int dp[1000];
    fi >> n >> m >> s >> d;
    for (int i = 0; i <= m; i++)
        dp[i] = -1;
    for (int i = 0; i < n; i++) {
        fi >> x;
        dp[x] = -2;
    }
    fi.close();
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        if (dp[i] == -2)
            continue;
        if (dp[i - 1] >= 0)
            dp[i] = dp[i - 1] + 1;
        if (dp[i] == -1) {
            for (int j = max(0, i - d); j < i && dp[i] == -1; j++)
                if (dp[j] >= s)
                    dp[i] = 0;
        }
    }

    if (dp[m] == -1)
        return false;
    else
        return true;
}

void fail(string s) {
    cerr << s << "\n";
    exit(34);
}

void gentest() {
    ofstream fo("a.in");

    int n = 1 + rand() % 5;
    int m = 5 + rand() % 10;
    int s = 1 + rand() % m;
    int d = 1 + rand() % m;

    int a[100];
    for (int i = 0; i < n; i++)
        a[i] = 1 + rand() % (m - 1);
    sort(a, a + n);
    n = unique(a, a + n) - a;
    random_shuffle(a, a + n);


    fo << n << " " << m << " " << s << " " << d << "\n";
    for (int i = 0; i < n; i++)
        fo << a[i] << " ";
    fo.close();
}

int num;

void check() {

    gentest();

    cerr << "g";

    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    solve();
    cerr << "s";

    string st;
    ifstream fi("a.out");
    fi >> st;
    fi.close();

    cerr << int(solve2());

    if (st == "IMPOSSIBLE") {
        if (solve2())
            fail("didn't find a solution.");
        else {
            //cerr << " OK " << ++num << "\n";
            //++num;
            cerr << "\n";
            return;
        }
    }

    cerr << "h";

    ifstream fi3("a.out");

    int cur = 0;
    int x, lst = -1;
    bool u[1000];
    for (int i = 0; i <= m; i++)
        u[i] = false;
    while (fi3 >> st >> x) {
        if (st == "RUN") {
            for (int i = cur; i <= cur + x; i++)
                u[i] = true;
            cur += x;
            lst = x;
        } else {
            if (lst < s)
                fail("jump after short run");
            if (x > d)
                fail("too long jump.");
            cur += x;
        }
    }
    for (int i = 0; i < n; i++)
        if (u[a[i]])
            fail("running through a border.");
    cerr << " OK " << ++num << "\n";
    fi3.close();
}

int main() {

    solve();
    return 0;

    /*srand(3431);
    //freopen("a.in", "r", stdin);
    //solve();
    while (clock() < 34000)
        check();

    string y;
    cin >> y;
    cout << y;
    return 0;*/
}