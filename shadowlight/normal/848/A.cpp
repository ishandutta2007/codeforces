#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e5 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    int k;
    cin >> k;
    if (!k) {
        cout << "a";
        return 0;
    }
    vector <int> a;
    while (k != 0) {
        int x = max((int) sqrt(2 * k), 2);
        k -= x * (x - 1) / 2;
        a.push_back(x);
    }
    assert(a.size() <= 26);
    for (int i = 0; i < (int) a.size(); i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << (char) (i + 'a');
        }
    }
}