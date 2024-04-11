#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 512;

ll n, m, k;
ll a[N][N];
ll ans[N];
ll x, y;

void count_ans(int y) {
    ll kol = 0;
    ans[y] = 0;
    for (int i = 0; i < m; i++) {
        if (a[y][i] == 1)
            kol++;
        else {
            ans[y] = max(ans[y], kol);
            kol = 0;
        }
    }
    ans[y] = max(ans[y], kol);
}

void put_ans() {
    ll res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, ans[i]);
    cout << res << "\n";
}

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        count_ans(i);

    while (k --> 0) {
        cin >> y >> x;
        a[y - 1][x - 1] = !a[y - 1][x - 1];
        count_ans(y - 1);
        put_ans();
    }

    
    //return 0;
}