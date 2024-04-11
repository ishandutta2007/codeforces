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

int n, a25, a50, k;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> k;
    if (n >= 0 && k >= 0) {
        cout << "0 " << n + k << " " << n + k << " 0";
    }
    if (n < 0 && k >= 0) {
        cout << n - k << " 0 0 " << k - n;
    }
    if (n < 0 && k < 0) {
        cout << n + k << " 0 0 " << n + k;
    }
    if (n >= 0 && k < 0) {
        cout << "0 " << k - n << " " << n - k << " 0";
    }
    return 0;
}