#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    string str;
    cin >> str;

    for (int rows = 1; rows <= 5; rows++) {
        for (int cols = 1; cols <= 20; cols++) {
            for (int stars = 0; stars < rows; stars++) {
                if (rows * cols - stars == str.size()) {
                    cout << rows << " " << cols << "\n";
                    int t = 0;
                    for (int r = 0; r < rows; r++) {
                        if (r < stars) cout << '*';
                        else cout << str[t++];
                        for (int c = 1; c < cols; c++)
                            cout << str[t++];
                        cout << "\n";
                    }
                    return 0;
                }
            }
        }
    }

    return 0;
}