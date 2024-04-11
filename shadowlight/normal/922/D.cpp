#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct Data {
    ll s, h;
    int id;
};

bool operator<(Data a, Data b) {
    return a.s * b.h > a.h * b.s;
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
    ll res = 0;
    vector <Data> data(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            if (c == 's') {
                data[i].s++;
            } else {
                data[i].h++;
                res += data[i].s;
            }
        }
    }
    sort(data.begin(), data.end());
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        res += cnt * data[i].h;
        cnt += data[i].s;
    }
    cout << res;
}