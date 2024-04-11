#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

void go(int loc, int cur, vector<vector<double>> &books, vector<array<int, 3>> &queries,
        vvi &children, vi &ans) {
    bool old;
    if (loc) {
        switch(queries[loc][0]) {
            case 1:
                {
                    int i = queries[loc][1] - 1;
                    int j = queries[loc][2] - 1;
                    cur += !books[i][j];
                    old = books[i][j];
                    books[i][j] = true;
                }
                break;
            case 2:
                {
                    int i = queries[loc][1] - 1;
                    int j = queries[loc][2] - 1;
                    cur -= books[i][j];
                    old = books[i][j];
                    books[i][j] = false;
                }
                break;
            case 3:
                {
                    int i = queries[loc][1] - 1;
                    for (int j = 0; j < books[i].size(); j++) {
                        cur -= books[i][j];
                        books[i][j] = !books[i][j];
                        cur += books[i][j];
                    }
                }
            case 4:
                break;
        }

        ans[loc] = cur;
    }

    for (int ch : children[loc]) {
        go(ch, cur, books, queries, children, ans);
    }

    if (loc) {
        switch(queries[loc][0]) {
            case 1:
            case 2:
                {
                    int i = queries[loc][1] - 1;
                    int j = queries[loc][2] - 1;
                    cur -= books[i][j];
                    books[i][j] = old;
                    cur += books[i][j];
                }
                break;
            case 3:
                {
                    int i = queries[loc][1] - 1;
                    for (int j = 0; j < books[i].size(); j++) {
                        cur -= books[i][j];
                        books[i][j] = !books[i][j];
                        cur += books[i][j];
                    }
                }
            case 4:
                break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M, Q;
    cin >> N >> M >> Q;

    vvi children(Q + 1);
    vector<array<int, 3>> queries(Q + 1);

    for (int i = 1; i <= Q; i++) {
        cin >> queries[i][0] >> queries[i][1];
        if (queries[i][0] < 3)
            cin >> queries[i][2];

        if (queries[i][0] == 4)
            children[queries[i][1]].push_back(i);
        else
            children[i-1].push_back(i);
    }

    vi ans(Q + 1);
    vector<vector<double>> books(N, vector<double>(M, false));

    go(0, 0, books, queries, children, ans);

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << "\n";

    return 0;
}