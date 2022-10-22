#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

const int N = 1e5 + 13;

int d[N];

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 2; i < N; i++) {
        if(d[i] == 0) {
            d[i] = i;

            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    d[j] = i;
        }
    }

    vector<int> a(N, 0);

    for(int i = 0; i < n; i++) {
        int b;
        cin >> b;

        a[b]++;
    }

    map<pair<int, int>, vector<int>> m;

    for(int i = N - 1; i > 0; i--)
        if(a[i] > 0) {
            int b1 = i, b = i;
            map<int, int> mp;
            while(d[b1] > 0) {
                mp[d[b1]]++;
                b1 /= d[b1];
            }

            for(auto &p : mp) {
                while(p.s >= k) {
                    for(int j = 0; j < k; j++)
                        b /= p.f;
                    p.s -= k;
                }
            }

            if(b != i) {
                a[b] += a[i];
                a[i] = 0;
            } else {
                for(auto p : mp) {
                    m[p].push_back(i);
                }
            }
        }

    li ans = 0;

    unordered_set<li> sk;
    for(int i = 1; i < N; i++) {
        li p = 1;
        for(int j = 0; j < k; j++)
            p *= i;
        sk.insert(p);

        if(p > 2e10)
            break;
    }

    //cout << m[{3, 1}].size() << endl;

    for(int i = 1; i < N; i++)
        if(a[i] > 0) {
            //cout << i << ' ' << a[i] << endl;
            if(i ==  1) {
                ans += a[i] * 1ll * (a[i] - 1);
                continue;
            }

            int b1 = i;
            map<int, int> mp;
            while(d[b1] > 0) {
                mp[d[b1]]++;
                b1 /= d[b1];
            }

            int mn = mp.begin()->f, mn1 = m[{mn, k - mp.begin()->s}].size();
            for(auto p : mp) {
                int res = m[{p.f, k - p.s}].size();
                if(res < mn1) {
                    mn = p.f;
                    mn1 = res;
                }
            }

            //cout << i << ' ' << mn << ' ' << mn1 << endl;
                /*if(p.s < mn) {
                    mn = p.f;
                    mn1 = p.s;
                }*/

            pair<int, int> p = {mn, k - mp[mn]};
            //cout << m[p].size() << endl;
            for(auto b : m[p])
                if(b != i) {
                    //cout << i << ' ' << b << ' ' << a[i] << ' ' << a[b] << endl;
                    if(sk.count(i * 1ll * b)) {
                        //cout << i << ' ' << b << ' ' << a[i] << ' ' << a[b] << endl;
                        ans += a[i] * 1ll * a[b];
                    }
                }

            if(sk.count(i * 1ll * i)) {
                ans += a[i] * 1ll * (a[i] - 1);
            }
        }

    cout << ans / 2;
}

/*
6 2
1 3 3 8 24 1

*/