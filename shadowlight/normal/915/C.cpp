#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <int> cnt(10, 0);

string now = "", a, b;

bool rec(int pos) {
    if (pos == b.size()) {
        return true;
    }
    int k = b[pos] - '0';
    if (cnt[k]) {
        cnt[k]--;
        now += (char) (k + '0');
        if (rec(pos + 1)) {
            return true;
        }
        now.pop_back();
        cnt[k]++;
    }
    bool fl = false;
    for (int i = k - 1; i >= 0; i--) {
        if (cnt[i]) {
            cnt[i]--;
            fl = true;
            now += (char) (i + '0');
            break;
        }
    }
    if (!fl) {
        return false;
    }
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < cnt[i]; j++) {
            now += (char) (i + '0');
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
    cin >> a >> b;
    for (char c : a) {
        cnt[c - '0']++;
    }
    if (a.size() < b.size()) {
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < cnt[i]; j++) {
                cout << i;
            }
        }
        return 0;
    }
    rec(0);
    cout << now;
}