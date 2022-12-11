#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <queue>

#define mp make_pair
#define pb push_back
#define rand() 0
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef long double ld;
const ll N = 1e5 + 5;

int st, fn;
int q, s, d, n, h, len, ans[5];
int a[N];
pair <int, int> b[N];

bool cmp (pair <int, int> aa, pair <int, int> bb) {
    return aa.ss < bb.ss;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    fr(i, n)
        cin >> a[i];
    int i = 0;
    while (i < n) {
        st = i;
        while (a[i] != 0) {
            i++;
            if (i == n) {
                fr(j, n - st)
                    cout << "pushBack\n";
                return 0;
            }
        }
        fn = i;
        for (int j = st; j < fn; j++)
            b[j] = mp(a[j], j);
        sort(b + st, b + fn);
        for (int j = st; j < fn - 3; j++)
            b[j].ff = 0;
        if (fn - st > 2) b[fn - 3].ff = 1;
        if (fn - st > 1) b[fn - 2].ff = 2;
        if (fn - st > 0) b[fn - 1].ff = 3;
        sort(b + st, b + fn, cmp);
        for (int j = st; j < fn; j++) {
            if (b[j].ff == 0)
                cout << "pushBack\n";
            if (b[j].ff == 1)
                cout << "pushFront\n";
            if (b[j].ff == 2)
                cout << "pushQueue\n";
            if (b[j].ff == 3)
                cout << "pushStack\n";
        }
        len = min(fn - st, 3);
        cout << len;
        if (len > 0) cout << " popStack";
        if (len > 1) cout << " popQueue";
        if (len > 2) cout << " popFront";
        cout << "\n";
        i++;
    }

    return 0;
}