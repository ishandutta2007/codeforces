#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(a) a.begin(), a.end()
#define forn(i, n) for (int i = 0; i < n; i++)

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1023;
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
    vector <int> tp(10, 0);
    for (int i = 0; i < n; i++) {
        int x;
        char c;
        cin >> c >> x;
        if (c == '&') {
            //cout << x << "\n";
            for (int j = 0; j < 10; j++) {
                //cout << (int) ((x >> j) & 1) << " ";
                if (!((x >> j) & 1)) {
                    tp[j] = 2;
                }
            }
            //cout << "\n";
        } else if (c == '|') {
            for (int j = 0; j < 10; j++) {
                if ((x >> j) & 1) {
                    tp[j] = 3;
                }
            }
        } else {
            for (int j = 0; j < 10; j++) {
                if ((x >> j) & 1) {
                    tp[j] ^= 1;
                }
            }
        }
    }
    /*for (int i = 0; i < 10; i++) {
        cout << tp[i] << " ";
    }
    cout << "\n";*/
    int and1 = 0, or1 = 0, xor1 = 0;
    for (int i = 0; i < 10; i++) {
        if (!tp[i]) {
            and1 += (1 << i);
        } else if (tp[i] == 1) {
            xor1 += (1 << i);
            and1 += (1 << i);
        } else if (tp[i] == 2) {
            //nothing
        } else {
            and1 += (1 << i);
            or1 += (1 << i);
        }
    }
    cout << 3 << "\n";
    cout << "& " << and1 << "\n";
    cout << "| " << or1 << "\n";
    cout << "^ " << xor1 << "\n";
}