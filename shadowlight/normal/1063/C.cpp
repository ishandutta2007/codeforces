#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int qu = 0;

bool query(int x, int y) {
    qu++;
    cout << x << " " << y << endl;
    string s;
    cin >> s;
    return s == "black";
}

int main() {
    srand(time(0));
    int n;
    cin >> n;
    bool st = query(INF, INF / 2);
    int l = 0, r = INF - 1;
    for (int i = 0; i < n - 1; i++) {
        assert(r - l > 1);
        //cout << qu << "\n";
        int mid = (l + r) / 2;
        bool now = query(mid, INF / 2);
        if (now == st) {
            r = mid;
        } else {
            l = mid;
        }
    }
    //cout << l << " " << r << "\n";
    assert(r != l);
    if (r - l > 1) {
        int mid = (l + r) / 2;
        cout << mid << " " << 0 << " " << mid << " " << 1 << endl;
    } else {
        cout << l << " " << INF << " " << r << " " << 0 << endl;
    }
}