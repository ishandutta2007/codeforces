#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 1e6 + 34;

ll n, k, kol, p, t, u1, u2, m;
char ch;
string s, q;
set <ll> a;
set <ll> :: iterator it;
vector <ll> es[N], z[N];
bool u[N];

int main() {
    ///freopen("a.in", "r", stdin);

    cin >> k >> q >> m;
    n = q.length();

    for (int i = 0; i < k; i++)
        s += q;
    for (int i = 0; i < s.length(); i++) {
        es[s[i] - 'a'].push_back(i);
        a.insert(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> p >> ch;
        z[ch - 'a'].push_back(p);
    }

    for (int lt = 0; lt < 26; lt++)
        for (int i = 0; i < z[lt].size(); i++) {
            kol = z[lt][i];
            kol--;
            t = 0;
            for (int j = 0; j < i; j++) {
                if (z[lt][j] <= kol)
                    t++;
                else
                    u[z[lt][j]] = true;
            }
            u1 = kol;
            u2 = kol + t;
            while (u2 > u1) {
                ///cerr << u2 << " " << u1 << "\n";
                u1++;
                if (u[u1])
                    u2++;
            }
            for (int j = 0; j < i; j++)
                u[z[lt][j]] = false;
            ///cerr << es[lt][u2] << "\n";
            z[lt][i] = u2;
            a.erase(es[lt][u2]);
        }

    for (it = a.begin(); it != a.end(); it++)
        printf("%c", s[*it]);

    return 0;
}