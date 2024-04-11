#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

void fail() {
    cout << "NO" << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const int LIM = 20000;

    int N;
    cin >> N;

    int loc = 0;
    for (int i = 0; i < N; i++) {
        int dist;
        string dir;

        cin >> dist >> dir;
        if (dir == "South") {
            loc += dist;
            if (loc > LIM) fail();
        } else if (dir == "North") {
            loc -= dist;
            if (loc < 0) fail();
        } else {
            if (loc == 0 || loc == LIM) fail();
        }
    }

    if (loc != 0) fail();
    cout << "YES" << endl;
    return 0;
}