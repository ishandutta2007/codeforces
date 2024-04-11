#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto c=a; c!=b;) cout << *(c++) << " "; cout << endl)
#define WATCHC(V) TRACE(cout << #V" = "; WATCHR(V.begin(), V.end()))

typedef long long ll;

int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
                43, 47 };
int pows[] = { 4, 9, 25, 49 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    for (int p : pows) {
        cout << p << endl;
        string resp;
        cin >> resp;
        if (resp == "yes") {
            cout << "composite" << endl;
            return 0;
        }
    }

    int qua = 0;

    for (int p : primes) {
        cout << p << endl;
        string resp;
        cin >> resp;
        qua += resp == "yes";
    }

    if (qua >= 2) cout << "composite" << endl;
    else cout << "prime" << endl;

    return 0;
}