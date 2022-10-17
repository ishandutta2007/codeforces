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

void print(set<string> &s) {
    for (string str: s)
        cout << str << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    string A, B;
    int N;

    cin >> A >> B >> N;

    set<string> names;
    names.insert(A);
    names.insert(B);

    print(names);

    for (int i = 0; i < N; i++) {
        string kill, add;
        cin >> kill >> add;

        names.erase(kill);
        names.insert(add);
        print(names);
    }

    return 0;
}