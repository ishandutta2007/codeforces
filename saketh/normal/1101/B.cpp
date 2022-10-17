#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> str;

    int i = 0;
    while (i < str.size() && str[i] != '[')
        i++;
    while (i < str.size() && str[i] != ':')
        i++;

    int j = str.size() - 1;
    while (j >= 0 && str[j] != ']')
        j--;
    while (j >= 0 && str[j] != ':')
        j--;

    if (i < j) {
        int btw = 0;
        for (int k = i + 1; k < j; k++)
            btw += str[k] == '|';
        cout << btw + 4 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}