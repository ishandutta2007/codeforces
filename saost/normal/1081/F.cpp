#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 1e5 + 5;
int n, k, prek, newk, a[2], b[N];

void Enter() {
    cin >> n >> k;
    newk = prek = k;
}

int ask(int u, int v) {
    cout << "? " << u << ' ' << v << endl;
    prek = newk;
    cin >> newk;
    return (newk + prek + v) & 1;
}

void neven() {
    FOR(i, 1, n) {
        while (a[0] != 1 || a[1] != 0)
            a[ask(i, i)] ^= 1;
        b[i] = (i + k - newk) / 2;
        while (a[0] != 0 || a[1] != 0)
            a[ask(i, i)] ^= 1;
    }
    cout << "! ";
    FOR(i, 1, n) cout << b[i] - b[i - 1];
    cout << endl;
}

void nodd() {
    b[n] = k;
    REP(i, 2, n) {
        while (a[0] != 1 || a[1] != 0)
            a[ask(i - 1, i)] ^= 1;
        b[i] = (i + k - newk) / 2;
        while (a[0] != 0 || a[1] != 0)
            a[ask(i - 1, i)] ^= 1;
    }

    if (n > 1) {
        while (a[0] != 0 || a[1] != 1)
            a[ask(2, 3)] ^= 1;
        b[1] = k - (n + k - newk) / 2;
    }

    cout << "! ";
    FOR(i, 1, n) cout << b[i] - b[i - 1];
    cout << endl;
}

void Process() {
    if (n%2 == 0) neven();
    else nodd();
}

int main()
{
    Enter();
    Process();
}