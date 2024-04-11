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

void fail() {
    cout << "===" << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    string all = "ACGT";
    map<char, int> inx;
    for (int i = 0; i < 4; i++)
        inx[all[i]] = i;

    int N;
    cin >> N;
    
    string gen;
    cin >> gen;

    if (N % 4 != 0) {
        fail();
    }

    vi ct(4);
    for (char c : gen)
        if (c != '?')
            ct[inx[c]]++;

    for (int i = 0; i < 4; i++) {
        if (ct[i] > N/4)
            fail();
    }

    for (char c : gen) {
        if (c != '?') {
            cout << c;
        } else {
            for (int i = 0; i < 4; i++) {
                if (ct[i] < N/4) {
                    cout << all[i];
                    ct[i]++;
                    break;
                }
            }
        }
    }
    cout << endl;

    return 0;
}