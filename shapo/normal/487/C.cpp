#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool
isPrime(int x)
{
    if (x == 2) {
        return true;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int
getPow(int base, int st, int mod)
{
    int res = 1;
    while (st) {
        if (st & 1) {
            res = 1ll * res * base % mod;
        }
        st /= 2;
        base = 1ll * base * base % mod;
    }
    return res;
}

int
generator(int x)
{
    vector< int > allPrimeFact;
    int curV = x - 1;
    int phi = x - 1;
    for (int i = 2; i * i <= curV; ++i) {
        if (curV % i == 0) {
            allPrimeFact.push_back(i);
            while (curV % i == 0) {
                curV /= i;
            }
        }
    }
    if (curV != 1) {
        allPrimeFact.push_back(curV);
    }
    for (int ch = 2; ch <= x; ++ch) {
        bool ok = true;
        for (auto val : allPrimeFact) {
            ok = getPow(ch, phi / val, x) != 1;
            if (!ok) {
                break;
            }
        }
        if (ok) {
            return ch;
        }
    }
    return -1;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int myGen = generator(n);
    if (n <= 3) {
        cout << "YES\n";
        for (int i = 1; i <= n; ++i) {
            cout << i << '\n';
        }
    } else if (n == 4) {
        cout << "YES\n1\n3\n2\n4\n";
    } else if (!isPrime(n)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector< int > allPows(n - 1, 0);
        //cout << "mGen = " << myGen << '\n';
        for (int i = 0, curV = 1; i < n - 1; ++i) {
            allPows[i] = curV;
            curV = 1ll * curV * myGen % n;
        }
        vector< int > res(n, 0);
        res[n - 1] = n;
        for (int i = 1; i < n - 1; i += 2) {
            res[i] = i;
        }
        for (int i = 0, v = n - 1; i < n - 1; i += 2, v -= 2) {
            res[i] = v % (n - 1);
        }
        for (int i = 0; i < n - 1; ++i) {
            res[i] = allPows[res[i]];
        }
        int curVal = 1;
        for (auto x : res) {
            curVal = 1ll * curVal * x % n;
            cout << x << "\n";//" " << curVal << '\n';
        }
    }
    return 0;
}