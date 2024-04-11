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
    string s;
    cin >> s;
    int n = s.size();
    vector <int> a(n, 0);
    int mink = INF;
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        if (x <= mink) {
            mink = x;
            if (i) {
                a[i - 1] = 1 - a[i - 1];
            }
            a[i] = 1;
        }
    }
    for (int x : a) {
        cout << x << " ";
    }
}