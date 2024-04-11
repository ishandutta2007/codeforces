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

bool adj(array<int, 2> a, array<int, 2> b) {
    return abs(a[0] - b[0]) <= 1
        && abs(a[1] - b[1]) <= 1
        && ((abs(a[0] - b[0]) > 0)
          ||(abs(a[1] - b[1]) > 0));
}

vector<array<int, 2>> arrange(string alpha, vector<array<int, 2>> &locs, int off) {
    vector<array<int, 2>> res(256);
    for (int i = 0; i < 26; i++) {
        array<int, 2> put = locs[(i+off)%26];
        res[alpha[i]] = put;
    }
    return res;
}

bool ok(vector<array<int, 2>> put, string arg) {
    for (int i = 0; i + 1 < arg.size(); i++) {
        if (!adj(put[arg[i]], put[arg[i+1]]))
            return false;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    vector<array<int, 2>> locs;
    for (int i = 0; i < 13; i++)
        locs.push_back({0, i});
    for (int i = 0; i < 13; i++)
        locs.push_back({1, 12-i});

    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int a = 0; a < 27; a++) {
        for (int b = a + 2; b < 27; b++) {
            stringstream testcase;
            testcase << alpha.substr(0, b);
            testcase << alpha[a];
            testcase << alpha.substr(b);
            string inp = testcase.str();

            bool good = false;
            for (int o = 0; o < 26; o++)
                good |= ok(arrange(alpha, locs, o), inp);
            assert(good);
        }
    }

    string inp;
    cin >> inp;

    string inp2;
    for (int i = 0; i < inp.size(); i++) {
        for (int j = i + 1; j < inp.size(); j++) {
            if (inp[i] == inp[j]) {
                inp2 = inp.substr(0, j) + 
                              inp.substr(j+1);
            }
        }
    }

    for (int o = 0; o < 26; o++) {
        auto arr = arrange(inp2, locs, o);
        if (ok(arr, inp)) {
            vector<vector<char>> res(2, vector<char>(13));
            for (char c = 'A'; c <= 'Z'; c++)
                res[arr[c][0]][arr[c][1]] = c;

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 13; j++)
                    cout << res[i][j];
                cout << endl;
            }

            return 0;
        }
    }
        
    cout << "Impossible\n";
    return 0;

    return 0;
}