#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int n, k;

vector <int> a;
int now = 1;

void rec(int l, int r) {
    if (r - l == 1 || now == k) {
        return;
    }
    int mid = (l + r) / 2;
    swap(a[mid - 1], a[mid]);
    now += 2;
    rec(l, mid);
    rec(mid, r);
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    cin >> n >> k;
    if (k % 2 == 0) {
        cout << -1;
        return 0;
    }
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    rec(0, n);
    if (now < k) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}