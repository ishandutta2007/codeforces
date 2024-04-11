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

    int N, K;
    cin >> N >> K;

    string str;
    cin >> str;

    stringstream sub;
    int bal = 0;
    int tcl = 0;
    for (char c : str) {
        if (c == '(') {
            sub << c;
            bal++;
        } else if (bal > 0) {
            sub << c;
            bal--;
            tcl++;
        }
    }

    // print the first K ( and the last K )
    int pop = 0;
    string res = sub.str();
    for (char c : res) {
        if (c == '(') {
            if (pop++ < K/2) {
                cout << '(';
            }
        } else {
            if (--tcl < K/2) {
                cout << ')';
            }
        }
    }

    cout << endl;
    return 0;
}