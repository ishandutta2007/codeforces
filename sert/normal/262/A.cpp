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

int n, k, t, ans, kk;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> k;
    fr(i, n) {
        cin >> t;
        kk = 0;
        while (t > 0) {
            if (t % 10 == 4 || t % 10 == 7) kk++;
            t /= 10;
        }
        if (kk <= k)
            ans++;
    }
    cout << ans;
    return 0;
}