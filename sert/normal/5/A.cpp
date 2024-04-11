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

long long ans, n, kol;
string s;

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    while (getline(cin, s)) {
        if (s[0] == '+') kol++;
        else if (s[0] == '-') kol--;
        else {
            n = s.length();
            for (int i = 0; i < n; i++)
            if (s[i] == ':') {
                ans += (n - i - 1) * kol;
                break;
            }
        }
    }
    cout << ans;

    return 0;
}