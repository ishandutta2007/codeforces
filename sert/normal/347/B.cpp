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

string s;
ll a[N];
ll n, st, fn, kol;
bool u[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n)
        if (a[i] == i)
            kol++;
    if (kol == n) {
        cout << kol;
        return 0;
    }
    fr(i, n)
        if (a[i] != i)
        if (a[a[i]] == i) {
            cout << kol + 2;
            return 0;
        }
    cout << kol + 1;




    return 0;
}