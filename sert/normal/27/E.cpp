#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

long long step(long long a, long long st) {
    if (st == 0) return 1;
    return a * step(a, st - 1);
}
typedef long long ll;
const ll inf = 4e18;
const ll p[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
ll n, ans = inf;

vector <int> st;

void go(ll cur, ll lst, ll pr, ll ta) {
    //cerr << pr << " " << ta << "\n";
    if (pr == n) {
        ans = min(ans, ta);
        return;
    }
    if (pr > n || cur > 10 || ta > ans) return;
    for (int i = 1; i <= lst; i++)
        if (ta < inf / step(p[cur], i))
            go(cur + 1, i, pr * (i + 1), ta * step(p[cur], i));
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    go(0, 63, 1, 1);
    cout << ans;
}