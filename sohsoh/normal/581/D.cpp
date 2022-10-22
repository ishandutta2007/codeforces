/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

pll L[3];
char C[3] = {'A', 'B', 'C'};

void solve1() {
    if (L[0].X == L[1].X && L[1].X == L[2].X && L[0].X == L[0].Y + L[1].Y + L[2].Y) {
        cout << L[0].X << endl;
        for (int i = 0; i < L[0].Y; i++) {
            for (int j = 0; j < L[0].X; j++) cout << C[0];
            cout << endl;
        }

        for (int i = 0; i < L[1].Y; i++) {
            for (int j = 0; j < L[0].X; j++) cout << C[1];
            cout << endl;
        }

        for (int i = 0; i < L[2].Y; i++) {
            for (int j = 0; j < L[0].X; j++) cout << C[2];
            cout << endl;
        }
        exit(0);
    }
}

void solve2() {
    if (L[0].X == L[1].X + L[2].X && L[1].Y == L[2].Y && L[0].X == L[0].Y + L[1].Y) {
        cout << L[0].X << endl;
        for (int i = 0; i < L[0].Y; i++) {
            for (int j = 0; j < L[0].X; j++) cout << C[0];
            cout << endl;
        }

        for (int i = 0; i < L[1].Y; i++) {
            for (int j = 0; j < L[0].X; j++) {
                if (j < L[1].X) cout << C[1];
                else cout << C[2];
            }

            cout << endl;
        }
        exit(0);
    }
}

int main() {
    fast_io;
    for (int i = 0; i < 3; i++) cin >> L[i].X >> L[i].Y;

    for (int j = 0; j < 3; j++) {
        swap(L[0], L[j]);
        swap(C[0], C[j]);

        for (int i = 0; i < 8; i++) {
            if (i & 1) swap(L[0].X, L[0].Y);
            if ((i / 2) & 1) swap(L[1].X, L[1].Y);
            if (i / 4) swap(L[2].X, L[2].Y);
            solve1();
            solve2();
            if (i & 1) swap(L[0].X, L[0].Y);
            if ((i / 2) & 1) swap(L[1].X, L[1].Y);
            if ((i / 4) & 1) swap(L[2].X, L[2].Y);
        }


        swap(C[0], C[j]);
        swap(L[0], L[j]);
    }

    cout << -1 << endl;
    return 0;
}