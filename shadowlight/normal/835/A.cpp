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
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int x = v1 * s + 2 * t1, y = v2 * s + 2 * t2;
    if (x == y) {
        cout << "Friendship";
    } else if (x < y) {
        cout << "First";
    } else {
        cout << "Second";
    }
}