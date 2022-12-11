#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
#define ff first
#define ss second
const ll N = 1e6 + 34;


ll n, m, k, p;
string s;
int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &n);
    if (n % 2 == 0)
        cout << "4 " << n - 4;
    else
        cout << "9 " << n - 9;
    return 0;
}