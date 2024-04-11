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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int l1 = a ^ b;
    int l2 = (c | d);
    int l3 = c & b;
    int l4 = a ^ d;
    int t1 = l1 & l2;
    int t2 = (l3 | l4);
    cout << (int) (t1 ^ t2);
}