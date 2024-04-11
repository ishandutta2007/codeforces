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

    int months[11] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
    string weeks[7] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };

    string a, b;
    cin >> a >> b;

    int ai, bi;

    for (int i = 0; i < 7; i++) {
        if (weeks[i] == a) ai = i;
        if (weeks[i] == b) bi = i;
    }

    for (int i = 0; i < 11; i++) {
        if ((ai + months[i]) % 7 == bi) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}