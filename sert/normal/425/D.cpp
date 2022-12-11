#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e5 + 3;
const int B = 350;
vector <int> x[N], y[N];
vector <int> xx[N], yy[N];

bool is_in(const vector <int> &v, int x) {
    //for (int i = 0; i < v.size(); i++) cerr << v[i] << " "; cerr << "\n";
    return (*(lower_bound(v.begin(), v.end(), x)) == x);
}

int _x, _y, n, len, d, ans;
int xd[1000], yd[1000];
bool u[100][100];

int solve() {       ///0 1
    int res = 0;    ///3 2
    for (int a0 = 0; a0 < n; a0++)
    for (int a1 = 0; a1 < n; a1++)
    for (int a2 = 0; a2 < n; a2++)
    for (int a3 = 0; a3 < n; a3++) {
        if (yd[a0] == yd[a1] && yd[a3] == yd[a2] && xd[a0] == xd[a3] && xd[a1] == xd[a2] && xd[a0] < xd[a1] && yd[a0] < yd[a3] && xd[a1] - xd[a0] == yd[a3] - yd[a0])
            res++;
    }
    return res;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &_x, &_y);
        //xd[i] = _x;
        //yd[i] = _y;
        //u[_x][_y] = true;
        //y[_y].push_back(_x);
        x[_x].push_back(_y);
    }

    //cout << solve() << "\n";

    for (int i = 0; i < N; i++) {
        sort(x[i].begin(), x[i].end());
        //sort(y[i].begin(), y[i].end());
        x[i].push_back(1000000000);
        //y[i].push_back(1000000000);
    }

    //cerr << "ok\n";

    for (int i = 0; i < N; i++) {
        //cerr << i << "\n";
        //cerr << x[i].size() << "\n";
        if (int(x[i].size()) > B) {
            for (int q: x[i])
                if (q < N)
                    y[q].push_back(i);
            continue;
        }
        len = x[i].size();
        //cerr << len << "\n";
        for (int p1 = 0; p1 < len - 1; p1++)
        for (int p2 = p1 + 1; p2 < len - 1; p2++) {
            //cerr << p1 << " " << p2 << "\n";
            d = x[i][p2] - x[i][p1];
            //cerr << d << "\n";
            if (d <= i && int(x[i - d].size()) > B && is_in(x[i - d], x[i][p1]) && is_in(x[i - d], x[i][p2]))
                ans++;
            if (i + d < N && is_in(x[i + d], x[i][p1]) && is_in(x[i + d], x[i][p2])) {
                ans++;
                /*cerr << "(" << i << "," << x[i][p1] << ") - (" << i + d << "," << x[i][p2] << ") ";
                if (!u[i][x[i][p1]]) cerr << 0;
                if (!u[i][x[i][p2]]) cerr << 1;
                if (!u[i + d][x[i][p1]]) cerr << 2;
                if (!u[i + d][x[i][p2]]) cerr << 3;
                cerr << "\n";*/
            }
        }
    }

    for (int i = 0; i < N; i++)
        y[i].push_back(1000000000);

    for (int i = 0; i < N; i++) {
        len = y[i].size();
        for (int p1 = 0; p1 < len; p1++)
        for (int p2 = p1 + 1; p2 < len; p2++) {
            d = y[i][p2] - y[i][p1];
            if (i + d < N && is_in(y[i + d], y[i][p1]) && is_in(y[i + d], y[i][p2]))
                ans++;
        }
    }

    cout << ans;

    return 0;
}