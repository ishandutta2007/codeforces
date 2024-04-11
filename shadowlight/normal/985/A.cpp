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
    int n;
    cin >> n;
    int sum1 = 0, sum2 = 0;
    vector <int> a(n / 2);
    for (int i = 0; i < n / 2; i++) {
        cin >> a[i];
        a[i]--;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n / 2; i++) {
        sum1 += abs(a[i] - 2 * i);
        sum2 += abs(a[i] - (2 * i + 1));
    }
    cout << min(sum1, sum2);
}