#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int F;
    cin >> F;

    string clock;
    cin >> clock;

    int dig[5];
    for (int i = 0; i < 5; i++) {
        if (i == 2) continue;
        dig[i] = clock[i] - '0';
    }

    int lmin = INT_MAX;
    int bmin;

    for (int min = 0; min < 60; min++) {
        int cost = int((min/10) != dig[3])
                 + int((min%10) != dig[4]);

        if (cost < lmin) {
            lmin = cost;
            bmin = min;
        }
    }

    int lo = (F == 12) ? 1 : 0;
    int hi = (F == 12) ? 12 : 23;

    int lhr = INT_MAX;
    int bhr;

    for (int hr = lo; hr <= hi; hr++) {
        int cost = int((hr/10) != dig[0])
                 + int((hr%10) != dig[1]);

        if (cost < lhr) {
            lhr = cost;
            bhr = hr;
        }
    }

    cout << (bhr/10) << (bhr%10) << ":";
    cout << (bmin/10) << (bmin%10) << endl;
    return 0;
}