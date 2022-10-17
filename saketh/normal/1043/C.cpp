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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    string str;
    cin >> str;

    vector<bool> res(str.size(), false);

    bool sort = true;
    for (int i = str.size() - 1; i >= 0; i--) {
        if ((sort) == (str[i] == 'a')) {
            res[i] = true;
            sort = !sort;
        }
    }

    for (bool v : res) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}