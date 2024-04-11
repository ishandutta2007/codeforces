#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

#define y1 yy1
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;

using namespace std;

const ll N = 1e5 + 34;

int n, uk;
string s[N], k, t;
bool a1, a2, w;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> k;
    t = "<3";
    for (int i = 0; i < n; i++) {t += s[i]; t += "<3";}
    uk = 0;
    t += "@"; k += "@";
    for (int i = 0; i < k.length() && uk < t.length(); i++) {if (k[i] == t[uk]) uk++;
        //else if (k[i] >= 'a' && k[i] <= 'z') {cout << "no"; return 0;}
    }
    if (uk == t.length()) printf("yes"); else printf("no");

    return 0;
}