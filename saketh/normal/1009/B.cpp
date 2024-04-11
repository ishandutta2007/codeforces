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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    string str;
    cin >> str;

    int ones = 0;
    int ftwo = -1;

    stringstream ss;
    int sz = 0;

    for (char c : str) {
        if (c == '1') {
            ones++;
        } else {
            if (c == '2' && ftwo == -1)
                ftwo = sz;
            ss << c;
            sz++;
        }
    }

    string rest = ss.str();

    if (ftwo == -1) {
        cout << rest;
        for (int i = 0; i < ones; i++)
            cout << '1';
        cout << endl;
    } else {
        cout << rest.substr(0, ftwo);
        for (int i = 0; i < ones; i++)
            cout << '1';
        cout << rest.substr(ftwo) << endl;
    }

    return 0;
}