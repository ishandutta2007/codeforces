#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

#define fr(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 7;
const ll M = 1e3 + 3;

using namespace std;

vector <ll> es[N];
ll a[N], k[N];
ll n, m, h, t, kol;
string s, s1, s2;
bool u[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;

    if (n == 1){
        cout << "YES";
        return 0;
    }

    fr(i, n) cin >> a[i];

    fr(i, n) k[a[i]]++;

    for(int i = 0; i < 12345; i++)
    if ((n % 2 == 0 && k[i] * 2 > n) || (n % 2 == 1 && k[i] * 2 - 1 > n)){
        cout << "NO";
        return 0;
    }

    cout << "YES";

    return 0;
}