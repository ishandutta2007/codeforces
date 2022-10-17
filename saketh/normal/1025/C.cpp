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
    int N = str.size();

    stringstream ss;
    ss << str << str;
    str = ss.str();

    int st = 1, mx = 1;
    for (int i = 1; i < str.size(); i++) {
        if (str[i] != str[i-1]) {
            mx = max(mx, ++st);
        } else {
            st = 1;
        }
    }

    cout << min(mx, N) << endl;
    return 0;
}