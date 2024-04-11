#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <int> a;

void check() {
    for (int i = 0; i < (int) a.size() - 1; i++) {
        if (abs(a[i] - a[i + 1]) >= 2) {
            cout << "NO\n";
            exit(0);
        }
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
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    check();
    while (a.size()) {
        int maxk = -1, pos = -1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > maxk) {
                pos = i;
                maxk = a[i];
            }
        }
        a.erase(a.begin() + pos);
        check();
    }
    cout << "YES\n";
}