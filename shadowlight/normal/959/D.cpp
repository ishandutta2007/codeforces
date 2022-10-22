#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 5e7 + 7;
const double EPS = 1e-8;

vector <int> p, d(MAXN, -1);

vector <int> pnow;
vector <int> used;

bool can(int x) {
    while (x != 1) {
        int k = d[x];
        if (used[k]) {
            return false;
        }
        pnow.push_back(k);
        while (x % p[k] == 0) {
            x /= p[k];
        }
    }
    return true;
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
    for (int i = 2; i < MAXN; i++) {
        if (d[i] == -1) {
            p.push_back(i);
            d[i] = (int) p.size() - 1;
        }
        for (int j = 0; j <= d[i]; j++) {
            if (i * p[j] >= MAXN) break;
            d[i * p[j]] = j;
        }
    }
    used.resize(p.size(), 0);
    int n;
    cin >> n;
    int ost = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pnow.clear();
        //cout << x << " " << can(x) << "\n";
        if (can(x)) {
            for (int a : pnow) {
                used[a] = 1;
            }
            cout << x << " ";
        } else {
            while (!can(x)) {
                pnow.clear();
                x++;
            }
            ost = n - i - 1;
            for (int a : pnow) {
                used[a] = 1;
            }
            cout << x << " ";
            break;
        }
    }
    int now = 0;
    //cout << ost << "\n";
    for (int i = 0; i < ost; i++) {
        while (used[now]) {
            now++;
        }
        used[now] = 1;
        cout << p[now] << " ";
    }
}