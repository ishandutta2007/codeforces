#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int n;

int get(int pos) {
    if (!pos) pos = n;
    cout << "? " << pos << endl;
    int x;
    cin >> x;
    return x;
}

void ans(int pos) {
    if (!pos) pos = n;
    cout << "! " << pos << endl;
    exit(0);
}

int main() {
    #ifdef MY
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        //cin.tie(0);
        //cout.tie(0);
    #endif // MY
    cin >> n;
    if (n % 4) {
        ans(-1);
    }
    int d = get(1) - get(n / 2 + 1);
    if (!d) {
        ans(1);
    }
    int l = 2, r = n / 2;
    if (d < 0) {
        l = n / 2 + 1, r = n;
    }
    while (r - l > 0) {
        int mid = (l + r) / 2;
        int d = get(mid) - get((mid + n / 2) % n);
        if (!d) {
            ans(mid);
        } else if (d > 0) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    ans(l);
}