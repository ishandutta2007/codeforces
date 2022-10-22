#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll nod(ll l1, ll l2) {
    if (l1 < l2)
        return nod(l2, l1);
    if (l1 % l2 == 0)
        return l2;
    return nod(l2, l1 % l2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    int q;
    cin >> n >> m >> q;
    ll no = nod(n, m);
    ll shn = n / no;
    ll shm = m / no;
    int s1, s2;
    ll e1, e2;
    ll ho1, ho2;
    for (int qq = 0; qq < q; qq++) {
        cin >> s1 >> e1 >> s2 >> e2;
        if (s1 == 1)
            ho1 = (e1 - 1) / shn;
        else
            ho1 = (e1 - 1) / shm;
        if (s2 == 1)
            ho2 = (e2 - 1) / shn;
        else
            ho2 = (e2 - 1) / shm;
        //cout << ho1 << " " << ho2 << '\n';
        if (ho1 == ho2) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}