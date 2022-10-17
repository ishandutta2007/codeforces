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

    string inp;
    cin >> inp;

    vector<int> aloc;
    for (int i = 0; i < inp.size(); i++) {
        if (inp[i] == 'a')
            aloc.push_back(i);
    }

    if (aloc.size() == inp.size()) {
        for (int i = 0; i < inp.size(); i++) {
            if (i + 1 == inp.size()) 
                cout << 'z';
            else cout << 'a';
        }
        cout << "\n";
    } else if (aloc.size() == 0) {
        // no a's, just shift all of it
        for (char c : inp)
            cout << char(c - 1);
        cout << "\n";
    } else if (aloc[0] > 0) {
        // there is an a, but not in the first position
        // shift everything before it
        for (int i = 0; i < inp.size(); i++) {
            if (i < aloc[0]) cout << char (inp[i] - 1);
            else cout << char(inp[i]);
        }
        cout << "\n";
    } else {
        // the string starts with an a
        // find the first non-A, and shift from there until the next A
        
        int state = 0;

        for (int i = 0; i < inp.size(); i++) {
            if (state == 0 && inp[i] != 'a') {
                state = 1;
            } else if (state == 1 && inp[i] == 'a') {
                state = 2;
            }

            if (state == 1) cout << char(inp[i] - 1);
            else cout << char(inp[i]);
        }
        cout << "\n";
    }

    return 0;
}