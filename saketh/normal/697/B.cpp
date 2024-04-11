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

    stringstream res;

    string inp;
    cin >> inp;

    int pi = inp.find('.');
    string a = inp.substr(0, pi);
    inp = inp.substr(pi + 1);

    int ei = inp.find('e');
    string d = inp.substr(0, ei);
    int b = atoi(inp.substr(ei + 1).c_str());

    res << a;

    for (int i = 0; i < b; i++) {
        if (i < d.size())
            res << d[i];
        else
            res << 0;
    }

    if (b < d.size() && d != "0") {
        res << ".";
        for (int i = b; i < d.size(); i++)
            res << d[i];
    }

    string result = res.str();

    while (result.size() >= 2 && result[0] == '0' && result[1] != '.')
        result = result.substr(1);

    cout << result << endl;
    return 0;
}