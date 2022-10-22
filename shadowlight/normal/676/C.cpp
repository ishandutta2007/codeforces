#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    int n, k;
    cin >> n >> k;
    vector <int> a, b;
    a.push_back(-1);
    b.push_back(-1);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'a') {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    a.push_back(n);
    b.push_back(n);
    int maxk = 0;
    for (int i = 1; i < (int) a.size(); i++) {
        int pr = a[i - 1] + 1;
        if (i + k >= a.size()) {
            maxk = max(maxk, n - pr);
            break;
        }
        maxk = max(maxk, a[i + k] - pr);
    }
    for (int i = 1; i < (int) b.size(); i++) {
        int pr = b[i - 1] + 1;
        if (i + k >= b.size()) {
            maxk = max(maxk, n - pr);
            break;
        }
        maxk = max(maxk, b[i + k] - pr);
    }
    cout << maxk;
}