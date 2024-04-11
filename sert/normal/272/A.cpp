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
const ll N = 103;

ll n, k, sum;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    fr(i, n) {
        cin >> k;
        sum += k;
    }
    int ans = 0;
    for (int i = 1; i < 6; i++) {
        if ((sum + i - 1) % (n + 1) != 0) ans++;
    }
    cout << ans;
    return 0;
}