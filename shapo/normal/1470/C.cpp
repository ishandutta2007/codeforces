#include <bits/stdc++.h>

using namespace std;

#define ve vector

typedef long long ll;

struct TestSysGame {
    int
    get_k(int x)
    {
        cout << "? " << x + 1 << endl;
        ll ans;
        cin >> ans;
        return ans;
    }

    void
    found_p(int x)
    {
        cout << "! " << x + 1 << endl;
    }
};

struct Game
{
    Game(int _n, int _k, int _pos) : pos(_pos - 1), n(_n), n_g(0), v(_n, ll(_k)) {}

    ll
    get_k(int x)
    {
        cout << "? " << x + 1 << endl;
        n_g++;
        auto res = v[x];
        cout << res << endl;
        _next();
        return res;
    }

    void
    found_p(int x) const
    {
        cout << "! " << x + 1 << endl;
        cout << "Answer " << pos + 1 << endl;
        cout << "Made " << n_g << " steps" << endl;
    }

    void _next()
    {
        ve<ll> res(n, 0ll);
        for (int i = 0; i < n; ++i) {
            if (i != pos) {
                res[(i + 1) % n] += (v[i] + 1) / 2;
                res[(i + n - 1) % n] += (v[i] / 2);
            } else {
                res[(i + 1) % n] += v[i];
            }
        }
        v.swap(res);
    }

    const int pos, n;
    int n_g;
    ve<ll> v;
};

template<typename T>
void
solve(int n, int k, T& game)
{
    int l = 0, w = 3, v = k;
    for (;;) {
        int a = game.get_k(l);
        int b = game.get_k((l + 1) % n);
        if (a != k) {
            v = a;
            break;
        } else if (b != k) {
            l = (l + 1) % n, v = b;
            break;
        }
        l = (l + w + 1) % n;
        w += 4;
    }
    int dir = (v > k) ? -1 : 1;
    while (v != k) {
        l = (l + dir) % n;
        v = game.get_k(l);
    }
    game.found_p(l);
}

int
main()
{
    cin.sync_with_stdio(false);
#ifdef _LOCAL
    int n, k, pos;
    cin >> n >> k >> pos;
    Game g(n, k, pos);
    solve(n, k, g);
#else
    int n, k;
    cin >> n >> k;
    TestSysGame g;
    solve(n, k, g);
#endif
    return 0;
}