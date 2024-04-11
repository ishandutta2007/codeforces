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
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n;
pll P[MAXN];

bool c(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    int a = x1 * (y2 - y3) + x2 * (y3 - y1) +  x3 * (y1 - y2);

    if (a == 0) return true;
    else return false;
}

ld area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
   return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool check(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x, ll y)
{
   ld A = area (x1, y1, x2, y2, x3, y3);
   ld A1 = area (x, y, x2, y2, x3, y3);
   ld A2 = area (x1, y1, x, y, x3, y3);
   ld A3 = area (x1, y1, x2, y2, x, y);
   return (A == A1 + A2 + A3);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> P[i].X >> P[i].Y;
    pll p1 = P[0];
    pll p2 = P[1];
    pll p3 = P[2];
    for (int i = 0; i < n; i++) {
        if (!c(p1.X, p1.Y, p2.X, p2.Y, P[i].X, P[i].Y)) {
            p3 = P[i];
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (P[i] == p1 || P[i] == p2 || P[i] == p3) continue;
        if (check(p1.X, p1.Y, p2.X, p2.Y, p3.X, p3.Y, P[i].X, P[i].Y)) {
            if (!c(p1.X, p1.Y, p2.X, p2.Y, P[i].X, P[i].Y)) {
                p3 = P[i];
                continue;
            }

            if (!c(p1.X, p1.Y, p3.X, p3.Y, P[i].X, P[i].Y)) {
                p2 = P[i];
                continue;
            }

            if (!c(p3.X, p1.Y, p3.X, p2.Y, P[i].X, P[i].Y)) {
                p1 = P[i];
                continue;
            }
        }
    }

    cout << find(P, P + n, p1) - P + 1 << sep << find(P, P + n, p2) - P + 1 << sep << find(P, P + n, p3) - P + 1 << endl;
    return 0;
}