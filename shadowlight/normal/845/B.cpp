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
    string s;
    cin >> s;
    vector <int> a;
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        int k = s[i] - '0';
        a.push_back(k);
        sum += k;
    }
    for (int i = 0; i < 3; i++) {
        int k = s[i + 3] - '0';
        a.push_back(9 - k);
        sum -= k;
    }
    bool fl = 0;
    if (sum > 0) {
        sum = -sum;
        for (int i = 0; i < 6; i++) {
            a[i] = 9 - a[i];
        }
    }
    sort(a.begin(), a.end());
    int now = 0;
    while (sum < 0) {
        sum += 9 - a[now];
        now++;
    }
    cout << now;
}