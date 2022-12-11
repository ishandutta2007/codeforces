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
    cin >> n >> st >> fn;
    fr(i, n)
        cin >> a[i];

    while (true) {
        if (u[st]) {
            cout << -1;
            return 0;
        }
        u[st] = true;
        if (st == fn) {
            cout << kol;
            return 0;
        }
        kol++;
        st = a[st - 1];
    }




    return 0;
}