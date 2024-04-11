#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1000;
const double EPS = 1e-8;
const int LOGN = 30;

pair <int, int> zapr(int pos) {
    cout << "? " << pos << endl;
    int x, y;
    cin >> x >> y;
    return {x, y};
}

ll myRand() {
    return (rand() << 15) + rand();
}

int main() {
    srand(time(0));
    int n, start, x;
    cin >> n >> start >> x;
    set <int> used;
    vector <pair <int, int> > ans(n + 1, {-1, -1});
    int now = -1, nxt_pos = start;
    int cntz = 0;
    int cnt = 0;
    while (used.size() < n && cntz < MAXN) {
        int pos = myRand() % (n - used.size()) + 1;
        for (auto it = used.begin(); it != used.end(); it++) {
            if (*it > pos) {
                break;
            } else {
                pos++;
            }
        }
        auto p = zapr(pos);
        ans[pos] = p;
        int val = p.first, nxt = p.second;
        used.insert(pos);
        if (nxt != -1) {
           used.insert(nxt);
        }
        if (val < x && val > now) {
            now = val;
            nxt_pos = nxt;
        }
        cntz++;
    }
    cntz = 0;
    while (now < x && nxt_pos != -1) {
        pair <int, int> p;
        if (ans[nxt_pos].first != -1) {
            p = ans[nxt_pos];
        } else {
            p = zapr(nxt_pos);
        }
        nxt_pos = p.second;
        now = p.first;
        cntz++;
    }
    if (now < x) {
        cout << "! -1" << endl;
    } else {
        cout << "! " << now << endl;
    }
}