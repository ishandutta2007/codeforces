#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N; ll X;
    cin >> N >> X;

    int sad = 0;
    for (int i = 0; i < N; i++) {
        char type;
        ll val;

        cin >> type >> val;

        if (type == '+') {
            X += val;
        } else {
            if (X < val) sad++;
            else X -= val;
        }
    }

    cout << X << " " << sad << endl;
    return 0;
}