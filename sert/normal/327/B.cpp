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
const ll N = 1e7+5;

ll n, m;
bool p[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    p[1] = true;
    for (ll i = 2; i <= 10000000; i++)
        if (!p[i])
            for (ll j = i * i; j <= 10000000; j += i)
                p[j] = true;

    for (int i = 2; i <= 10000000; i++)
        if (!p[i]) {
            cout << i << " ";
            n--;
            if (!n)
                break;
        }


    return 0;
}