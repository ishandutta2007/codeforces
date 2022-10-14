#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n), T(n, -1), dop(n, -1);
    for (int i = 0; i < n; i++) cin >> A[i];
    int min1 = 1;
    int min2 = 1;
    deque<int> gde1chel, gde2chela;
    vector<int> J(n + 11), JJ(n + 11);
    int ANS = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (A[i] == 1) {
            JJ[min1] = i;
            T[i] = min1;
            gde1chel.pb(min1);
            min1++;
            ANS++;
        } else if (A[i] == 2) {
            if (gde1chel.empty()) {
                cout << "-1\n";
                exit(0);
            }
            int h = gde1chel.front();
            gde1chel.pop_front();
            T[i] = h;
            J[h] = i;
            gde2chela.pb(h);
            ANS++;
        } else if (A[i] == 3) {
            if (!gde2chela.empty()) {
                int h = gde2chela.front();
                gde2chela.pop_front();
                T[i] = min1;
                J[min1] = i;
                dop[J[h]] = min1;
                gde2chela.pb(min1);
                min1++;
                ANS += 2;
            } else if (gde1chel.empty()) {
                cout << "-1\n";
                exit(0);
            } else {
                int h = gde1chel.front();
                gde1chel.pop_front();
                T[i] = min1;
                J[min1] = i;
                dop[JJ[h]] = min1;
                gde2chela.pb(min1);
                min1++;
                ANS += 2;
            }
        }
    }
    cout << ANS << '\n';
    for (int i = 0; i < n; i++) {
        if (T[i] != -1) cout << n + 1 - T[i] << ' ' << i + 1 << '\n';
        if (dop[i] != -1) cout << n + 1 - dop[i] << ' ' << i + 1 << '\n';
    }
}