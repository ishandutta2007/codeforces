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

int n, m;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    if (n == 1) {
        cout << m << "\n";
        fr(i, m)
            cout << "1 " << i + 1 << "\n";
        return 0;
    }
    if (m == 1) {
        cout << n << "\n";
        fr(i, n)
            cout << i + 1 << " 1\n";
        return 0;
    }

    cout << m + n - 1 << "\n";
    fr(i, m)
        cout << "1 " << i + 1 << "\n";
    fr(i, n - 1)
        cout << i + 2 << " 1\n";


    return 0;
}