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

string s;
int n, a[10];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = n + 1;;i++) {
        a[0] = i % 10;
        a[1] = i / 1000;
        a[2] = (i % 1000) / 100;
        a[3] = (i % 100) / 10;
        sort(a, a + 4);
        if (a[0] != a[1] && a[1] != a[2] && a[3] != a[2]) {
            cout << i;
            return 0;
        }
    }

    return 0;
}