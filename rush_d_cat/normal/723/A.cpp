#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;
typedef long long ll;
#define fastio ios::sync_with_stdio(false)
#define INF 1e18
#define max(a, b) a<b?b:a
#define min(a, b) a<b?a:b
#define abs(x) x<0?-x:x
const int MOD = 1e9 + 7;
const int MAXN = 1000 + 10;
const int MAXM = 1000 + 10;
int a[4];
int main()
{
    cin >> a[1] >> a[2] >> a[3];
    sort(a+1, a+4);
    cout << (a[3] - a[1]) << endl;
}