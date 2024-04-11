#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <deque <char> > > a;
vector <vector <string> > b;

int n, m;

int all = 0;

struct Res {
    int x1, y1, x2, y2;
};

vector <Res> res;

void move(int x1, int y1, int x2, int y2) {
    all++;
    res.push_back({x1, y1, x2, y2});
    assert(a[x1][y1].size());
    assert(x1 * m + y1 != x2 * m + y2);
    a[x2][y2].push_front(a[x1][y1].back());
    a[x1][y1].pop_back();
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //assert(a[i][j].size() == b[i][j].size());
            if (!a[i][j].size()) {
                cout << "#";
            }
            for (int pos = 0; pos < (int) a[i][j].size(); pos++) {
                //assert(a[i][j][pos] == b[i][j][pos]);
                cout << a[i][j][pos];
            }
            cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> n >> m;
    a.resize(n, vector <deque <char> > (m));
    b.resize(n, vector <string> (m));
    vector <int> ar(n, 0), br(n, 0), ac(m, 0), bc(m, 0);
    int sum1 = 0;
    vector <vector <int> > need0(n, vector <int> (m, 0)), need1(n, vector <int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;
            assert(s.size());
            for (char c : s) {
                a[i][j].push_back(c);
                ar[i]++;
                ac[j]++;
            }
        }
    }
    vector <int> needrow(n, 0), needcol(m, 0);
    int sum0 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            assert(b[i][j].size());
            for (char c : b[i][j]) {
                if (c == '1') {
                    need1[i][j]++;
                } else {
                    need0[i][j]++;
                }
                br[i]++, bc[j]++;
            }
            needrow[i] += need1[i][j];
            needcol[j] += need0[i][j];
            sum0 += need0[i][j];
            sum1 += need1[i][j];
            assert(need1[i][j] >= 0);
        }
    }
    int r = -1, c = -1;
    for (int i = 0; i < n; i++) {
        if (ar[i] >= br[i]) {
            r = i;
            break;
        }
    }
    for (int i = 0; i < m; i++) {
        if (ac[i] >= bc[i]) {
            c = i;
            break;
        }
    }
    assert(r != -1 && c != -1);
    //cout << r << " " << c << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == r) continue;
            while (a[i][j].size()) {
                move(i, j, r, j);
            }
        }
    }
    for (int j = 0; j < m; j++) {
        if (j == c) continue;
        while (a[r][j].size()) {
            move(r, j, r, c);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == r) continue;
        while (a[i][c].size()) {
            move(i, c, r, c);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != r || j != c) {
                assert(!a[i][j].size());
            }
        }
    }
    for (char t : a[r][c]) {
        if (t == '1') {
            sum1--;
        } else {
            sum0--;
        }
    }
    assert(!sum0 && !sum1);
    //print();
    int li = 0, lj = 0;
    if (li == r) li++;
    if (lj == c) lj++;

    bool fixi = false, fixj = false;
     while (!fixi && a[li][c].size() == needrow[li] - need1[li][c]) {
                li++;
                if (li == r) li++;
                if (li == n) {
                    li--;
                    if (li == r) li--;
                    fixi = true;
                }
            }
            while (!fixj && a[r][lj].size() == needcol[lj] - need0[r][lj]) {
                lj++;
                if (lj == c) lj++;
                if (lj == m) {
                    lj--;
                    if (lj == c) lj--;
                    fixj = true;
                }
            }
    while (a[r][c].size()) {
        if (a[r][c].back() == '1') {
            move(r, c, li, c);
            assert(need1[li][c] >= 0);
            while (!fixi && a[li][c].size() == needrow[li] - need1[li][c]) {
                li++;
                if (li == r) li++;
                if (li == n) {
                    li--;
                    if (li == r) li--;
                    fixi = true;
                }
            }
        } else if (a[r][c].back() == '0') {
            move(r, c, r, lj);
            while (!fixj && a[r][lj].size() == needcol[lj] - need0[r][lj]) {
                lj++;
                if (lj == c) lj++;
                if (lj == m) {
                    lj--;
                    if (lj == c) lj--;
                    fixj = true;
                }
            }
        }
    }
    assert(!a[r][c].size());
    for (int i = 0; i < n; i++) {
        if (i != li && i != r) {
            if (a[i][c].size() != needrow[i] - need1[i][c]) {
                for (int k = i + 1; k < n; k++) {
                    assert(a[k][c].size() < needrow[k] - need1[k][c]);
                }
                cout << i << " " << a[li][c].size() << " " << needrow[li] - need1[li][c] << " " << need1[i][c] << " " << fixi << " " << fixj << " " << li << " " << r << "\n";
                exit(0);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (i != lj && i != c) {
            assert(a[r][i].size() == needcol[i] - need0[r][i]);
        }
    }
    for (int j = 0; j < m; j++) {
        if (j == c) continue;
        string need = b[r][j];
        reverse(need.begin(), need.end());
        for (int pos = 0; pos < (int) need.size(); pos++) {
            if (need[pos] == '0') {
                move(r, lj, r, c);
            } else {
                move(li, c, r, c);
            }
        }
        for (int pos = 0; pos < (int) need.size(); pos++) {
            move(r, c, r, j);
        }
        assert(!a[r][c].size());
    }
    for (int i = 0; i < n; i++) {
        if (i == r) continue;
        string need = b[i][c];
        reverse(need.begin(), need.end());
        for (int pos = 0; pos < (int) need.size(); pos++) {
            if (need[pos] == '0') {
                move(r, lj, r, c);
            } else {
                move(li, c, r, c);
            }
        }
        for (int pos = 0; pos < (int) need.size(); pos++) {
            move(r, c, i, c);
        }
        assert(!a[r][c].size());
    }
    string need = b[r][c];
    reverse(need.begin(), need.end());
    for (int pos = 0; pos < (int) need.size(); pos++) {
        if (need[pos] == '0') {
            move(r, lj, r, c);
        } else {
            move(li, c, r, c);
        }
    }
    assert(a[li][c].size() == needrow[li] - need1[li][c] + b[li][c].size());
    assert(a[r][lj].size() == needcol[lj] - need0[r][lj] + b[r][lj].size());
    for (int i = 0; i < n; i++) {
        if (i == r) continue;
        for (int j = 0; j < m; j++) {
            if (j == c) continue;
            assert(!a[i][j].size());
            string need = b[i][j];
            reverse(need.begin(), need.end());
            for (char e : need) {
                if (e == '0') {
                    move(r, j, i, j);
                } else {
                    move(i, c, i, j);
                }
            }
        }
    }
    //print();
    cout << res.size() << "\n";
    for (auto r : res) {
        cout << r.x1 + 1 << " " << r.y1 + 1 << " " << r.x2 + 1 << " " << r.y2 + 1 << "\n";
    }
}