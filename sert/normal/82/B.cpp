#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 202;

bitset <N> b[N * N], c;
bool u[N * N][N];
int n, k, len, x;
bool uu[N * N], uuu[N * N];
vector<vector<int> > ans;
vector<int> cur;

int main() {
    init();

    cin >> n;

    if (n == 2) {
        cin >> len;
        cin >> x;
        cout << "1 " << x << "\n";
        cout << len - 1;
        for (int i = 0; i < len - 1; i++) {
            cin >> x;
            cout << " " << x;
        }
        return 0;
    }

    n = (n * (n - 1)) / 2;
    for (int i = 0; i < n; i++) {
        cin >> len;
        for (int j = 0; j < len; j++) {
            cin >> x;
            x--;
            uuu[x] = true;
            u[i][x] = true;
            b[i][x] = 1;
        }
    }

    for (int i = 0; i < N; i++) {
        if (uu[i] || !uuu[i])
            continue;
        for (int j = 0; j < N; j++) c[j] = 1;
        for (int j = 0; j < n; j++)
            if (u[j][i]) {
                c = (c & b[j]);
            }


        cur.clear();
        for (int j = 0; j < N; j++)
            if (c[j] == 1) {
                cur.push_back(j + 1);
                uu[j] = true;
            }
        ans.push_back(cur);
    }

    for (vector<int> q: ans) {
        cout << q.size() << " ";
        for (int y: q)
            cout << y << " ";
        cout << "\n";
    }

    return 0;
}