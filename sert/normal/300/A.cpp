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
#define fr(i, n) for (int i = 0; i < int(n); i++)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef double ld;
const ll N = 1e6+5;

int b[3][N], a[N];
int len[3], pos, kol, ln, ps = -1;
int c[N], n;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n) {
        c[i] = -1;
        if (a[i] < 0) pos = i;
        if (a[i] > 0) ps = i;
    }

    if (ps == -1) {
        fr(i, n)
            if (a[i] < 0 && kol < 2) {
                b[1][len[1]++] = a[i];
                c[i] = 1;
                kol++;
            }
        b[0][0] = a[pos];
        c[pos] = 0;
        len[0] = 1;
        len[2] = n - len[0] - len[1];
        fr(i, n)
            if (c[i] == -1)
                b[2][ln++] = a[i];
        fr(i, 3) {
            cout << len[i];
            fr(j, len[i])
                cout << " " << b[i][j];
            cout << "\n";
        }
    } else {
        cout << "1 " << a[pos] << "\n";
        cout << "1 " << a[ps] << "\n";
        cout << n - 2;
        fr(i, n)
            if (i != ps && i != pos)
                cout << " " << a[i];
    }





    return 0;
}