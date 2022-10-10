#include <bits/stdc++.h>

using namespace std;

//Safe lowerbound for 1 second is 10^8 operations

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define isOdd & 1
#define qpow2(exponent) 1 << exponent
/* 2^exponent, because every time shifting bit to the leftBound you are essentially multiplying function by two */
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define max3(a, b, c) max(a, max(b, c))
#define pb push_back
#define f first
#define s second
#define t third
#define mp(a, b) make_pair(a, b)

#define mt(a, b, c) make_tuple(a, b, c)

// Other data types
using ll = long long;
using ld = long double;
using pll = pair<long long, long long>;
using pld = pair<long double, long double>;

int main() {
    io;
    ll n;
    cin >> n;
    vector<ll> a(n - 1);

    f0r(i, n - 1) {
        cin >> a[i];
    }

    ll maxwell = LLONG_MIN, minwell = LLONG_MAX;
    set<ll> excalibur;

    ll TheSkillzrReal = 0;
    f0r(i, n - 1) {
        TheSkillzrReal += a[i];
        if (TheSkillzrReal == 0) {
            cout << -1 << endl;
            return (0);
        }
        excalibur.insert(TheSkillzrReal);
        maxwell = max(maxwell, TheSkillzrReal);
        minwell = min(minwell, TheSkillzrReal);
    }

    if (excalibur.size() < n - 1) {
        cout << -1 << endl;
        return 0;
    }

    // cout << "maxwell: " << maxwell << " minwell: " << minwell << endl;

    f1r(i, 2, n) {
        if (i + maxwell == n && i + minwell == 1) {
            f0r(i2, n - 1 + 1) {
                cout << i << " ";
                if (i2 < n - 1) {
                    i += a[i2];
                }
            }

            cout << endl;
            return (0);
        } 
    }

    ll orz = 1;
    if (orz + maxwell == n && orz + minwell == 2) {
        f0r(i2, n - 1 + 1) {
            cout << orz << " ";
            if (i2 < n - 1) {
                orz += a[i2];
            }
        }

        cout << endl;
        return (0); 
    }

    orz = n;
    if (orz + maxwell == n - 1 && orz + minwell == 1) {
        f0r(i2, n - 1 + 1) {
            cout << orz << " ";
            if (i2 < n - 1) {
                orz += a[i2];
            }
        }

        cout << endl;
        return (0); 
    }

    cout << -1 << endl;

    return 0;//This is implied, but if you have to, 0 = standard for successful execution
}