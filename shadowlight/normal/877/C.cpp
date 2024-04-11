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
    int n;
    cin >> n;
    vector <int> a;
    for (int i = 2; i <= n; i += 2) {
        a.push_back(i);
    }
    for (int i = 1; i <= n; i += 2) {
        a.push_back(i);
    }
    for (int i = 2; i <= n; i += 2) {
        a.push_back(i);
    }
    cout << a.size() << "\n";
    for (int x : a) {
        cout << x << " ";
    }
}