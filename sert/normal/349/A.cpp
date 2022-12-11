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
    cin >> n;
    fr(i, n) {
        cin >> k;
        if (k == 25) a25++;
        if (k == 50) {
            if (a25 == 0) {
                cout << "NO";
                return 0;
            }
            else {
                a25--;
                a50++;
            }
        }
        if (k == 100) {
            if (a25 < 3 && (a50 < 1 || a25 < 1)) {
                cout << "NO";
                return 0;
            }
            if (a50 > 0 && a25 > 0) {
                a50--;
                a25--;
            }
            else a25 -= 3;
        }
    }
    cout << "YES";
    return 0;
}