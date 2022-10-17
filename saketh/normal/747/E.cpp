#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

vector<vector<string>> parsed;

string get_token(string &str, int &i) {
    TRACE(cout << "Getting token at " << i << endl;)
    int inx = i;
    while (inx < str.size() && str[inx] != ',') inx++;
    WATCH(inx);
    string res = str.substr(i, inx - i);
    WATCH(res);
    i = inx + 1;
    return res;
}

void go(string &str, int &i, int lvl, int qua) {
    if (!qua) return;
    if (parsed.size() <= lvl) parsed.push_back({});
    while (i < str.size() && qua > 0) {
        string comment = get_token(str, i);
        int below = atoi(get_token(str, i).c_str());
        parsed[lvl].push_back(comment);
        go(str, i, lvl + 1, below);
        qua--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    string rep;
    cin >> rep;

    int i = 0;
    go(rep, i, 0, INT_MAX);

    cout << parsed.size() << "\n";
    for (vector<string> &v : parsed) {
        for (string str : v)
            cout << str << " ";
        cout << "\n";
    }

    return 0;
}