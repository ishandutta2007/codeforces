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
bool us, ub, un;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') us = true;
        if (s[i] >= 'A' && s[i] <= 'Z') ub = true;
        if (s[i] >= '0' && s[i] <= '9') un = true;
    }
    if (us && ub && un && s.length() >= 5) cout << "Correct\n"; else cout << "Too weak\n";

    return 0;
}