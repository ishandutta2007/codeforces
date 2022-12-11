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

const ll N = 1e6 + 34;

string s;
int md = -1, st, fn;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> st;
    cin >> s;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != '.' && s[i - 1] == '.') st = i;
        if (s[i] != 'R' && s[i - 1] == 'R') md = i - 1;
        if (s[i - 1] != '.' && s[i] == '.') fn = i - 1;
    }

    if (md == fn) cout << fn + 1 << " " << fn + 2;
    else if (md == -1) cout << st + 1 << " " << st;
    else cout << st + 1 << " " << md + 1;

    return 0;
}