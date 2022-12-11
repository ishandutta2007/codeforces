#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1e6 + 7;

ll n, x, ss, sf;
vector <ll> f, s;

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 0) {
            f.push_back(x);
            sf += x;
        } else {
            s.push_back(-x);
            ss -= x;
        }
    }

    if (sf != ss) {
        if (sf > ss)
            cout << "first";
        else
            cout << "second";
        return 0;
    }

    f.push_back(-34);
    s.push_back(-34);

    for (int i = 0; i < f.size(); i++)
        if (f[i] != s[i]) {
            if (f[i] < s[i])
                cout << "second";
            else
                cout << "first";
            return 0;
        }

    if (x > 0)
        cout << "first";
    else
        cout << "second";

    return 0;
}